/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 13:34:41 by bkarlida          #+#    #+#             */
/*   Updated: 2023/09/02 13:34:54 by bkarlida         ###   ########.fr       */
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
