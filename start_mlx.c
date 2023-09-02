/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:03:13 by muerdoga          #+#    #+#             */
/*   Updated: 2023/09/02 13:24:09 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_mlx(t_cub3d *game)
{
	game->mlx = mlx_init();
	game->img.window = mlx_new_window(game->mlx, 800, 600, "Cub3D");
	mlx_mouse_move(game->img.window, WIDTH / 2, HEIGHT / 2);
	mlx_mouse_hide();
	start_img(game);
	open_textures(game);
	find_player(game);
	player_first_rotate(game);
}

void	start_img(t_cub3d *game)
{
	int	bpp;
	int	sizeline;
	int	endian;

	game->img.image = mlx_new_image(game->mlx, 800, 600);
	game->img.data = mlx_get_data_addr(game->img.image, &bpp,
			&sizeline, &endian);
	game->img.bpp = bpp;
	game->img.sizeline = sizeline;
	game->img.endian = endian;
}
