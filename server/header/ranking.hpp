#pragma once

#include "inc.hpp"

class ranking
{
private:
    std::vector<std::pair<std::string, int>> rank;
    int                                      line;
public:
    ranking(); // ranking/ranking_list.txt - read -> stl save
    ~ranking(); // stl rank - save -> ranking/ranking_list.txt
    void        save(std::string name, int score);
    void        ranksorting(void);
    std::string getMessage(void);
};
