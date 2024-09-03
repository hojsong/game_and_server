#include "../header/client.h"

void    choiceImagesPut(char *str)
{
    int     img_width, img_height;
    int     x0, x1, y0 , y1, y3, len;
    char    *resource;
    void    *modexpmimage;

    len = strlen("./source/image/xpm/") + strlen(str) + strlen(".xpm");
    while(resource == NULL)
        resource = malloc(sizeof(char) * (len + 1));
    strcat(resource, "./source/image/xpm/");
    strcat(resource, str);
    strcat(resource, ".xpm");

    x0 = (Window_x - ARROW_X) / 2;
    x1 = (Window_x / 2) - 200;
    y0 = (Window_y / 2) + 200;
    y1 = (Window_y / 2) - 200 - ARROW_Y;
    y3 = (Window_y / 2) - 100;
    mlx_put_image_to_window(g_game.mlx, g_game.win, g_game.backgraunbd, 0, 0);
    mlx_put_image_to_window(g_game.mlx, g_game.win, g_game.arrow[0], x0, y0);
    mlx_put_image_to_window(g_game.mlx, g_game.win, g_game.backgraunbd, x0, y1);
    modexpmimage = mlx_xpm_file_to_image(g_game.mlx, \
			resource, &img_width, &img_height);
    mlx_put_image_to_window(g_game.mlx, g_game.win, modexpmimage, x1, y3);
    free(resource);
}

void    airPlainChoicePut(int result)
{
    int     img_width, img_height;
    int     x0, x1, y0 , y1, y3, len;

    x0 = (Window_x - ARROW_X) / 2;
    x1 = (Window_x - Charactet_x) / 2;

    y0 = (Window_y / 2) + 200;
    y1 = (Window_y / 2) - 200 - ARROW_Y;
    y3 = (Window_y - Charactet_y) / 2;
    
    mlx_put_image_to_window(g_game.mlx, g_game.win, g_game.backgraunbd, 0, 0);
    mlx_put_image_to_window(g_game.mlx, g_game.win, g_game.arrow[0], x0, y0);
    mlx_put_image_to_window(g_game.mlx, g_game.win, g_game.backgraunbd, x0, y1);
    mlx_put_image_to_window(g_game.mlx, g_game.win, g_game.characterImages[result], x1, y3);
}

void    imagePut()
{

}