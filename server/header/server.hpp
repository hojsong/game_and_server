#include "inc.hpp"

class ranking;
class client;

class server
{
    private :
        std::vector<client>  clients;
        ranking              rank;
    public :
        server();
        ~server();
        void    init();
        void    accept();
};