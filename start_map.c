/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:09:27 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/19 18:28:51 by muerdoga         ###   ########.fr       */
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
	fill_x_map(game);
	map_cover_x(game);
	map_cover_b(game);
	map_x_control(game);
	
}

