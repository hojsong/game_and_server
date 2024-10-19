#include "../header/server.hpp"

server::server()
{
    init();
}

server::~server()
{
    // 클라이언트 소켓 해제
    for (size_t i = 0; i < this->clients.size(); ++i)
    {
        // clients[i]의 소멸자가 자동으로 호출됨
    }
    // 랭킹 소멸자 호출
    this->rank.~ranking();
    exit(0);
}

void server::init()
{
    // 소켓 생성
    this->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->server_fd < 0) {
        std::cerr << "소켓 생성 실패" << std::endl;
        return;  // 객체 소멸자를 호출하지 않고 종료
    }

    fcntl(this->server_fd, F_SETFL, O_NONBLOCK);

    std::memset(&this->server_addr, 0, sizeof(this->server_addr));
    // 주소 설정
    this->server_addr.sin_family = AF_INET;
    this->server_addr.sin_port = htons(PORT);
    this->server_addr.sin_addr.s_addr = INADDR_ANY;

    int option = 1;
    if (setsockopt(this->server_fd, SOL_SOCKET, SO_REUSEADDR, (const void *)&option, sizeof(option)) == -1) {
        std::cerr << "setsockopt error" << std::endl;
        close(server_fd);
        return;  // 객체 소멸자를 호출하지 않고 종료
    }
    
    // 바인딩
    if (bind(server_fd, reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(server_addr)) < 0) {
        std::cerr << "바인딩 실패" << std::endl;
        close(server_fd);
        return;  // 객체 소멸자를 호출하지 않고 종료
    }

    // 리슨
    if (listen(server_fd, 5) < 0) {
        std::cerr << "리슨 실패" << std::endl;
        close(server_fd);
        return;  // 객체 소멸자를 호출하지 않고 종료
    }
}

void server::change_events(uintptr_t const & ident, int16_t const & filter, uint16_t const & /*flags*/)
{
#ifdef __APPLE__
    struct kevent temp_event;
    EV_SET(&temp_event, ident, filter, 0, 0, NULL); // flags를 사용하지 않음
    changeList.push_back(temp_event);
#else
    struct pollfd temp_event;
    temp_event.fd = static_cast<int>(ident); // uintptr_t에서 int로 변환
    temp_event.events = filter; // POLLIN, POLLOUT 등을 사용
    changeList.push_back(temp_event);
#endif
}

