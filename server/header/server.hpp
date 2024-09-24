#pragma once

#include "inc.hpp"
#include "client.hpp"
#include "ranking.hpp"

class client;
class ranking;

class server
{
    private :
        uintptr_t               server_fd;
        struct sockaddr_in      server_addr{};
        std::vector<client>     clients;
        std::vector<struct kevent> changeList;
        ranking                 rank;
    public :
        server();
        ~server();
        void    change_events(uintptr_t const & ident, int16_t const & filter, uint16_t const & flags);
        void    init();
        void    execute();
};