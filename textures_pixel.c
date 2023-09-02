/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_pixel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:24:11 by bkarlida          #+#    #+#             */
/*   Updated: 2023/09/02 20:10:28 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_pixel_in_tex(t_texture tex, int x, int y)
{
	char	*dst;

	dst = tex.data + (y * tex.sizeline + x * (tex.bpp / 8));
	return (*((unsigned int *)dst));
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	put_px_img(t_cub3d *f, int x, int y, int color)
{
	char	*dst;

	dst = f->img.data + (y * f->img.sizeline + x * (f->img.bpp / 8));
	*(unsigned int *)dst = color;
}

void	calc_texture_pixel_color(t_cub3d *game)
{
	int	color;
	int	tex_y;

	if (game->y < game->draw_start)
		put_px_img(game, game->x, game->y, create_trgb(0, game->sky.r,
				game->sky.g, game->sky.b));
	else if (game->y >= game->draw_start && game->y <= game->draw_end)
	{
		tex_y = (int)game->tex_pos & (TEX_H - 1);
		game->tex_pos += game->step;
		if (game->side == 0 && game->ray_dir_x > 0)
			color = get_pixel_in_tex(game->north, game->tex_x, tex_y);
		else if (game->side == 0 && game->ray_dir_x < 0)
			color = get_pixel_in_tex(game->south, game->tex_x, tex_y);
		else if (game->side == 1 && game->ray_dir_y > 0)
			color = get_pixel_in_tex(game->west, game->tex_x, tex_y);
		else if (game->side == 1 && game->ray_dir_y < 0)
			color = get_pixel_in_tex(game->east, game->tex_x, tex_y);
		put_px_img(game, game->x, game->y, color);
	}
	else
		put_px_img(game, game->x, game->y , create_trgb(0, game->floor.r,
				game->floor.g, game->floor.b));
}