void server::execute() {
#ifdef __APPLE__
    struct kevent eventList[1024];
    struct kevent *curr_event;

    int kq = kqueue();
    if (kq == -1) {
        std::cout << "kqueue Error!!" << std::endl;
        return;  // 객체 소멸자를 호출하지 않고 종료
    }

    change_events(this->server_fd, EVFILT_READ, EV_ADD | EV_ENABLE);
    
    std::cout << "Server Start!" << std::endl;
    while (true) {
        int event_count = kevent(kq, &changeList[0], changeList.size(), eventList, 1024, 0);
        changeList.clear();

        if (event_count == -1) {
            std::cout << "Event count = -1" << std::endl;
            return;  // 객체 소멸자를 호출하지 않고 종료
        }

        for (int i = 0; i < event_count; ++i) {
            curr_event = &eventList[i];
            if (curr_event->flags & EV_ERROR) {
                std::cout << "EVERROR" << std::endl;
                continue;
            }
            if (curr_event->ident == server_fd) {
                client *one_cl = new client(server_fd, &this->rank, &this->sql);
                change_events(one_cl->get_fd(), EVFILT_READ, EV_ADD | EV_ENABLE);
                change_events(one_cl->get_fd(), EVFILT_WRITE, EV_ADD | EV_DISABLE);
                this->clients.push_back(*one_cl);
            } else {
                size_t x;
                for (x = 0; x < clients.size(); x++) {
                    if (clients[x].get_fd() == curr_event->ident)
                        break;
                }
                if (x == clients.size())
                    continue;

                if (curr_event->filter == EVFILT_READ) {
                    ssize_t len = clients[x].recving();
                    if (len > 0 && clients[x].getstatus() == 1) {
                        change_events(curr_event->ident, EVFILT_READ, EV_DISABLE);
                        change_events(curr_event->ident, EVFILT_WRITE, EV_ENABLE);
                    } else if (len == 0) {
                        std::cout << "Client " << curr_event->ident << " disconnected." << std::endl;
                        clients.erase(clients.begin() + x);
                    } else {
                        continue;
                    }
                } else if (curr_event->filter == EVFILT_WRITE) {
                    clients[x].sendMessage();
                    change_events(curr_event->ident, EVFILT_READ, EV_ENABLE);
                    change_events(curr_event->ident, EVFILT_WRITE, EV_DISABLE);
                    clients[x].request_clear();
                }
            }
        }
        curr_event = NULL;
    }
#else // Linux
    // pollfd 구조체 배열을 사용하여 이벤트를 관리
    std::vector<struct pollfd> pollfds;
    
    // 서버 소켓을 pollfd 배열에 추가 (처음에는 읽기 이벤트만 처리)
    struct pollfd server_pollfd;
    server_pollfd.fd = server_fd;
    server_pollfd.events = POLLIN;
    server_pollfd.revents = 0;
    pollfds.push_back(server_pollfd);

    std::cout << "Server Start!" << std::endl;

    while (true) {
        // poll 호출로 이벤트 감지
        int event_count = poll(pollfds.data(), pollfds.size(), -1);

        if (event_count == -1) {
            std::cerr << "Poll Error!!" << std::endl;
            return;  // 오류 발생 시 종료
        }

        // 감지된 이벤트 처리
        for (size_t i = 0; i < pollfds.size(); ++i) {
            if (pollfds[i].revents & POLLIN) {
                if (pollfds[i].fd == server_fd) {  // 서버 소켓에 새로운 연결이 들어온 경우 (accept)
                    client *new_client = new client(server_fd, &this->rank, &this->sql);

                    // 새 클라이언트의 소켓을 pollfd 배열에 추가
                    struct pollfd client_pollfd;
                    client_pollfd.fd = new_client->get_fd();  // 클라이언트 소켓 fd
                    client_pollfd.events = POLLIN;  // 읽기 이벤트 처리
                    client_pollfd.revents = 0;
                    pollfds.push_back(client_pollfd);

                    this->clients.push_back(*new_client);
                    std::cout << "New client connected: " << new_client->get_fd() << std::endl;
                } else {  // 기존 클라이언트 소켓에서 데이터를 수신한 경우
                    size_t x;
                    for (x = 0; x < clients.size(); x++) {
                        if (clients[x].get_fd() == pollfds[i].fd)
                            break;
                    }
                    if (x == clients.size())
                        continue;

                    ssize_t len = clients[x].recving();  // client 클래스에서 recv 처리
                    if (len > 0 && clients[x].getstatus() == 1) {
                        // 읽기 완료 후 쓰기 이벤트로 전환
                        pollfds[i].events = POLLOUT;
                    } else if (len == 0) {  // 클라이언트가 연결을 종료한 경우
                        std::cout << "Client " << pollfds[i].fd << " disconnected." << std::endl;
                        close(pollfds[i].fd);  // 클라이언트 소켓 닫기
                        clients.erase(clients.begin() + x);  // 클라이언트 목록에서 삭제
                        pollfds.erase(pollfds.begin() + i);  // pollfd 배열에서 소켓 제거
                        i--;  // 배열 크기가 줄어들었으므로 인덱스 조정
                    }
                }
            } else if (pollfds[i].revents & POLLOUT) {  // 쓰기 이벤트 처리
                size_t x;
                for (x = 0; x < clients.size(); x++) {
                    if (clients[x].get_fd() == pollfds[i].fd)
                        break;
                }
                if (x == clients.size())
                    continue;

                clients[x].sendMessage();  // client 클래스에서 send 처리
                pollfds[i].events = POLLIN;  // 다시 읽기 이벤트로 전환
                clients[x].request_clear();  // client의 상태 초기화
            }
        }
    }
#endif
}