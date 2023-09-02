/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:09:26 by muerdoga          #+#    #+#             */
/*   Updated: 2023/09/02 13:32:55 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	color_print(char *msg, char color)
{
	if (color == 'r')
		printf(RED "%s\n" RESET, msg);
	else if (color == 'g')
		printf(GREEN "%s\n" RESET, msg);
	else if (color == 'y')
		printf(YELLOW "%s\n" RESET, msg);
}

void	color_print_exit(char *msg, char color)
{
	if (color == 'r')
		printf(RED "%s\n" RESET, msg);
	else if (color == 'g')
		printf(GREEN "%s\n" RESET, msg);
	else if (color == 'y')
		printf(YELLOW "%s\n" RESET, msg);
	exit(0);
}

void	map_height(t_cub3d *game)
{
	game->map_he = 0;
	while (game->b_map[game->map_he] != NULL)
		game->map_he++;
}

int	is_user_char(int c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

void	copy_map(t_cub3d *game)
{
	int	i;
	int	j;
	int	map_index;

	map_index = 6;
	i = 0;
	j = map_index;
	while (game->map[j++])
		i++;
	game->c_map = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (game->map[map_index])
	{
		game->c_map[i] = ft_strdup(game->map[map_index]);
		i++;
		map_index++;
	}
	game->c_map[i] = NULL;
}
