#include "../header/client.hpp"
#include "../header/inc.hpp"

client::client(int server_fd, ranking *rank, sql_Integration *sql)
{
    std::cout << "Accept" << std::endl;
    this->addr_len = sizeof(client_addr);
    this->socket_fd = accept(server_fd, reinterpret_cast<struct sockaddr*>(&client_addr), &addr_len);
#ifdef __APPLE__
    if (socket_fd == static_cast<uintptr_t>(-1)) {
        std::cout << "Accept Failed" << std::endl;
        client::~client();   
    }
#else
    if (socket_fd == -1) {
        std::cout << "Accept Failed" << std::endl;
        client::~client();   
    }
#endif
    this->rank = rank;
    this->sql = sql;
    this->request = "";
    this->status = 0;
}

client::~client()
{
    // std::cout << "Disconnect" << std::endl;
}

#ifdef __APPLE__
uintptr_t     client::get_fd()
{
    return (this->socket_fd);
}
#else
int     client::get_fd()
{
    return (this->socket_fd);
}
#endif

ssize_t client::recving()
{
    ssize_t len = recv(socket_fd, buffer, sizeof(buffer) - 1, 0);

    if (len > 0)
    {
        buffer[len] = '\0';
        this->request += buffer;
    }
    
    if (this->request.find("\r\n\r\n") != std::string::npos)
    {
        this->status = 1;
    }
    // std::cout << buffer << std::endl;
    return len;
}

int     client::getstatus()
{
    return this->status;
}

void    client::setstatus(int status)
{
    this->status = status;
}

void    client::request_clear()
{
    this->request.clear();
    setstatus(0);
}

void    client::sendMessage()
{
    std::istringstream iss(this->request);
    std::string name, message;
    int score;

    iss >> name >> score;
    
    //file save.
    rank->save(name, score);
    rank->ranksorting();

    // message = rank->getMessage(); // file Message Setting
    message = sql->sql_update(name, score); // sql insert and Query Data Message Setting
    send(this->socket_fd, message.c_str(), message.size() , 0);
}