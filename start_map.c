/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:09:27 by muerdoga          #+#    #+#             */
/*   Updated: 2023/09/02 15:54:12 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_map(t_cub3d *game, char *map_name)
{
	int	fd;
	int	map_index;

	map_name_control(map_name);
	fd = file_control(game, map_name);
	game->map = file_read(game, fd);
	take_textures(game);
	map_char_control(game);
	copy_map(game);
	xpm_control(game);
	map_division_control(game);
	fill_x_map(game);
	map_cover_x(game);
	map_cover_b(game);
	map_x_control(game);
}

void	start_game_utils(t_cub3d *game)
{
	game->map = NULL;
	game->c_map = NULL;
	game->x_map = NULL;
	game->north.path = NULL;
	game->south.path = NULL;
	game->east.path = NULL;
	game->west.path = NULL;
	game->north.use = 0;
	game->south.use = 0;
	game->east.use = 0;
	game->west.use = 0;
	game->floor.use = 0;
	game->sky.use = 0;
	game->gun_w = 500;
	game->gun_h = 350;
}

void	start_game(t_cub3d *game)
{
	start_game_utils(game);
	game->move[0] = 0;
	game->move[1] = 0;
	game->move[2] = 0;
	game->move[3] = 0;
	game->move[4] = 0;
	game->move[5] = 0;
	game->lock = 0;
	game->player.x = 0;
	game->player.y = 0;
	game->player.speed = 0.06;
	game->player.rot_speed = 0.04;
	game->m_old_pos_x = WIDTH / 2;
	game->m_old_pos_y = HEIGHT / 2;
	game->loc_x = WIDTH / 2;
	game->loc_y = HEIGHT / 2;
	game->gun_flag = 1;
}

void	map_x_control(t_cub3d *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->b_map[y] != NULL)
	{
		x = 0;
		while (game->b_map[y][x] != '\0')
		{
			if (game->b_map[y][x] == 'X')
			{
				if (game->b_map[y][x + 1] == '0')
					color_print_exit("faulty map layout", 'r');
				else if (game->b_map[y][x - 1] == '0')
					color_print_exit("faulty map layout", 'r');
				else if (game->b_map[y + 1][x] == '0')
					color_print_exit("faulty map layout", 'r');
				else if (game->b_map[y - 1][x] == '0')
					color_print_exit("faulty map layout", 'r');
			}
			x++;
		}
		y++;
	}
}

void	map_char_control(t_cub3d *game)
{
	int	map_index;
	int	player_count;
	int	i;

	map_index = 6;
	player_count = 0;
	while (game->map[map_index])
	{
		i = 0;
		while (game->map[map_index][i])
		{
			map_char_control_utils(game, &map_index, &i, &player_count);
			i++;
		}
		map_index++;
	}
	if (player_count != 1)
	{
		color_print("player count error", 'r');
		exit(1);
	}
}
