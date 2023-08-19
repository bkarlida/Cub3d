/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:09:23 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/19 16:09:47 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    map_name_control(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len > 4)
	{
		if (!(map_name[len - 1] == 'b' && map_name[len - 2] == 'u' 
            && map_name[len - 3] == 'c' && map_name[len - 4] == '.'))
        {
            color_print("map name  error", 'r');
            exit(1);
        }          
	}
	else
    {
        color_print("map name  error", 'r');
        exit(1);
    }
}

int	file_control(t_cub3d *game, char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		color_print("file could not be opened", 'r');
		exit(1);
	}
	else
		return (fd);
}

char	**file_read(t_cub3d *game, int fd)
{
	char	*text;
	char	*tmp;
	char	**map;

	text = get_next_line(fd);
	if (!text)
	{
		close(fd);
		free(text);
		color_print("file is empty or could not be opened", 'r');
		exit(1);
	}
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		text = ft_strjoin(text, tmp);
		free(tmp);
	}
    game->map_text = ft_strdup(text);
	map = ft_split(text, '\n');
	free(text);
	return (map);
}

void map_char_control(t_cub3d *game)
{
    int map_index;
    int player_count;
	int i;
    
    map_index = 6;
    player_count = 0;
	while(game->map[map_index]){
		i = 0;
		while(game->map[map_index][i])
		{
            if(game->map[map_index][i] == 'N' || game->map[map_index][i] == 'S' || game->map[map_index][i] == 'W' || game->map[map_index][i] == 'E')
                player_count++;
			if(game->map[map_index][i] != '1' && game->map[map_index][i] != '0' && game->map[map_index][i] != 'N'
				&& game->map[map_index][i] != ' ' && game->map[map_index][i] != '\t' && game->map[map_index][i] != '\0' && game->map[map_index][i] != 'S' && game->map[map_index][i] != 'W' && game->map[map_index][i] != 'E')
			{
				
				color_print("map character error", 'r');
				exit(1);
			}
            
			i++;
		}
		map_index++;
	}
    if(player_count != 1)
    {
        printf("%d\n", player_count);
		color_print("player count error", 'r');
		exit(1);
	} 
}

void copy_map(t_cub3d *game){
	int i;
	int j;
	int map_index;

    map_index = 6;
	i = 0;
	j = map_index;
	while(game->map[j++])
		i++;
	game->c_map = malloc(sizeof(char *) * i + 1);
	i = 0;
	while(game->map[map_index])
	{
		game->c_map[i] = ft_strdup(game->map[map_index]);
		i++;
		map_index++;
	}
	game->c_map[i] = NULL;
}

