#include "../header/client.h"

// 비교 함수
int compare(const void *a, const void *b) {
    Entry *entryA = (Entry *)a;
    Entry *entryB = (Entry *)b;
    return entryB->score - entryA->score; // 내림차순 정렬
}

// 데이터 읽기 함수
int read_data(const char *file_path, Entry *entries) {
    FILE *file = fopen(file_path, "r");
    if (!file) {
        perror("파일을 열 수 없습니다");
        return 0;
    }

    int count = 0;
    while (fgets(entries[count].name, sizeof(entries[count].name), file) && count < MAX_LINES) {
        // 각 줄에서 이름과 점수를 읽어오기
        if (fscanf(file, "%d", &entries[count].score) != 1) {
            break;
        }
        count++;
    }

    fclose(file);
    return count;
}

// 데이터 저장 함수
void write_data(const char *file_path, Entry *entries, int count) {
    FILE *file = fopen(file_path, "w");
    if (!file) {
        perror("파일을 열 수 없습니다");
        return;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d\n", entries[i].name, entries[i].score);
    }
    fclose(file);
}

char** add_and_sort(const char *file_path, const char *name, int score) {
    Entry entries[MAX_LINES];
    int count = read_data(file_path, entries);
    char **result = malloc((MAX_LINES + 1) * sizeof(char*)); // 결과 저장을 위한 메모리 할당

    printf("count : %d\n", count);
    if (count < MAX_LINES || score > entries[MAX_LINES - 1].score) {
        // 새로운 데이터 추가
        if (count < MAX_LINES) {
            strcpy(entries[count].name, name);
            entries[count].score = score;
            count++;
        } else {
            if (score > entries[MAX_LINES - 1].score) {
                strcpy(entries[MAX_LINES - 1].name, name);
                entries[MAX_LINES - 1].score = score;
            } else {
                printf("입력된 점수가 현재 목록의 모든 점수보다 낮습니다.\n");
                free(result); // 메모리 해제
                return NULL; // NULL 반환
            }
        }
        
        qsort(entries, count, sizeof(Entry), compare);
        write_data(file_path, entries, count > MAX_LINES ? MAX_LINES : count);

        // 결과 문자열 생성
        for (int i = 0; i < (count > MAX_LINES ? MAX_LINES : count); i++) {
            result[i] = malloc(MAX_STRING_LENGTH + 20); // 각 결과 문자열을 위한 메모리 할당
            snprintf(result[i], MAX_STRING_LENGTH + 20, "%s %d", entries[i].name, entries[i].score);
        }
        result[count > MAX_LINES ? MAX_LINES : count] = NULL; // 마지막에 NULL 추가
    } else {
        printf("입력된 점수가 현재 목록의 모든 점수보다 낮습니다.\n");
        free(result); // 메모리 해제
        return NULL; // NULL 반환
    }

    return result; // 결과 반환
}

// // 새로운 데이터 추가 및 정렬 함수
// void add_and_sort(const char *file_path, const char *name, int score)
// {
//     Entry entries[MAX_LINES];
//     int count = read_data(file_path, entries);

//     if (count < MAX_LINES || score > entries[MAX_LINES - 1].score) {
//         // 새로운 데이터 추가
//         if (count < MAX_LINES) {
//             strcpy(entries[count].name, name);
//             entries[count].score = score;
//             count++;
//         } else {
//             if (score > entries[MAX_LINES - 1].score) {
//                 strcpy(entries[MAX_LINES - 1].name, name);
//                 entries[MAX_LINES - 1].score = score;
//             } else {
//                 printf("입력된 점수가 현재 목록의 모든 점수보다 낮습니다.\n");
//                 return;
//             }
//         }
//         qsort(entries, count, sizeof(Entry), compare);
//         write_data(file_path, entries, count > MAX_LINES ? MAX_LINES : count);
//     } else {
//         printf("입력된 점수가 현재 목록의 모든 점수보다 낮습니다.\n");
//     }
// }