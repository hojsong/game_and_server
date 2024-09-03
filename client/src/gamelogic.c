#include "../header/client.h"

void    gaming(int key_code)
{
    
}


void	mlxstart(void)
{
    char    **data;

	if(g_game.wlmode == 0)
		mlx_hook(g_game.win, X_EVENT_KEY_PRESS, 0, &wlmodeChoice, NULL);
	else if(g_game.my_character == NULL)
		mlx_hook(g_game.win, X_EVENT_KEY_PRESS, 0, &airplainChoice, NULL);
	else if(g_game.mode == 0)
		mlx_hook(g_game.win, X_EVENT_KEY_PRESS, 0, &modeChoice, NULL);
    else if(g_game.die == 0)
    	mlx_hook(g_game.win, X_EVENT_KEY_PRESS, 0, &gaming, NULL);
    else
    {
	    if (g_game.wlmode == 1)
    		data = servDataLoad();
	    else if (g_game.wlmode == 2)
		    data = localDataLoad();
    	mlx_hook(g_game.win, X_EVENT_KEY_PRESS, 0, &continue_or_exit, NULL);
    }
}