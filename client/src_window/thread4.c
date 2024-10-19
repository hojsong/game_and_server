#include "../header/client.h"
#include <SDL2/SDL.h>

static void putGame_view(t_game *game) {
    SDL_Rect dest_rect; // 이미지 렌더링을 위한 사각형 구조체
    int idx;

    // 화면을 검은색으로 지우기
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255); // 배경색 설정
    SDL_RenderClear(game->renderer); // 화면 지우기

    idx = 0;
    while (idx < game->size) {
        // 총알의 유효한 위치 확인 후 이미지 렌더링
        if (game->bulletimage && 
            game->bullets[idx].x > 2 && 
            game->bullets[idx].x < Window_x - 2 && 
            game->bullets[idx].y > 2 && 
            game->bullets[idx].y < Window_y - 2) {
            
            // 총알 이미지 렌더링
            dest_rect.x = (int)game->bullets[idx].x - 2; // x 위치
            dest_rect.y = (int)game->bullets[idx].y + 2; // y 위치
            dest_rect.w = 4; // 이미지 너비
            dest_rect.h = 4; // 이미지 높이
            SDL_RenderCopy(game->renderer, game->bulletimage, NULL, &dest_rect);
        }
        idx++;
    }

    // 플레이어 캐릭터 렌더링
    dest_rect.x = (int)game->my_character.x - (game->character_x[game->my_character.num] / 2);
    dest_rect.y = (int)game->my_character.y - (game->character_y[game->my_character.num] / 2);
    dest_rect.w = game->character_x[game->my_character.num]; // 캐릭터 너비
    dest_rect.h = game->character_y[game->my_character.num]; // 캐릭터 높이
    SDL_RenderCopy(game->renderer, game->characterImages[game->my_character.num], NULL, &dest_rect);

    // 화면에 모든 렌더링 내용을 업데이트
    SDL_RenderPresent(game->renderer);
}

void *put_game_ing_image(void *ptr) {
    t_game *game = (t_game *)ptr;

    if (game->die == 0)
        putGame_view(game);
    
    return NULL;
}
