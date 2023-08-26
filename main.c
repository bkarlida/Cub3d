/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:09:20 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/26 20:38:16 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_game_loop(t_cub3d *game)
{
    if (game->lock)
	{
		mlx_mouse_show();
		return (0);
	}
    player_move(game); // hız ayarlama ve hareketler burada
    	mlx_mouse_get_pos(game->img.window, &(game->loc_x), &(game->loc_y));
	if (game->loc_x - game->m_old_pos_x != 0)
		rotate_with_mouse(game);
	mlx_mouse_move(game->img.window, WIDTH / 2, HEIGHT / 2);
    game->m_old_pos_x = WIDTH / 2;
	game->m_old_pos_y = HEIGHT / 2;
	game->loc_x = WIDTH / 2;
	game->loc_y = HEIGHT / 2;
    game->map_wd = ft_strlen(game->c_map[0]);
    game_arithmetic(game);
    print_mini_map(game);
	print_player(game, game->x, game->y, game->scale);
	mlx_put_image_to_window(game->mlx, game->img.window, game->img.image, 0, 0);
    return(0);
}

int main(int ac, char **av){
    t_cub3d *game;

    if(ac == 2){
        game = malloc(sizeof(t_cub3d));
        start_game(game);
        start_map(game, av[1]);
        start_mlx(game);
        mlx_hook(game->img.window, 2, 0, key_press, game);
	    mlx_hook(game->img.window, 3, 0, key_release, game);
	    mlx_hook(game->img.window, 17, 1L << 2, x_close, game);
        mlx_loop_hook(game->mlx, &ft_game_loop, game);
        mlx_loop(game->mlx);
    }
    else{
        color_print("number of erroneous parameters", 'r');
    }
    return(0);
}

void start_game(t_cub3d *game){
    game->map = NULL;
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
    game->lock = 0;
}