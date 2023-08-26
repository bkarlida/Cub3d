/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:33:21 by bkarlida          #+#    #+#             */
/*   Updated: 2023/08/26 19:33:29 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_frame_init(t_cub3d *game)
{
	game->camera_x = 2 * game->x / (double) WIDTH - 1;
	game->ray_dir_x = game->player.dir_x + game->player.plane_x
		* game->camera_x;
	game->ray_dir_y = game->player.dir_y + game->player.plane_y
		* game->camera_x;
	game->map_x = (int) game->player.x;
	game->map_y = (int) game->player.y;
	if (game->ray_dir_x == 0)
		game->delta_dist_x = 1e30;
	else
		game->delta_dist_x = fabs(1 / game->ray_dir_x);
	if (game->ray_dir_y == 0)
		game->delta_dist_y = 1e30;
	else
		game->delta_dist_y = fabs(1 / game->ray_dir_y);
	game->hit = 0;
}

void	calc_side_dist(t_cub3d *game)
{
	if (game->ray_dir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->player.x - game->map_x) * game->delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x + 1.0 - game->player.x)
			* game->delta_dist_x;
	}
	if (game->ray_dir_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->player.y - game->map_y) * game->delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y + 1.0 - game->player.y)
			* game->delta_dist_y;
	}
}

void	calc_wall_height(t_cub3d *game)
{
	while (game->hit == 0)
	{
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x += game->delta_dist_x;
			game->map_x += game->step_x;
			game->side = 0;
		}
		else
		{
			game->side_dist_y += game->delta_dist_y;
			game->map_y += game->step_y;
			game->side = 1;
		}
		if (game->map[game->map_y][game->map_x] > 0)
			game->hit = 1;
	}
	if (game->side == 0)
		game->perp_wall_dist = (game->side_dist_x - game->delta_dist_x);
	else
		game->perp_wall_dist = (game->side_dist_y - game->delta_dist_y);
	game->line_height = (int)(HEIGHT / game->perp_wall_dist);
}

void	calc_wall_x(t_cub3d *game)
{
	game->draw_start = -game->line_height / 2 + HEIGHT / 2;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + HEIGHT / 2;
	if (game->draw_end >= HEIGHT)
		game->draw_end = HEIGHT - 1;
	if (game->side == 0)
		game->wall_x = game->player.y + game->perp_wall_dist * game->ray_dir_y;
	else
		game->wall_x = game->player.x + game->perp_wall_dist * game->ray_dir_x;
	game->wall_x -= floor(game->wall_x);
}

void	game_arithmetic(t_cub3d *game)
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