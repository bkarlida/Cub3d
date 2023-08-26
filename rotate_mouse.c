/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:49:16 by bkarlida          #+#    #+#             */
/*   Updated: 2023/08/26 20:20:49 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_with_mouse(t_cub3d *vals)
{
	double	old_dir_x;
	double	old_plane_x;
	double	rot_x;

	if (vals->loc_x - vals->m_old_pos_x > 0)
		rot_x = vals->player.rot_speed * ((vals->loc_x
					- vals->m_old_pos_x) / 10.0);
	else
		rot_x = vals->player.rot_speed * ((vals->loc_x
					- vals->m_old_pos_x) / 10.0);
	old_dir_x = vals->player.dir_x;
	old_plane_x = vals->player.plane_x;
	vals->player.dir_x = vals->player.dir_x * cos(rot_x) - vals->player.dir_y
		* sin(rot_x);
	vals->player.dir_y = old_dir_x * sin(rot_x) + vals->player.dir_y
		* cos(rot_x);
	vals->player.plane_x = vals->player.plane_x * cos(rot_x)
		- vals->player.plane_y * sin(rot_x);
	vals->player.plane_y = old_plane_x * sin(rot_x) + vals->player.plane_y
		* cos(rot_x);
}