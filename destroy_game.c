/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 17:57:36 by muerdoga          #+#    #+#             */
/*   Updated: 2023/09/02 11:42:07 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	double_free(char **game)
{
	int	i;

	i = 0;
	if (game)
	{
		while (game[i])
			free(game[i++]);
		free(game);
	}
}

void	free_tex_paths_2(t_cub3d *game)
{
	if (game->north.path)
		free(game->north.path);
	if (game->south.path)
		free(game->south.path);
	if (game->west.path)
		free(game->west.path);
	if (game->east.path)
		free(game->east.path);
}

void	free_map(t_cub3d *game, char **map)
{
	(void)map;
	free_tex_paths_2(game);
}
