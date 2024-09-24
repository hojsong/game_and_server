#include "../header/client.hpp"
#include "../header/inc.hpp"

client::client(int server_fd, ranking *rank)
{
    std::cout << "client::client" << std::endl;
    this->addr_len = sizeof(client_addr);
    this->socket_fd = accept(server_fd, reinterpret_cast<struct sockaddr*>(&client_addr), &addr_len);
    if (socket_fd == static_cast<uintptr_t>(-1)) {
        std::cout << "????" << std::endl;   
    }
    this->rank = rank;
    this->request = "";
    this->status = 0;
}

client::~client()
{
    std::cout << "client::~client" << std::endl;
}

uintptr_t     client::get_fd()
{
    std::cout << "client::get_fd()" << std::endl;
    return (this->socket_fd);
}

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
    std::cout << buffer << std::endl;
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
    rank->save(name, score);
    rank->ranksorting();
    message = rank->getMessage();
    send(this->socket_fd, message.c_str(), message.size() , 0);
}