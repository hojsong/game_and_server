#include "../header/client.h"

void	wlmodeChoice(int key_code)
{
    static int  result = 1;
    if (key_code == KEY_W || key_code == KEY_W2)
        result++;
    else if (key_code == KEY_S || key_code == KEY_S2)
        result--;
    else if (key_code == KEY_ENTER)
    {
        g_game.wlmode = result;
        return ;
    }
    if (result < 1)
        result += 2;
    else if (result > 2)
        result -= 2;
    if (result == 1)
        choiceImagesPut("WebMode");
    else if (result == 2)
        choiceImagesPut("LocalMode");
}

void	airplainChoice(int key_code)
{
    static int  result = 0;
    if (key_code == KEY_W || key_code == KEY_W2)
        result++;
    else if (key_code == KEY_S || key_code == KEY_S2)
        result--;
    else if (key_code == KEY_ENTER)
    {
        if (g_game.my_character == NULL)
            g_game.my_character = malloc(sizeof(g_game.my_character));
        g_game.my_character->x = (Window_x - Charactet_x) / 2;
        g_game.my_character->y = (Window_y - Charactet_y) / 2;
        g_game.my_character->image = g_game.characterImages[result];
    }
    
    if (result < 0)
        result += 5;
    else if (result > 4)
        result -= 5;
}

void    modeChoice(int key_code)
{
    static int  result = 1;
    if (key_code == KEY_W || key_code == KEY_W2)
        result++;
    else if (key_code == KEY_S || key_code == KEY_S2)
        result--;
    else if (key_code == KEY_ENTER)
    {
        g_game.mode = result;
        return ;
    }
    if (result < 1)
        result += 3;
    else if (result > 3)
        result -= 3;
    if (result == 1)
        choiceImagesPut("EASY");
    else if (result == 2)
        choiceImagesPut("NOMAL");
    else if (result == 2)
        choiceImagesPut("HARD");
}

void    continue_or_exit(int key_code)
{
    static int  result = 0;
    if (key_code == KEY_W || key_code == KEY_W2)
        result++;
    else if (key_code == KEY_S || key_code == KEY_S2)
        result--;
    else if (key_code == KEY_ENTER)
    {
        g_game.wlmode = 0;
        free(g_game.my_character);
        g_game.my_character = NULL;
        g_game.mode = 0;
        g_game.die = 0;
        if (result == 1)
        {
            mlx_destroy_window(g_game.mlx, g_game.win);
	        exit(0);
        }
        return ;
    }
    if (result < 1)
        result += 2;
    else if (result > 2)
        result -= 2;
        if (result == 1)
        choiceImagesPut("EXIT");
    else if (result == 2)
        choiceImagesPut("Continue");
}
