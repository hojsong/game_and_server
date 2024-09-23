#pragma once

#include "inc.hpp"

class ranking;

class client{
    private :
        int         socket_fd;
        pthread_t   cl_thread;
        ranking     *rank;
    public :
        client(int server_fd, ranking *rank);
        ~client();
        void    thread_create_exe_distroy();
};