#pragma once

#include "inc.hpp"
#include <algorithm>

class sql_Integration
{
    private :
        std::string sql_id;
        std::string sql_password;
        int         sql_port;
        std::string sql_name;
        std::string databasename;
        std::string tablename;
        PGconn *conn;
    public:
        sql_Integration();
        ~sql_Integration();
        void init();
        std::string sql_update(std::string name, int score);
};