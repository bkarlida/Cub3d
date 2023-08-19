/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:05:09 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/19 21:14:27 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	x_close(int keycode, t_cub3d *game)
{
	color_print("Cub3d closed successfully!", 'g');
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_press(int key_code, t_cub3d *game)
{
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
    else if (key_code == 53)
	{
        color_print("Cub3d closed successfully!", 'g');
	    exit(EXIT_SUCCESS);
    }
	return (0);
}

int	key_release(int key_code, t_cub3d *game)
{
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
