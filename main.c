/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:09:20 by muerdoga          #+#    #+#             */
/*   Updated: 2023/09/02 19:38:38 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_player(t_cub3d *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->b_map[y])
	{
		x = 0;
		while (game->b_map[y][x])
		{
			if (is_user_char(game->b_map[y][x]))
			{
				game->player.x = (double)x + 0.5;
				game->player.y = (double)y + 0.5;
			}
			x++;
		}
		y++;
	}
}

void	fill_player_dir(t_cub3d *game, double x, double y)
{
	game->player.dir_x = x;
	game->player.dir_y = y;
	if (x < 0.0)
		game->player.plane_y = -0.66;
	else if (x > 0.0)
		game->player.plane_y = 0.66;
	else
		game->player.plane_y = 0;
	if (y < 0.0)
		game->player.plane_x = 0.66;
	else if (y > 0.0)
		game->player.plane_x = -0.66;
	else
		game->player.plane_x = 0;
}

void	player_first_rotate(t_cub3d *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->b_map[y])
	{
		x = 0;
		while (game->b_map[y][x])
		{
			if (game->b_map[y][x] == 'N')
				fill_player_dir(game, 0.0, -1.0);
			else if (game->b_map[y][x] == 'S')
				fill_player_dir(game, 0.0, 1.0);
			else if (game->b_map[y][x] == 'W')
				fill_player_dir(game, -1.0, 0.0);
			else if (game->b_map[y][x] == 'E')
				fill_player_dir(game, 1.0, 0.0);
			x++;
		}
		y++;
	}
}

int	ft_game_loop(t_cub3d *game)
{
	if (game->lock)
	{
		mlx_mouse_show();
		return (0);
	}
	player_move(game);
	mlx_mouse_get_pos(game->img.window, &(game->loc_x), &(game->loc_y));
	if (game->loc_x - game->m_old_pos_x != 0)
		rotate_with_mouse(game);
	mlx_mouse_move(game->img.window, WIDTH / 2, HEIGHT / 2);
	game->m_old_pos_x = WIDTH / 2;
	game->m_old_pos_y = HEIGHT / 2;
	game->loc_x = WIDTH / 2;
	game->loc_y = HEIGHT / 2;
	game->map_wd = ft_strlen(game->b_map[0]);
	game_arithmetic(game);
	print_mini_map(game);
	print_player(game, game->x, game->y, game->scale);
	mlx_put_image_to_window(game->mlx, game->img.window, game->img.image, 0, 0);
	gun_show(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub3d	*game;

	if (ac == 2)
	{
		game = malloc(sizeof(t_cub3d));
		start_game(game);
		start_map(game, av[1]);
		start_mlx(game);
		mlx_hook(game->img.window, 2, 0, key_press, game);
		mlx_hook(game->img.window, 3, 0, key_release, game);
		mlx_hook(game->img.window, 17, 1L << 2, x_close, game);
		mlx_loop_hook(game->mlx, &ft_game_loop, game);
		free_map(game, game->map);
		mlx_loop(game->mlx);
	}
	else
		color_print("number of erroneous parameters", 'r');
	mlx_destroy_window(game->mlx, game->img.window);
	mlx_destroy_image(game->mlx, game->img.image);
	return (0);
}
