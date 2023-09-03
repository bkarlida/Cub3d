/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:49:16 by bkarlida          #+#    #+#             */
/*   Updated: 2023/09/03 15:04:49 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_with_mouse(t_cub3d *game)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_x;

	
	rot_x = game->player.rot_speed * ((game->loc_x - game->m_old_pos_x)
				/ 10.0);
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(rot_x) - game->player.dir_y
		* sin(rot_x);
	game->player.dir_y = old_dir_x * sin(rot_x) + game->player.dir_y
		* cos(rot_x);
	game->player.plane_x = game->player.plane_x * cos(rot_x)
		- game->player.plane_y * sin(rot_x);
	game->player.plane_y = old_plane_x * sin(rot_x) + game->player.plane_y
		* cos(rot_x);
}
