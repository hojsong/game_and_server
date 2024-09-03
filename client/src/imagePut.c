#include "../header/client.h"

static char    *xpm_dir_sum(char *dir, char *src_name, char *expr)
{
    char    *result;
    int     i, len, dir_len, src_name_len, expr_len;

    dir_len = strlen(dir);
    src_name_len = strlen(src_name);
    expr_len = strlen(expr);
    len = dir_len + src_name_len + expr_len;
    i = 0;
    result = malloc(sizeof(char) * (len + 1));
    while (i < dir_len)
    {
        result[i] = dir[i];
        i++;
    }
    while (i - dir_len < src_name_len)
    {
        result[i] = src_name[i - dir_len];
        i++;
    }
    while (i - dir_len - src_name_len < expr_len)
    {
        result[i] = expr[i - dir_len - src_name_len];
        i++;
    }
    result[i] = '\0';
    return (result);
}

void    choiceImagesPut(char *str, t_game *game)
{
    int     img_width, img_height;
    int     x0, x1, y0 , y1, y3;
    char    *resource;
    void    *modexpmimage;

    resource = xpm_dir_sum("./source/image/xpm/", str, ".xpm");
    // printf("%s\n", resource);
    x0 = (Window_x - ARROW_X) / 2;
    x1 = (Window_x / 2) - 200;
    y0 = (Window_y / 2) + 200;
    y1 = (Window_y / 2) - 200 - ARROW_Y;
    y3 = (Window_y / 2) - 100;
    mlx_put_image_to_window(game->mlx, game->win, game->backgraunbd, 0, 0);
    mlx_put_image_to_window(game->mlx, game->win, game->arrow[1], x0, y0);
    mlx_put_image_to_window(game->mlx, game->win, game->arrow[0], x0, y1);
    modexpmimage = mlx_xpm_file_to_image(game->mlx, \
			resource, &img_width, &img_height);
    if (modexpmimage != NULL)
    {
        mlx_put_image_to_window(game->mlx, game->win, modexpmimage, x1, y3);
        free(modexpmimage);
    }
    free(resource);
}

void    airPlainChoicePut(int result, t_game *game)
{
    int     x0, x1, y0 , y1, y3;

    x0 = (Window_x - ARROW_X) / 2;
    x1 = (Window_x - Charactet_x) / 2;

    y0 = (Window_y / 2) + 200;
    y1 = (Window_y / 2) - 200 - ARROW_Y;
    y3 = (Window_y - Charactet_y) / 2;
    
    mlx_put_image_to_window(game->mlx, game->win, game->backgraunbd, 0, 0);
    mlx_put_image_to_window(game->mlx, game->win, game->arrow[0], x0, y0);
    mlx_put_image_to_window(game->mlx, game->win, game->backgraunbd, x0, y1);
    mlx_put_image_to_window(game->mlx, game->win, game->characterImages[result], x1, y3);
}

void    imagePut()
{

}