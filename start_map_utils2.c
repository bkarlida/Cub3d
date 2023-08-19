/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:43:47 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/19 14:44:21 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void xpm_control(t_cub3d *game)
{
	int *fd;
	int i;
	
	fd = malloc(sizeof(int) * 4);
	i = 0;
	fd[0] = open(game->north.path, O_RDONLY);
	fd[1] = open(game->south.path, O_RDONLY);
	fd[2] = open(game->west.path, O_RDONLY);
	fd[3] = open(game->east.path, O_RDONLY);

	while(i < 4){
		if(fd[i] == -1)
		{
			color_print("textures not open", 'r');
			exit(1);
		}
		i++;
	}
	name_xpm(game);
}

void	name_xpm(t_cub3d *game)
{
	int i;
	int len;

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