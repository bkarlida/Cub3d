/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:03:13 by muerdoga          #+#    #+#             */
/*   Updated: 2023/09/03 13:36:41 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_mlx(t_cub3d *game)
{
	game->mlx = mlx_init();
	game->img.window = mlx_new_window(game->mlx, 800, 600, "Cub3D");
	game->gun1 = mlx_xpm_file_to_image(game->mlx, "textures/lev.xpm",
			&(game->gun_h), &(game->gun_w));
	game->gun2 = mlx_xpm_file_to_image(game->mlx, "textures/pom.xpm",
			&(game->gun_h), &(game->gun_w));
	game->gun3 = mlx_xpm_file_to_image(game->mlx, "textures/tar.xpm",
			&(game->gun_h), &(game->gun_w));
	game->gun4 = mlx_xpm_file_to_image(game->mlx, "textures/fire.xpm",
			&(game->gun_h), &(game->gun_w));
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

void	gun_show(t_cub3d *game)
{
	if (game->gun_flag == 1)
		mlx_put_image_to_window(game->mlx, game->img.window, game->gun1, 0, 0);
	if (game->gun_flag == 2)
		mlx_put_image_to_window(game->mlx, game->img.window, game->gun2, 0, 0);
	if (game->gun_flag == 3)
		mlx_put_image_to_window(game->mlx, game->img.window, game->gun3, 0, 0);
}

int	mouse_click(int button, int x, int y, t_cub3d *game)
{
	if (button == 1 && game->lock == 0)
	{
		mlx_put_image_to_window(game->mlx, game->img.window, game->gun4, 0, 0);
	}
	return (0);
}
