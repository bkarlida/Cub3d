/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:03:12 by bkarlida          #+#    #+#             */
/*   Updated: 2023/08/27 17:16:49 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_left(t_cub3d *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(-game->player.rot_speed)
		- game->player.dir_y * sin(-game->player.rot_speed);
	game->player.dir_y = old_dir_x * sin(-game->player.rot_speed)
		+ game->player.dir_y * cos(-game->player.rot_speed);
	game->player.plane_x = game->player.plane_x * cos(-game->player.rot_speed)
		- game->player.plane_y * sin(-game->player.rot_speed);
	game->player.plane_y = old_plane_x * sin(-game->player.rot_speed)
		+ game->player.plane_y * cos(-game->player.rot_speed);
}

void	rotate_right(t_cub3d *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(game->player.rot_speed)
		- game->player.dir_y * sin(game->player.rot_speed);
	game->player.dir_y = old_dir_x * sin(game->player.rot_speed)
		+ game->player.dir_y * cos(game->player.rot_speed);
	game->player.plane_x = game->player.plane_x * cos(game->player.rot_speed)
		- game->player.plane_y * sin(game->player.rot_speed);
	game->player.plane_y = old_plane_x * sin(game->player.rot_speed)
		+ game->player.plane_y * cos(game->player.rot_speed);
}

void	move_forward(t_cub3d *game)
{
	printf("AAAA : %c\n", game->b_map[(int)game->player.y][(int)(game->player.x
		+ game->player.dir_x * game->player.speed)]);
	if (game->b_map[(int)game->player.y][(int)(game->player.x
		+ game->player.dir_x * game->player.speed)] == '0')
		game->player.x += game->player.dir_x * game->player.speed;
	if (game->b_map[(int)(game->player.y + game->player.dir_y
			* game->player.speed)][(int)(game->player.x)] == '0')
		game->player.y += game->player.dir_y * game->player.speed;
}

void	move_back(t_cub3d *game)
{
	if (game->b_map[(int)game->player.y][(int)(game->player.x
		- game->player.dir_x * game->player.speed)] == '0')
		game->player.x -= game->player.dir_x * game->player.speed;
	if (game->b_map[(int)(game->player.y - game->player.dir_y
			* game->player.speed)][(int)(game->player.x)] == '0')
		game->player.y -= game->player.dir_y * game->player.speed;
}

void	move_left(t_cub3d *game)
{
	if (game->b_map[(int)game->player.y][(int)(game->player.x + game->player.dir_y
		* game->player.speed)] == '0')
		game->player.x += game->player.dir_y * game->player.speed;
	if (game->b_map[(int)(game->player.y - game->player.dir_x
			* game->player.speed)][(int)(game->player.x)] == '0')
		game->player.y += -game->player.dir_x * game->player.speed;
}

void	move_right(t_cub3d *game)
{
	if (game->b_map[(int)game->player.y][(int)(game->player.x - game->player.dir_y
		* game->player.speed)] == '0')
		game->player.x -= game->player.dir_y * game->player.speed;
	if (game->b_map[(int)(game->player.y + game->player.dir_x
			* game->player.speed)][(int)(game->player.x)] == '0')
		game->player.y -= -game->player.dir_x * game->player.speed;
}
	
void	player_move(t_cub3d *game)
{
	
	if ((game->move[0] || game->move[1])
		&& (game->move[2] || game->move[3]))
	game->player.speed = 0.06 / sqrt(2);
	else
		game->player.speed = 0.06;
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
