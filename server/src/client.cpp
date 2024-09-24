#include "../header/client.hpp"
#include "../header/inc.hpp"

client::client(int server_fd, ranking *rank)
{
    this->socket_fd = accept(server_fd, NULL, NULL);
    if (socket_fd == static_cast<uintptr_t>(-1)) {
        this->~client();
    }
    this->rank = rank;
    this->request = "";
    this->status = 0;
}

client::~client()
{
    // close(socket_fd) 
}

uintptr_t     client::get_fd()
{
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
    return len;
}

int     client::getstatus()
{
    return this->status;
}

void    client::request_clear()
{
    this->request.clear();
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
