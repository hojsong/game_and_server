#include "../header/server.hpp"

server::server()
{
    init();
}

server::~server()
{
    for (const auto& dest : this->clients)
    {
        dest.~client();
    }
    this->rank.~ranking();
}

void    server::init()
{
    // 소켓 생성
    this->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->server_fd < 0) {
        std::cerr << "소켓 생성 실패" << std::endl;
        server::~server();
    }

    // 주소 설정
    this->server_addr.sin_family = AF_INET;
    this->server_addr.sin_port = htons(PORT);
    this->server_addr.sin_addr.s_addr = INADDR_ANY;

        // 바인딩
    if (bind(server_fd, reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(server_addr)) < 0) {
        std::cerr << "바인딩 실패" << std::endl;
        close(server_fd);
        server::~server();
    }

    // 리슨
    if (listen(server_fd, 1024) < 0) {
        std::cerr << "리슨 실패" << std::endl;
        close(server_fd);
        server::~server();
    }


}

void server::change_events(uintptr_t const & ident, int16_t const & filter, uint16_t const & flags)
{
	struct kevent temp_event;

	EV_SET(&temp_event, ident, filter, flags, 0, 0, NULL);
	changeList.push_back(temp_event);
}

void    server::execute()
{
    struct kevent           eventList[1024];
    struct kevent           *curr_event;

    int kq = kqueue();
	if (kq == -1) {
		std::cout << "kqueue Error!!" << std::endl;
        server::~server();
        return ;
	}

    // change_events(this->server_fd, EVFILT_READ, EV_ADD | EV_ENABLE);
    
    std::cout << "Server Start!" << std::endl;
    while(true) {
        int event_count = kevent(kq, &changeList[0], changeList.size(), eventList, 1024, 0);

        changeList.clear();
        if (event_count == -1) {
            server::~server();
        }
        for (int i = 0; i < event_count; ++i) { // 이벤트 개수만큼 루프 순회
            curr_event = &eventList[i];
            if (curr_event->flags & EV_ERROR) { // 에러 발생 시
                continue;
            }
            if (curr_event->ident == server_fd) { // 서버 소켓일 경우, 서버 인덱스 값
                client  one_cl(server_fd, &this->rank);
                this->clients.push_back(one_cl);
            }
            else {
                size_t x;
                for(x = 0; x < clients.size(); x++)
                {
                    if(clients[x].get_fd() == curr_event->ident)
                        break;
                }
                if (x == clients.size())
                    continue;
                if (curr_event->filter == EVFILT_READ) {
                    ssize_t len = clients[x].recving();
                    if (len == 0) { // 클라이언트와의 연결 종료(읽을 데이터가 없을 경우 클라이언트에게서는 0이 아닌 -1 값을 받아옴. 연결이 끊겼을 때(close)만 0 출력됨
                        std::cout << "Client " << curr_event->ident << " disconnected." << std::endl;
                        clients[x].~client();
                        clients.erase(clients.begin() + i);
                    }
                    else {
                        continue ; // 추후 다시 접근
                    }
                    if (clients[x].getstatus() == 1)
                    {
                        change_events(curr_event->ident, EVFILT_READ, EV_DISABLE); // 클라이언트 READ 이벤트 비활성화
                        change_events(curr_event->ident, EVFILT_WRITE, EV_ENABLE); // 클라이언트 소켓 WRITE 이벤트 활성화
                    }
                }
                else if (curr_event->filter == EVFILT_WRITE) { // 클라이언트 소켓이고, WRITE 이벤트가 생겼을 경우
                    clients[x].sendMessage();
                    change_events(curr_event->ident, EVFILT_READ, EV_ENABLE); // 클라이언트 READ 이벤트 활성화
                    change_events(curr_event->ident, EVFILT_WRITE, EV_DISABLE); // 클아이언트 WRITE 이벤트 비활성화
                    clients[x].request_clear();
                    std::cout << "response ok" << std::endl;
                }
            }
        }
        curr_event = NULL;
    }
}