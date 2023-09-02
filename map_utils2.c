/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:43:47 by muerdoga          #+#    #+#             */
/*   Updated: 2023/09/02 11:59:47 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	xpm_control(t_cub3d *game)
{
	int	*fd;
	int	i;

	fd = malloc(sizeof(int) * 4);
	i = 0;
	fd[0] = open(game->north.path, O_RDONLY);
	fd[1] = open(game->south.path, O_RDONLY);
	fd[2] = open(game->west.path, O_RDONLY);
	fd[3] = open(game->east.path, O_RDONLY);
	while (i < 4)
	{
		if (fd[i] == -1)
		{
			color_print("textures not open", 'r');
			free(fd);
			exit(1);
		}
		i++;
	}
	free(fd);
	name_xpm(game);
}

void	name_xpm(t_cub3d *game)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (game->map[i] != NULL && i < 4)
	{
		len = ft_strlen(game->map[i]);
		if (game->map[i][len - 1] != 'm' || game->map[i][len - 2] != 'p'
			|| game->map[i][len - 3] != 'x' || game->map[i][len - 4] != '.')
		{
			color_print("extension error '.xpm'", 'r');
			exit(0);
		}
		i++;
	}
}

void	map_division_utils(t_cub3d *game, char *map_copy)
{
	int	i;
	int	j;

	i = -1;
	while (game->map_text[++i] != '\0')
	{
		if (game->map_text[i] == ' ' || game->map_text[i] == '\t')
		{
			i++;
			continue ;
		}
		if (game->map_text[i] == '\n' || game->map_text[i] == '\t')
		{
			j = i + 1;
			while (game->map_text[j] == ' ' || game->map_text[j] == '\t')
				j++;
			if (game->map_text[i + 1] == '\n' || game->map_text[j] == '\n')
			{
				color_print("map division error", 'r');
				free(map_copy);
				exit(1);
			}
		}
	}
	free(map_copy);
}

void	map_division_control(t_cub3d *game)
{
	int		i;
	int		j;
	char	*map_copy;

	map_copy = malloc(sizeof(char) * ft_strlen(game->map_text) + 1);
	i = 0;
	j = 0;
	while (game->map_text[i])
	{
		if (game->map_text[i] == 'C')
			break ;
		i++;
	}
	while (game->map_text[i] != '\n')
		i++;
	while (game->map_text[i] == '\n')
		i++;
	while (game->map_text[i] != '\0')
		map_copy[j++] = game->map_text[i++];
	free(game->map_text);
	game->map_text = ft_strtrim(map_copy, "\n");
	map_division_utils(game, map_copy);
}

void	fill_x_map(t_cub3d *game)
{
	int	x;
	int	y;
	int	len;

	x = -1;
	while (game->c_map[++x] != NULL)
	{
		y = -1;
		while (game->c_map[x][++y] != '\0')
			if (game->c_map[x][y] == ' ' || game->c_map[x][y] == '\t')
				game->c_map[x][y] = 'X';
	}
	x = 0;
	len = ft_strlen(game->c_map[0]);
	while (game->c_map[x] != NULL)
	{
		if (ft_strlen(game->c_map[x]) > len)
			len = ft_strlen(game->c_map[x]);
		x++;
	}
	game->max_size = len;
}
