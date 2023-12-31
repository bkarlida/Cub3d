/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:05:09 by muerdoga          #+#    #+#             */
/*   Updated: 2023/09/02 18:59:21 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	x_close(int keycode, t_cub3d *game)
{
	color_print("Cub3d closed successfully!", 'g');
	exit(EXIT_SUCCESS);
	return (0);
}

void	draw_pause(t_cub3d *game)
{
	int	i;
	int	j;

	i = 3 * WIDTH / 8 - 1;
	while (++i < (15 * WIDTH) / 32)
	{
		j = HEIGHT / 3 - 1;
		while (++j < (2 * HEIGHT) / 3)
			put_px_img(game, i, j, create_trgb(50, 255, 255, 255));
	}
	i = (17 * WIDTH) / 32 - 1;
	while (++i < (5 * WIDTH) / 8)
	{
		j = HEIGHT / 3 - 1;
		while (++j < (2 * HEIGHT) / 3)
			put_px_img(game, i, j, create_trgb(50, 255, 255, 255));
	}
	mlx_put_image_to_window(game->mlx, game->img.window, game->img.image, 0, 0);
	gun_show(game);
}

void	key_press_v2(int key_code, t_cub3d *game)
{
	if (key_code == 35)
	{
		draw_pause(game);
		game->lock = !game->lock;
	}
	if (game->lock == 0)
	{
		mlx_mouse_hide();
		mlx_mouse_move(game->img.window, WIDTH / 2, HEIGHT / 2);
	}
}

int	key_press(int key_code, t_cub3d *game)
{
	if (key_code == 13)
		game->move[0] = 1;
	else if (key_code == 1)
		game->move[1] = 1;
	else if (key_code == 0)
		game->move[2] = 1;
	else if (key_code == 2)
		game->move[3] = 1;
	else if (key_code == 123)
		game->move[4] = 1;
	else if (key_code == 124)
		game->move[5] = 1;
	else if (key_code == 18)
		game->gun_flag = 1;
	else if (key_code == 19)
		game->gun_flag = 2;
	else if (key_code == 20)
		game->gun_flag = 3;
	else if (key_code == 53)
	{
		color_print("Cub3d closed successfully!", 'g');
		exit(EXIT_SUCCESS);
	}
	key_press_v2(key_code, game);
	return (0);
}

int	key_release(int key_code, t_cub3d *game)
{
	if (key_code == 13)
		game->move[0] = 0;
	else if (key_code == 1)
		game->move[1] = 0;
	else if (key_code == 0)
		game->move[2] = 0;
	else if (key_code == 2)
		game->move[3] = 0;
	else if (key_code == 123)
		game->move[4] = 0;
	else if (key_code == 124)
		game->move[5] = 0;
	return (0);
}
