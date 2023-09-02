/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cover.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:09:44 by muerdoga          #+#    #+#             */
/*   Updated: 2023/09/02 15:38:31 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_cover_x_utils(t_cub3d *game, char *temp, int *y)
{
	int	j;

	*y = 0;
	while (game->c_map[*y] != NULL)
	{
		temp = game->x_map[*y + 1];
		game->x_map[*y + 1] = ft_strjoin("X", game->c_map[*y]);
		free(temp);
		while (game->max_size + 2 > ft_strlen(game->x_map[*y + 1]))
		{
			temp = game->x_map[*y + 1];
			game->x_map[*y + 1] = ft_strjoin(game->x_map[*y + 1], "X");
			free(temp);
		}
		(*y)++;
	}
	j = 0;
	while (j < game->max_size + 2)
		game->x_map[*y + 1][j++] = 'X';
	game->x_map[*y + 1][game->max_size + 2] = '\0';
	game->x_map[*y + 2] = NULL;
}

void	map_cover_x_calloc(t_cub3d *game, int *i)
{
	int	j;

	j = -1;
	while (++j < *i + 4)
	{
		game->x_map[j] = ft_calloc(game->max_size + 3, sizeof(char));
		if (!game->x_map[j])
		{
			color_print("malloc error", 'y');
			while (j-- > 0)
				free(game->x_map[j]);
			free(game->x_map);
			exit(0);
		}
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
	map_cover_x_calloc(game, &i);
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
	while (++j < game->max_size + 4)
		game->b_map[y + 1][j] = 'B';
	game->b_map[y + 1][game->max_size + 4] = '\0';
	game->b_map[y + 2] = NULL;
	double_free(game->x_map);
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
	while (++j < i + 4)
	{
		game->b_map[j] = ft_calloc(game->max_size + 7, sizeof(char));
		if (!game->b_map[j])
		{
			color_print("malloc error", 'y');
			while (j-- > 0)
				free(game->b_map[j]);
			free(game->b_map);
			return ;
		}
	}
	map_cover_b_utils(game, temp);
}
