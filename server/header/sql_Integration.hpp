#pragma once

#include "inc.hpp"

class sql_Integration
{
    private :
        std::string user;
        std::string password;
        std::string database;
        std::string table;
        int         port;
    public:
        sql_Integration();
        ~sql_Integration();
        void init();
        char **sql_update(std::string name, int score);
}