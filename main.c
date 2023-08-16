#include "cub3d.h"

int main(int ac, char **av){
    t_cub3d *game;

    if(ac == 2){
        game = malloc(sizeof(t_cub3d));
        start_cub3d(game);
        start_mlx(game);
        start_map(game, av[1]);
        mlx_hook(game->img.window, 2, 0, key_press, game);
	    mlx_hook(game->img.window, 3, 0, key_release, game);
	    mlx_hook(game->img.window, 17, 1L << 2, x_close, game);
        mlx_loop_hook(game->mlx, &ft_game_loop, game);
        mlx_loop(game->mlx);
    }
    else{
        ultimate_print("number of erroneous parameters", 'r', game);
        exit(1);
    }
}

void start_cub3d(t_cub3d *game){
    game->map = NULL;
    game->c_map = NULL;
    game->x_map = NULL;
    game->north.path = NULL;
    game->south.path = NULL;
    game->east.path = NULL;
    game->west.path = NULL;
    game->north.use = 0;
    game->south.use = 0;
    game->east.use = 0;
    game->west.use = 0;
    game->floor.use = 0;
    game->sky.use = 0;

    game->move[0] = 0;
    game->move[1] = 0;
    game->move[2] = 0;
    game->move[3] = 0;
    game->move[4] = 0;
    game->move[5] = 0;
}
