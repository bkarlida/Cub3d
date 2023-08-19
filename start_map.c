/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:09:27 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/19 16:11:23 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void start_map(t_cub3d *game, char *map_name){
    int fd;
    int map_index;

    map_name_control(map_name);
    fd = file_control(game, map_name);
    game->map = file_read(game, fd);
    take_textures(game);
    map_char_control(game);
	copy_map(game);
    xpm_control(game);
    map_division_control(game);
}

void map_division_control(t_cub3d *game)
{
	int i;
	int j;
	char	*map_copy;
	
	map_copy = malloc(sizeof(char) * ft_strlen(game->map_text) + 1);

	i = 0;
	j = 0;
	while(game->map_text[i]){
		if(game->map_text[i] == 'C')
        	break;
		i++;
	}
	while(game->map_text[i] != '\n')
		i++;
	while(game->map_text[i] == '\n')
		i++;
	while(game->map_text[i] != '\0')
		map_copy[j++] = game->map_text[i++];
	free(game->map_text);
	game->map_text = ft_strtrim(map_copy, "\n");
	i = 0;
	j = 0;
	while(game->map_text[i] != '\0')
	{
		if (game->map_text[i] == ' ' || game->map_text[i] == '\t')
		{
			i++;
			continue;
		}
		if (game->map_text[i] == '\n' || game->map_text[i] == '\t')
		{
			j = i + 1;
			while (game->map_text[j] == ' ' || game->map_text[j] == '\t')
				j++;
			if (game->map_text[i + 1] == '\n' || game->map_text[j] == '\n')
			{
				color_print("map division error", 'r');
				exit(1);
			}
		}
		i++;
	}
}

