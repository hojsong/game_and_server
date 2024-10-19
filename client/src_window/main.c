#include "../header/client.h"
#include <SDL2/SDL.h>

int main()
{
    t_game game;
    
    // SDL 초기화
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // 윈도우 생성
    game.win = SDL_CreateWindow("Dodge Bullets", 
                                SDL_WINDOWPOS_CENTERED, 
                                SDL_WINDOWPOS_CENTERED, 
                                Window_x, 
                                Window_y, 
                                SDL_WINDOW_SHOWN);
    if (game.win == NULL)
    {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // 렌더러 생성 (SDL에서 화면을 그리기 위해 필요)
    game.renderer = SDL_CreateRenderer(game.win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (game.renderer == NULL)
    {
        SDL_DestroyWindow(game.win);
        printf("SDL_CreateRenderer Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    game_image_xpm_init(&game);  // 게임 이미지 초기화
    pthread_mutex_init(&game.player_mutex, NULL);
    choiceImagesPut("WebMode", &game);  // 선택된 이미지 출력 함수

    // 이벤트 루프
    SDL_Event e;
    int running = 1;
    while (running)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                running = 0;
            }
            if (e.type == SDL_KEYDOWN)
            {
                mlxstart(&game);  // 키를 눌렀을 때 실행하는 함수
            }
            if (e.type == SDL_KEYUP)
            {
                key_release(&game);  // 키를 뗐을 때 실행하는 함수
            }
        }

        bullet_init_c_d_m_p(&game);  // 매 프레임마다 실행되는 루프 함수

        // 화면 업데이트
        SDL_RenderClear(game.renderer);
        SDL_RenderPresent(game.renderer);
    }

    // SDL 리소스 해제
    SDL_DestroyRenderer(game.renderer);
    SDL_DestroyWindow(game.win);
    SDL_Quit();

    return 0;
}
