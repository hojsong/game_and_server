#include "../header/client.h"

// void    gaming(int key_code)
// {
    
// }


void	mlxstart(t_game game)
{
    // char    **data;

	if(game.wlmode == 0)
		mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &wlmodeChoice, &game);
	else if(game.my_character == NULL)
		mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &airplainChoice, &game);
	else if(game.mode == 0)
		mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &modeChoice, &game);
    // else if(game.die == 0)
    	// mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &gaming, &game);
    else
    {
	    // if (game.wlmode == 1)
    		// data = servDataLoad(game);
	    // else if (game.wlmode == 2)
		    // data = localDataLoad(game);
    	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &continue_or_exit, &game);
    }
	mlx_loop(game.mlx);
}