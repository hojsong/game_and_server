#include "../header/client.h"

int	wlmodeChoice(int key_code, t_game *game)
{
    static int  result = 1;
    printf("%d\n", key_code);
    if (key_code == KEY_W || key_code == KEY_W2)
        result++;
    else if (key_code == KEY_S || key_code == KEY_S2)
        result--;
    else if (key_code == KEY_ENTER)
    {
        printf("Save WlMode!!! %d %d\n", result, game->wlmode);
        game->wlmode = result;
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
        if (game->my_character == NULL)
            game->my_character = malloc(sizeof(game->my_character));
        game->my_character->x = (Window_x - Charactet_x) / 2;
        game->my_character->y = (Window_y - Charactet_y) / 2;
        game->my_character->image = game->characterImages[result];
    }
    else
        return (0);
    if (result < 0)
        result += 5;
    else if (result > 4)
        result -= 5;
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
        game->mode = result;
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
        choiceImagesPut("NOMAL", game);
    else if (result == 2)
        choiceImagesPut("HARD", game);
    return (0);
}

int    continue_or_exit(int key_code, t_game *game)
{
    static int  result = 0;
    if (key_code == KEY_W || key_code == KEY_W2)
        result++;
    else if (key_code == KEY_S || key_code == KEY_S2)
        result--;
    else if (key_code == KEY_ENTER)
    {
        game->wlmode = 0;
        free(game->my_character);
        game->my_character = NULL;
        game->mode = 0;
        game->die = 0;
        if (result == 1)
        {
            mlx_destroy_window(game->mlx, game->win);
	        exit(0);
        }
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
