#include "../header/client.h"

void    socket_create(t_game *game)
{
    FILE    *file;
    char    url[100];
    int     fort;
    struct sockaddr_in  addr;

    fort = 0;
    file = fopen("conf/default.con", "r");
    fscanf(file, "%s %d\n", url, &fort);
    fclose(file);
    
    printf("%s %d\n", url, fort);
    game->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (game->sockfd < 0)
    {
        game->sockfd = -1;
        return ;
    }
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(fort);
    addr.sin_addr.s_addr = inet_addr(url);
    if (connect(game->sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        close(game->sockfd);
        game->sockfd = -1;
    }
}

char**  web_ranking_Load(char *name, int score, t_game *game)
{
    char    **result;
    char    *message;
    int     count = 0;

    result = malloc(sizeof(char *) * (MAX_LINES + 1));
    message = malloc(MAX_STRING_LENGTH + 100);
    snprintf(message, MAX_STRING_LENGTH + 100, "%s %d \r\n\r\n", name, score);

    send(game->sockfd, message, strlen(message), 0);
    
    free(message);

    char buffer[1024];
    
    int bytes_received = recv(game->sockfd, buffer, sizeof(buffer) - 1, 0);

    if (bytes_received > 0) {
        buffer[bytes_received] = '\0'; // 문자열 종료
        // printf("서버로부터의 응답: %s\n", buffer);
    }

    // 개행 문자('\n')를 기준으로 문자열 나누기
    char *token = strtok(message, "\n");
    while (token != NULL && count < MAX_LINES) {
        result[count] = strdup(token); // 각 줄을 배열에 저장
        count++;
        token = strtok(NULL, "\n"); // 다음 줄로 이동
    }
    result[count] = NULL;
    // int i;
    // for (i = 0; i < count; i++) {
    //     printf("라인 %d: %s\n", i + 1, result[i]);
    // }
    // result[i] = NULL;
    return result;
}