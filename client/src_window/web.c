#include "../header/client.h"


void socket_create(t_game *game) {
    FILE *file;
    char url[100];
    int fort;
    struct sockaddr_in addr;

    // Winsock 초기화
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed: %d\n", WSAGetLastError());
        return;
    }

    fort = 0;
    file = fopen("conf/default.con", "r");
    if (file == NULL) {
        perror("Failed to open config file");
        WSACleanup(); // 초기화 정리
        return;
    }
    fscanf(file, "%s %d\n", url, &fort);
    fclose(file);

    printf("Connecting to %s on port %d\n", url, fort);
    game->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (game->sockfd == INVALID_SOCKET) {
        printf("Socket creation failed: %d\n", WSAGetLastError());
        game->sockfd = -1;
        WSACleanup(); // 초기화 정리
        return;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(fort);
    addr.sin_addr.s_addr = inet_addr(url);

    if (connect(game->sockfd, (struct sockaddr *)&addr, sizeof(addr)) == SOCKET_ERROR) {
        printf("Connection failed: %d\n", WSAGetLastError());
        closesocket(game->sockfd);
        game->sockfd = -1;
        WSACleanup(); // 초기화 정리
    }
}

char** web_ranking_Load(char *name, int score, t_game *game) {
    char **result;
    char *message;
    int count = 0;

    result = malloc(sizeof(char *) * (MAX_LINES + 1));
    message = malloc(MAX_STRING_LENGTH + 100);
    snprintf(message, MAX_STRING_LENGTH + 100, "%s %d\r\n\r\n", name, score);

    // 소켓을 통해 메시지를 서버에 전송
    send(game->sockfd, message, strlen(message), 0);
    free(message);

    char buffer[1024];
    int bytes_received = recv(game->sockfd, buffer, sizeof(buffer) - 1, 0);

    if (bytes_received > 0) {
        buffer[bytes_received] = '\0'; // 문자열 종료
        // 서버로부터 받은 응답을 출력 (디버깅 용도)
        // printf("서버로부터의 응답: %s\n", buffer);
    }

    // 개행 문자('\n')를 기준으로 문자열 나누기
    char *token = strtok(buffer, "\n");
    while (token != NULL && count < MAX_LINES) {
        result[count] = strdup(token); // 각 줄을 배열에 저장
        count++;
        token = strtok(NULL, "\n"); // 다음 줄로 이동
    }
    result[count] = NULL;

    return result; // 결과를 반환
}

void cleanup_socket(t_game *game) {
    // 소켓 종료
    if (game->sockfd != -1) {
        closesocket(game->sockfd);
        game->sockfd = -1;
    }
    WSACleanup(); // Winsock 초기화 정리
}