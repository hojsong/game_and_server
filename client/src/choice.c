#include "../header/client.h"

int	wlmodeChoice(int key_code, t_game *game)
{
    static int  result = 1;
    if (key_code == KEY_W || key_code == KEY_W2)
        result++;
    else if (key_code == KEY_S || key_code == KEY_S2)
        result--;
    else if (key_code == KEY_ENTER)
    {
        game->wlmode = result;
        airPlainChoicePut(0, game);
        result = 1;
        return (0);
    }
    else
        return (0);
    if (result < 1)
        result += 2;
    else if (result > 2)
        result -= 2;
    if (result == 1)
        choiceImagesPut("WebMode", game);
    else if (result == 2)
        choiceImagesPut("LocalMode", game);
    return (0);
}

int	airplainChoice(int key_code, t_game *game)
{
    static int  result = 0;

    if (key_code == KEY_W || key_code == KEY_W2)
        result++;
    else if (key_code == KEY_S || key_code == KEY_S2)
        result--;
    else if (key_code == KEY_ENTER)
    {
        game->my_character.x = (Window_x - Charactet_x) / 2;
        game->my_character.y = (Window_y - Charactet_y) / 2;
        game->my_character.num = result;
        choiceImagesPut("EASY", game);
        result = 0;
        return (0);
    }
    else
        return (0);
    if (result < 0)
        result += 5;
    else if (result > 4)
        result -= 5;
    airPlainChoicePut(result, game);
    return (0);
}

int    modeChoice(int key_code, t_game *game)
{
    static int  result = 1;
    if (key_code == KEY_W || key_code == KEY_W2)
        result++;
    else if (key_code == KEY_S || key_code == KEY_S2)
        result--;
    else if (key_code == KEY_ENTER)
    {
        // 쓰레드 생성 (캐릭터움직임, 총알의 움직임 과 생성 및 파괴, 죽음감지)

        game->die = 1;
        choiceImagesPut("EXIT", game);
        game->mode = result;
        result = 1;
        return (0);
    }
    else
        return(0);
    if (result < 1)
        result += 3;
    else if (result > 3)
        result -= 3;
    if (result == 1)
        choiceImagesPut("EASY", game);
    else if (result == 2)
        choiceImagesPut("NORMAL", game);
    else if (result == 3)
        choiceImagesPut("HARD", game);
    return (0);
}

int    continue_or_exit(int key_code, t_game *game)
{
    static int  result = 1;
    if (key_code == KEY_W || key_code == KEY_W2)
        result++;
    else if (key_code == KEY_S || key_code == KEY_S2)
        result--;
    else if (key_code == KEY_ENTER)
    {
        if (result == 1)
        {
            mlx_destroy_window(game->mlx, game->win);
	        exit(0);
        }
        else
        {
            game->wlmode = 0;
            game->mode = 0;
            game->die = 0;
            game->my_character.num = -1;
            mapinit(game);
	        choiceImagesPut("WebMode", game);
        }
        result = 1;
        return (0);
    }
    else
        return (0);
    if (result < 1)
        result += 2;
    else if (result > 2)
        result -= 2;
    if (result == 1)
        choiceImagesPut("EXIT", game);
    else if (result == 2)
        choiceImagesPut("Continue", game);
    return (0);
}
