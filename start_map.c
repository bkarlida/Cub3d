/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:09:27 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/19 15:09:15 by muerdoga         ###   ########.fr       */
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
    //map_division_control(game);
}

void map_division_control(t_cub3d *game)
{
   int i;

   i = 0;
	while(game->map_text[i]){
		if(game->map_text[i] == 'C')
        	break;
		i++;
	}
	while(game->map_text[i] != '\n')
		i++;
	while(game->map_text[i] == '\n')
		i++;
	printf("%d\n", i);
	while(game->map_text[i] != '\0')
		printf("%c", game->map_text[i++]);

}

