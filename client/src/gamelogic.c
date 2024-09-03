#include "../header/client.h"

// void    gaming(int key_code)
// {
    
// }


int	mlxstart(int key_code, t_game *game)
{
    // char    **data;

	if(game->wlmode == 0)
		wlmodeChoice(key_code, game);
	else if(game->my_character.num == -1)
		airplainChoice(key_code, game);
	else if(game->mode == 0)
		modeChoice(key_code, game);
    // else if(game->die == 0)
    	// gaming(key_code, game);
    else
    {
	    // if (game->wlmode == 1)
    		// data = servDataLoad(game);
	    // else if (game->wlmode == 2)
		    // data = localDataLoad(game);
    	continue_or_exit(key_code, game);
    }
	return (0);
}