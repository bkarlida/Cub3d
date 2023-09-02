/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cover.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:09:44 by muerdoga          #+#    #+#             */
/*   Updated: 2023/09/02 20:07:57 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_cover_x_utils(t_cub3d *game, char *temp, int *y)
{
	int	j;

	*y = 0;
	while (game->c_map[*y] != NULL)
	{
		game->x_map[*y + 1] = ft_strjoin("X", game->c_map[*y]);
		while (game->max_size + 2 > ft_strlen(game->x_map[*y + 1]))
		{
			temp = game->x_map[*y + 1];
			game->x_map[*y + 1] = ft_strjoin(game->x_map[*y + 1], "X");
			free(temp);
		}
		(*y)++;
	}
	j = 0;
	game->x_map[*y + 1] = malloc(game->max_size + 4);
	while (j < game->max_size + 2)
	{
		temp = game->x_map[*y + 1];
		game->x_map[*y + 1] = ft_strjoin(game->x_map[*y + 1], "X");
		free(temp);
		j++;
	}
}

void	map_cover_x(t_cub3d *game)
{
	int		i;
	int		y;
	int		j;
	char	*temp;

	i = 0;
	y = 0;
	while (game->c_map[i])
		i++;
	game->x_map = ft_calloc(i + 3, sizeof(char *));
	if (!game->x_map)
	{
		color_print("malloc error", 'y');
		exit(0);
	}
	game->x_map[0] = ft_calloc(game->max_size + 3, sizeof(char));
	j = 0;
	while (j < game->max_size + 2)
		game->x_map[0][j++] = 'X';
	map_cover_x_utils(game, temp, &y);
}

void	map_cover_b_utils(t_cub3d *game, char *temp)
{
	int	j;
	int	y;

	j = 0;
	while (j < game->max_size + 4)
		game->b_map[0][j++] = 'B';
	y = -1;
	while (game->x_map[++y] != NULL)
	{
		temp = game->b_map[y + 1];
		game->b_map[y + 1] = ft_strjoin("B", game->x_map[y]);
		free(temp);
		while (game->max_size + 4 > ft_strlen(game->b_map[y + 1]))
		{
			temp = game->b_map[y + 1];
			game->b_map[y + 1] = ft_strjoin(game->b_map[y + 1], "B");
			free(temp);
		}
	}
	j = -1;
	game->b_map[y + 1] = malloc(game->max_size + 5);
	while (++j < game->max_size + 4)
		game->b_map[y + 1][j] = 'B';
	game->b_map[y + 1][game->max_size + 4] = '\0';
}

void	map_cover_b(t_cub3d *game)
{
	int		i;
	int		y;
	int		j;
	char	*temp;

	i = 0;
	y = 0;
	while (game->x_map[i])
		i++;
	game->b_map = ft_calloc(i + 3, sizeof(char *));
	j = -1;
	game->b_map[0] = ft_calloc(game->max_size + 7, sizeof(char));
	map_cover_b_utils(game, temp);
}
