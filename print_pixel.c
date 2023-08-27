/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:28:35 by bkarlida          #+#    #+#             */
/*   Updated: 2023/08/27 13:11:13 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_player(t_cub3d *game, int x, int y, double scale)
{
	int	i;
	int	j;

	i = -2;
	j = -2;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
			put_px_img(game, (int)(game->player.x
					* ((WIDTH / scale) / (double) game->map_wd) + x + i),
				(int)(game->player.y * ((HEIGHT / scale)
						/ (double) game->map_he) + y + j),
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
	game->map_he = 0;
	while (game->b_map[game->map_he] != NULL)
		game->map_he++;
	mini_x = -1;
	while ((int)(++mini_x / ((WIDTH / game->scale)
			/ (double) game->map_wd)) < game->map_wd)
	{
		mini_y = -1;
		while ((int)(++mini_y / ((HEIGHT / game->scale)
				/ (double) game->map_he)) < game->map_he)
		{
			if (game->b_map[(int)(mini_y / ((HEIGHT / game->scale) / (double)
						game->map_he))][(int)(mini_x / ((WIDTH / game->scale)
					/ (double) game->map_wd))] == '1')
				put_px_img(game, mini_x + game->x, mini_y + game->y,
					create_trgb(0, 190, 190, 190));
			else
				put_px_img(game, mini_x + game->x, mini_y + game->y,
					create_trgb(0, 90, 90, 90));
		}
	}
}