#pragma once

#include "inc.hpp"
#include "ranking.hpp"
#include "client.hpp"
#include "sql_Integration.hpp"

class server
{
    private :
        #ifdef __APPLE__
        uintptr_t               server_fd;
        std::vector<struct kevent> changeList;
        #else
        int                     server_fd;
        std::vector<struct pollfd> changeList;
        #endif
        sql_Integration         sql;
        struct sockaddr_in      server_addr{};
        std::vector<client>     clients;
        ranking                 rank;
    public :
        server();
        ~server();
        void    change_events(uintptr_t const & ident, int16_t const & filter, uint16_t const & flags);
        void    init();
        void    execute();
};
