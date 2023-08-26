/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:28:35 by bkarlida          #+#    #+#             */
/*   Updated: 2023/08/26 19:33:00 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_player(t_cub3d *vals, int x, int y, double scale)
{
	int	i;
	int	j;

	i = -2;
	j = -2;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
			put_px_img(vals, (int)(vals->player.x
					* ((WIDTH / scale) / (double) vals->map_wd) + x + i),
				(int)(vals->player.y * ((HEIGHT / scale)
						/ (double) vals->map_he) + y + j),
				create_trgb(0, 255, 0, 0));
	}
}

void	print_mini_map(t_cub3d *game)
{
	int		mini_x;
	int		mini_y;

	game->x = WIDTH / 100;
	game->y = HEIGHT / 100;
	game->scale = 4.0;
	mini_x = -1;
	while ((int)(++mini_x / ((WIDTH / game->scale)
			/ (double) game->map_wd)) < game->map_wd)
	{
		mini_y = -1;
		while ((int)(++mini_y / ((HEIGHT / game->scale)
				/ (double) game->map_he)) < game->map_he)
		{
			if (game->map[(int)(mini_y / ((HEIGHT / game->scale) / (double)
						game->map_he))][(int)(mini_x / ((WIDTH / game->scale)
					/ (double) game->map_wd))] == 1)
				put_px_img(game, mini_x + game->x, mini_y + game->y,
					create_trgb(0, 190, 190, 190));
			else
				put_px_img(game, mini_x + game->x, mini_y + game->y,
					create_trgb(0, 90, 90, 90));
		}
	}
}