#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "inc.hpp"
#include "ranking.hpp"
#include "sql_Integration.hpp"

class client{
    private :
        uintptr_t                 socket_fd;
        struct sockaddr_in  client_addr{};
        socklen_t           addr_len;
        char                buffer[1024];
        std::string         request;
        int                 status;
        ranking             *rank;
        sql_Integration     *sql;
    public :
        client(int server_fd, ranking *rank, sql_Integration *sql);
        ~client();
        uintptr_t     get_fd();
        ssize_t recving();
        int     getstatus();
        void    sendMessage();
        void    setstatus(int status);
        void    request_clear();
};

#endif