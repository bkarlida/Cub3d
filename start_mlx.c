/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:36:12 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/16 17:09:37 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void start_mlx(t_cub3d *game){
    game->mlx = mlx_init();
    game->img.window = mlx_new_window(game->mlx, 800, 600, "Cub3D");
    start_img(game);
}

int ft_game_loop(t_cub3d *game)
{
    //player_move(game);


    
    return (0);
}

// void player_move(t_cub3d *game)
// {
//     if(game->move[0] == 1)
//         //move_forward(game);
//     else if(game->move[1] == 1)
//         //move_back(game);
//     if(game->move[2] == 1)
//         //move_left(game);
//     else if(game->move[3] == 1)
//         //move_right(game);
//     if(game->move[4] == 1)
//         //rotate_left(game);
//     else if(game->move[5] == 1)
//         //rotate_right(game);
 
// }


int	x_close(int keycode, t_cub3d *game)
{
	ultimate_print("Cub3d closed successfully!", 'g', game);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_press(int key_code, t_cub3d *game)
{
    printf("Bastın : %d\n", key_code);
	if (key_code == 13)
		game->move[0] = 1;
	else if (key_code == 1)
		game->move[1] = 1;
	else if (key_code == 0)
		game->move[2] = 1;
	else if (key_code == 2)
		game->move[3] = 1;
	else if (key_code == 123)
		game->move[4] = 1;
	else if (key_code == 124)
		game->move[5] = 1;
	return (0);
}

int	key_release(int key_code, t_cub3d *game)
{
	printf("Bıraktın : %d\n", key_code);
	if (key_code == 13)
		game->move[0] = 0;
	else if (key_code == 1)
		game->move[1] = 0;
	else if (key_code == 0)
		game->move[2] = 0;
	else if (key_code == 2)
		game->move[3] = 0;
	else if (key_code == 123)
		game->move[4] = 0;
	else if (key_code == 124)
		game->move[5] = 0;
	return (0);
}

void start_img(t_cub3d *game){
    int bpp;
    int sizeline;
    int endian;

    game->img.image = mlx_new_image(game->mlx, 800, 600);
    game->img.data = mlx_get_data_addr(game->img.image, &bpp, &sizeline, &endian);
    game->img.bpp = bpp;
    game->img.sizeline = sizeline;
    game->img.endian = endian;
}
