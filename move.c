/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:03:12 by bkarlida          #+#    #+#             */
/*   Updated: 2023/08/22 16:09:42 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_cub3d *game)
{
	if (game->map[(int)game->player.y][(int)(game->player.x
		+ game->player.dir_x * game->player.rot_speed)] == 0)
		game->player.x += game->player.dir_x * game->player.rot_speed;
	if (game->map[(int)(game->player.y + game->player.dir_y
			* game->player.rot_speed)][(int)(game->player.x)] == 0)
		game->player.y += game->player.dir_y * game->player.rot_speed;
}

void	move_back(t_cub3d *game)
{
	if (game->map[(int)game->player.y][(int)(game->player.x
		- game->player.dir_x * game->player.rot_speed)] == 0)
		game->player.x -= game->player.dir_x * game->player.rot_speed;
	if (game->map[(int)(game->player.y - game->player.dir_y
			* game->player.rot_speed)][(int)(game->player.x)] == 0)
		game->player.y -= game->player.dir_y * game->player.rot_speed;
}

void	move_left(t_cub3d *game)
{
	if (game->map[(int)game->player.y][(int)(game->player.x + game->player.dir_y
		* game->player.rot_speed)] == 0)
		game->player.x += game->player.dir_y * game->player.rot_speed;
	if (game->map[(int)(game->player.y - game->player.dir_x
			* game->player.rot_speed)][(int)(game->player.x)] == 0)
		game->player.y += -game->player.dir_x * game->player.rot_speed;
}

void	move_right(t_cub3d *game)
{
	if (game->map[(int)game->player.y][(int)(game->player.x - game->player.dir_y
		* game->player.rot_speed)] == 0)
		game->player.x -= game->player.dir_y * game->player.rot_speed;
	if (game->map[(int)(game->player.y + game->player.dir_x
			* game->player.rot_speed)][(int)(game->player.x)] == 0)
		game->player.y -= -game->player.dir_x * game->player.rot_speed;
}

void	player_move(t_cub3d *game)
{
	if ((game->move[0] || game->move[1])
		&& (game->move[2] || game->move[3]))
	game->player.rot_speed = 0.06 / sqrt(2);
	else
		game->player.rot_speed = 0.06;
	if (game->move[0] == 1)
		move_forward(game);
	else if (game->move[1] == 1)
		move_back(game);
	if (game->move[2] == 1)
		move_left(game);
	else if (game->move[3] == 1)
		move_right(game);
	if (game->move[4] == 1)
		rotate_left(game);
	else if (game->move[5] == 1)
		rotate_right(game);
}
