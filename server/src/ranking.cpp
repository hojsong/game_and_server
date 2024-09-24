#include "../header/ranking.hpp"

ranking::ranking()
{
    std::ifstream inputFile("ranking/rankig_list.txt"); // 입력 파일 이름
    line = 0;

    if (!inputFile) {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
        return ;
    }

    std::string name;
    int value;

    while (inputFile >> name >> value) {
        this->rank.emplace_back(name, value); // 벡터에 쌍 추가
    }

    inputFile.close(); // 파일 닫기

    // 벡터의 내용을 출력 (확인용)
    for (const auto& pair : this->rank) {
        std::cout << pair.first << " " << pair.second << std::endl;
        line++;
    }
}

ranking::~ranking()
{
    ranking::ranksorting();
    std::string filename = "ranking/rankig_list.txt";
    
    std::ofstream outputFile(filename.c_str()); // 출력 파일 이름

    while (!outputFile) {
        std::cerr << "파일을 열 수 없습니다." << std::endl;
        std::remove(filename.c_str());
        outputFile = std::ofstream(filename.c_str());
    }

    for (const auto& pair : this->rank) {
        outputFile << pair.first << " " << pair.second << "\n"; // 파일에 쌍 저장
    }

    outputFile.close(); // 파일 닫기
}

void ranking::save(std::string name, int score)
{
    if (line < 10 || (line >= 10 && this->rank[line - 1].second < score)){
        this->rank.emplace_back(name, score);
        line++;
    }
}

void    ranking::ranksorting(void)
{
    // int i,j;
    // std::string savename;
    // int         savescore;

    std::sort(rank.begin(), rank.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
        return a.second > b.second; // a의 second가 b의 second보다 크면 true
    });

    // for (i = 1; i < this->line - 1; i++)
    // {
    //     for (j = i; j > 0; j--)
    //     {
    //         if (rank[j - 1].second < rank[j].second)
    //         {
    //             savename = rank[j].first;
    //             savescore = rank[j].second;
    //             rank[j].first = rank[j - 1].first;
    //             rank[j].second = rank[j - 1].second;
    //             rank[j - 1].first = savename;
    //             rank[j - 1].second = savescore;
    //         }
    //         else
    //             break;
    //     }
    // }

    if (this->line > 10)
    {
        rank.erase(rank.begin() + 10, rank.end());
        this->line = 10;
    }
}

std::string ranking::getMessage(void)
{
    std::string message;

    message = "";
    for (const auto& pair : this->rank) {
        message.append(pair.first);
        message.append(" ");
        message.append(std::to_string(pair.second));
        message.append("\n");
    }
    
    return message;
}