#include "../header/inc.hpp"
#include "../header/server.hpp"

int main()
{
    server serv;

    serv.execute();
}

// #include <iostream>
// #include <cstring>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <unistd.h>

// constexpr int PORT = 8550;

// int main() {
//     int server_sock, client_sock;
//     struct sockaddr_in server_addr{}, client_addr{};
//     socklen_t addr_len = sizeof(client_addr);
//     char buffer[1024];

//     // 소켓 생성
//     server_sock = socket(AF_INET, SOCK_STREAM, 0);
//     if (server_sock < 0) {
//         std::cerr << "소켓 생성 실패" << std::endl;
//         return 1;
//     }

//     // 주소 설정
//     server_addr.sin_family = AF_INET;
//     server_addr.sin_port = htons(PORT);
//     server_addr.sin_addr.s_addr = INADDR_ANY;

//     // 바인딩
//     if (bind(server_sock, reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(server_addr)) < 0) {
//         std::cerr << "바인딩 실패" << std::endl;
//         close(server_sock);
//         return 1;
//     }

//     // 리슨
//     if (listen(server_sock, 5) < 0) {
//         std::cerr << "리슨 실패" << std::endl;
//         close(server_sock);
//         return 1;
//     }
    
//     std::cout << "서버가 시작되었습니다. 클라이언트를 기다립니다..." << std::endl;
//     while (1)
//     {
//         // 클라이언트 연결 수락
//         client_sock = accept(server_sock, reinterpret_cast<struct sockaddr*>(&client_addr), &addr_len);
//         if (client_sock < 0) {
//             std::cerr << "클라이언트 연결 수락 실패" << std::endl;
//             close(server_sock);
//             return 1;
//         }

//         std::string str;

//         // 데이터 수신
//         int bytes_received = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
//         if (bytes_received > 0) {
//             buffer[bytes_received] = '\0'; // 문자열 종료
//             str = buffer;
//             str += "\n";
//             std::cout << "수신한 메시지: " << str << std::endl;
//             // 수신한 메시지를 클라이언트에 다시 전송
//             send(client_sock, str.c_str(), bytes_received, 0);
//         }
//     }
//     // 소켓 종료
//     close(client_sock);
//     close(server_sock);
//     return 0;
// }
