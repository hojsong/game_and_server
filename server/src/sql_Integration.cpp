#include "../header/sql_Integration.hpp"

sql_Integration::sql_Integration(){
    std::ifstream configFile("config/config.con"); // 파일 이름에 맞게 수정하세요.
    
    if (!configFile.is_open()) {
        std::cerr << "파일을 열 수 없습니다!" << std::endl;
        exit(1);
    }

    std::string line;
    
    // 파일의 각 줄을 읽어와서 변수에 저장
    while (std::getline(configFile, line)) {
        std::istringstream iss(line);
        std::string key;
        std::string value;

        // '='로 키와 값을 분리
        if (std::getline(iss, key, '=') && std::getline(iss, value)) {
            // 공백 제거
            key.erase(remove(key.begin(), key.end(), ' '), key.end());
            value.erase(remove(value.begin(), value.end(), ' '), value.end());

            // 따옴표 제거
            if (value.front() == '"' && value.back() == '"') {
                value = value.substr(1, value.size() - 2);
            }

            // 변수에 값 할당
            if (key == "sql_id") {
                sql_id = value;
            } else if (key == "sql_password") {
                sql_password = value;
            } else if (key == "sql_port") {
                sql_port = std::stoi(value);
            } else if (key == "sql_name") {
                sql_name = value;
            } else if (key == "databasename") {
                databasename = value;
            } else if (key == "tablename") {
                tablename = value;
            }
        }
    }

    // 파일 닫기
    configFile.close();

    // 결과 출력
    std::cout << "SQL ID: " << sql_id << std::endl;
    std::cout << "SQL Password: " << sql_password << std::endl;
    std::cout << "SQL Port: " << sql_port << std::endl;
    std::cout << "SQL Name: " << sql_name << std::endl;
    std::cout << "Database Name: " << databasename << std::endl;
    std::cout << "Table Name: " << tablename << std::endl;
    init();
}

sql_Integration::~sql_Integration()
{
    std::cout << "sql_Integration delete" << std::endl;
    PQfinish(this->conn);
}

void sql_Integration::init()
{
     std::string conninfo = "host=" + sql_name + " "
                       "port=" + std::to_string(sql_port) + " "
                       "dbname=" + databasename + " "
                       "user=" + sql_id + " "
                       "password=" + sql_password;

    // PostgreSQL에 연결
    this->conn = PQconnectdb(conninfo.c_str());
    if (PQstatus(conn) != CONNECTION_OK) {
        std::cerr << "연결 실패: " << PQerrorMessage(conn) << std::endl;
        PQfinish(conn);
        exit (1);
    }
}

std::string sql_Integration::sql_update(std::string name, int score)
{
    // init();
    std::string insertQuery = "INSERT INTO " + this->tablename + \
                                " (name, score) VALUES ('"+name+"',"+std::to_string(score)+")";
    PGresult *res = PQexec(this->conn, insertQuery.c_str());
    
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        std::cerr << "데이터 삽입 실패: " << PQerrorMessage(conn) << std::endl;
        PQclear(res);
        return NULL;
    }
    std::cout << "데이터가 성공적으로 삽입되었습니다." << std::endl;

    // 결과 해제 및 연결 종료
    PQclear(res);
    // PQfinish(this->conn);

    // init();
    std::string selectQuery = "SELECT name, score FROM " + this->tablename + " ORDER BY score DESC";
    PGresult *res2 = PQexec(conn, selectQuery.c_str());

    if (PQresultStatus(res2) != PGRES_TUPLES_OK) {
        std::cerr << "쿼리 실행 실패: " << PQerrorMessage(conn) << std::endl;
        PQclear(res2);
        return NULL;
    }

    std::cout << "데이터 받기 성공" << std::endl;
    // 결과 출력
    int rows = PQntuples(res2);
    std::string result = "";

    std::cout << "1rows : " << rows << std::endl;
    for (int i = 0; i < rows && i < 10; i++) {
        result += PQgetvalue(res2, i, 0);
        result += " ";
        result += PQgetvalue(res2, i, 1);
        result += "\n";
    }
    std::cout << "2" << std::endl;

    PQclear(res2);
    // PQfinish(this->conn);
    std::cout << result << std::endl;
    return result;
}
