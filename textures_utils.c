/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:36:10 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/19 13:51:53 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void take_textures(t_cub3d *game){
    int i;
    int counter;

    i = 0;
    counter = 0;
    while(game->map[i] && ft_strnstr(game->map[i], "1111" , 5) == NULL){
        if(ft_strlen(game->map[i]) > 3)
            counter += extract_data(game, i);
        i++;
    }
    if(!(counter == 6 && game->map[i])){
        color_print("map content is incorrect", 'r');
        exit(1);
    }
}

int extract_data(t_cub3d *game, int i){
    if (texture_path(game, i, "NO", &game->north.path) == 1 && game->north.use == 0)
    {
        game->north.use = 1;   
        return (1);
    }
    else if(texture_path(game, i, "SO", &game->south.path) == 1 && game->south.use == 0)
    {
        game->south.use = 1;   
        return (1);
    }
    else if(texture_path(game, i, "EA", &game->east.path) == 1 && game->east.use == 0)
        {
        game->east.use = 1;   
        return (1);
    }
    else if(texture_path(game, i, "WE", &game->west.path) == 1 && game->west.use == 0)
        {
        game->west.use = 1;   
        return (1);
    }
    else if(take_color(game, i, "F", &game->floor) == 1 && game->floor.use == 0)
        {
        game->floor.use = 1;   
        return (1);
    }
    else if(take_color(game, i, "C", &game->sky) == 1 && game->sky.use == 0)
        {
        game->sky.use = 1;   
        return (1);
    }
    else{
        return (10);
    }
}

int texture_path(t_cub3d *game, int i, char *key, char **path){
    char	*str;

	if (ft_strnstr(game->map[i], key, 4) == game->map[i]
		&& ft_strnstr(game->map[i], key, 4)[2] == ' ')
	{
		str = ft_strnstr(game->map[i], key, 4) + 2;
		while (*str >= 9 && *str <= 13 || *str == ' ')
			str++;
		if (ft_isprint(*str))
		{
            *path = malloc(sizeof(char *) * (ft_strlen(str) + 1));
			ft_strlcpy(*path, str, (ft_strlen(str) + 1));
			return (1);
		}
	}
	return (0);
}

int take_color(t_cub3d *game, int i, char *key, t_color *color){
    char    *str;

    if(ft_strnstr(game->map[i], key, 2) == game->map[i]
		&& ft_strnstr(game->map[i], key, 4)[1] == ' ')
	{
        str = ft_strnstr(game->map[i], key, 2) + 1;
        while((*str >= 9 && *str <= 13 )|| *str == ' ')
            str++;
        return take_color_number(game, color, str);         
    }
    return (0);
}

int take_color_number(t_cub3d *game, t_color *color, char *str){
    int i;
    int j;
    
    char **rgb;
    i = 0;
    j = 0;
    rgb = ft_split(str, ',');
    while(rgb[i]){
        if(ft_atoi(rgb[i]) >= 0 && ft_atoi(rgb[i]) <= 255)
            j++;
        i++;
    }
    if(j == 3)
    {
        color->r = ft_atoi(rgb[0]);
        color->g = ft_atoi(rgb[1]);  
        color->b = ft_atoi(rgb[2]);
    }
    else{
        i = 0;
        while(rgb[i]){
            free(rgb[i]);
            i++;
        }
        free(rgb);
        return (0);
    }
    i = 0;
    while(rgb[i]){
        free(rgb[i]);
        i++;
    }
    free(rgb);
    return (1);
}