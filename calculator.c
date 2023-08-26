/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:33:21 by bkarlida          #+#    #+#             */
/*   Updated: 2023/08/24 12:07:33 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



void	game_is_arithmetic(t_cub3d *game)
{
	game->x = -1;
	mlx_clear_window(game->mlx, game->img.window);
	while (++(game->x) < WIDTH)
	{ 
		calc_frame_init(game);
		calc_side_dist(game);
		calc_wall_height(game);
		calc_wall_x(game);
		game->tex_x = (int)(game->wall_x * (double) TEX_W);
		game->step = 1.0 * TEX_H / game->line_height;
		game->tex_pos = (game->draw_start - HEIGHT / 2 + game->line_height / 2)
			* game->step;
		game->y = -1;
		while (++game->y < HEIGHT)
			calc_texture_pixel_color(game);
	}
}