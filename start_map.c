/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:22:18 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/16 17:07:20 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_map(t_cub3d *game, char *map_name)
{
	int	fd;
	int	map_index;

	if (map_name_control(map_name))
	{
		ultimate_print("wrong map name", 'r', game);
		exit(1);
	}
	fd = file_control(game, map_name);
	game->map = file_read(game, fd);
	map_index = start_textures(game);
	map_char_control(game, map_index);
	copy_map(game, map_index);
	fill_X_map(game);
	map_add_x(game);
	map_add_b(game);
	map_x_control(game);
	xpm_control(game);
	open_textures(game);
	int i = 0;
	while(game->x_map[i]){
		printf("%s\n", game->x_map[i]);
		i++;
	}
	//Map ikiye bölünme controlü yapılacak
}

void	open_textures(t_cub3d *game)
{
	game->north.image = mlx_xpm_file_to_image(game->mlx, game->north.path, &(game->north.w), &(game->north.h));
	game->south.image = mlx_xpm_file_to_image(game->mlx, game->south.path, &(game->south.w), &(game->south.h));
	game->west.image = mlx_xpm_file_to_image(game->mlx, game->west.path, &(game->west.w), &(game->west.h));
	game->east.image = mlx_xpm_file_to_image(game->mlx, game->east.path, &(game->east.w), &(game->east.h));
	if(!game->north.image || !game->south.image || !game->west.image || !game->east.image)
		ultimate_print("Texture error" , 'r', game);
	//Resimler destory edilecek path free yapılacak
	game->north.data = mlx_get_data_addr(game->north.image, &(game->north.bpp), &(game->north.sizeline), &(game->north.endian));
	game->south.data = mlx_get_data_addr(game->south.image, &(game->south.bpp), &(game->south.sizeline), &(game->south.endian));
	game->west.data = mlx_get_data_addr(game->west.image, &(game->west.bpp), &(game->west.sizeline), &(game->west.endian));
	game->east.data = mlx_get_data_addr(game->east.image, &(game->east.bpp), &(game->east.sizeline), &(game->east.endian));	
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
			ultimate_print("extension error '.xpm'", 'r', game);
			exit(0);
		}
		i++;
	}
}

void xpm_control(t_cub3d *game)
{
	int *fd;
	int i;
	
	fd = malloc(100);
	i = 0;
	fd[0] = open(game->north.path, O_RDONLY);
	fd[1] = open(game->south.path, O_RDONLY);
	fd[2] = open(game->west.path, O_RDONLY);
	fd[3] = open(game->east.path, O_RDONLY);

	while(i < 4){
		if(fd[i] == -1)
		{
			ultimate_print("textures not open", 'r', game);
			exit(1);
		}
		i++;
	}
	name_xpm(game);
}

void map_char_control(t_cub3d *game, int map_index)
{
	int i = 0;
	while(game->map[map_index]){
		i = 0;
		while(game->map[map_index][i])
		{
			if(game->map[map_index][i] != '1' && game->map[map_index][i] != '0' && game->map[map_index][i] != 'N'
				&& game->map[map_index][i] != ' ' && game->map[map_index][i] != '\0' && game->map[map_index][i] != 'S' && game->map[map_index][i] != 'W' && game->map[map_index][i] != 'E')
			{
				
				ultimate_print("map character error", 'r', game);
				exit(1);
			}
			i++;
		}
		map_index++;
	}
}

void map_x_control(t_cub3d *game){
	int x;
	int y;
	y = 0;
	while(game->b_map[y] != NULL){
		x = 0;
		while(game->b_map[y][x] != '\0'){
			if(game->b_map[y][x] == 'X'){
				if(game->b_map[y][x + 1] == '0')
				{
					ultimate_print("faulty map layout", 'r', game);
					exit(0);
				}
				else if(game->b_map[y][x - 1] == '0')
				{
					ultimate_print("faulty map layout", 'r', game);
					exit(0);
				}
				else if(game->b_map[y + 1][x] == '0')
				{
					ultimate_print("faulty map layout", 'r', game);
					exit(0);
				}
				else if(game->b_map[y - 1][x] == '0')
				{
					ultimate_print("faulty map layout", 'r', game);
					exit(0);	
				}
			}
			x++;
		}
		y++;
	}
}

void fill_X_map(t_cub3d *game){
	int x = 0;
	int y = 0;
	int len;
	
	while(game->c_map[x] != NULL){
		y = 0;
		while(game->c_map[x][y] != '\0'){
			if(game->c_map[x][y] == ' ')
				game->c_map[x][y] =  'X';
			y++;
		}
		x++;
	}

	x = 0;
	len = ft_strlen(game->c_map[0]);
	while(game->c_map[x] != NULL){
		if(ft_strlen(game->c_map[x]) > len)
			len = ft_strlen(game->c_map[x]);
		x++;
	}
	game->max_size = len;
}
void	map_add_x(t_cub3d *game)
{
	int i;

	i = 0;
	while (game->c_map[i])
		i++;
	game->x_map = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (game->c_map[i])
	{
		game->x_map[i] = malloc(sizeof(char) * game->max_size);	
		i++;
	}
	i = 0;
	while(game->max_size + 2 > i)
		game->x_map[0][i++] = 'X';
	int y = 0;
	while (game->c_map[y] != NULL)
	{
		game->x_map[y + 1] = ft_strjoin("X", game->c_map[y]);
		while (game->max_size + 2 > ft_strlen(game->x_map[y + 1]))
			game->x_map[y + 1] = ft_strjoin(game->x_map[y + 1], "X");
		y++;
	}
	i = 0;
	while(game->max_size + 2 > i)
		game->x_map[y][i++] = 'X';
}

void	map_add_b(t_cub3d *game)
{
	int i;
	int y = 0;

	i = 0;
	while (game->x_map[i])
		i++;
	game->b_map = malloc(sizeof(char *) * (i + 4));
	i = 0;
	while (game->x_map[i])
		game->b_map[i++] = malloc(sizeof(char) * game->max_size);	
	i = 0;
	while(game->max_size + 4 > i)
		game->b_map[0][i++] = 'B';
	while (game->x_map[y] != NULL)
	{
		//printf("%s\n", game->x_map[y]);
		game->b_map[y + 1] = ft_strjoin("B", game->x_map[y]);
		while (game->max_size + 4 > ft_strlen(game->b_map[y + 1]))
		{
			game->b_map[y + 1] = ft_strjoin(game->b_map[y + 1], "B");
		}
		y++;
	}
	i = 0;
	while(game->max_size + 4 > i)
		game->b_map[y][i++] = 'B';
}

void copy_map(t_cub3d *game, int map_index){
	int i;
	int j;
	
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

int	map_name_control(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len > 4)
	{
		if (map_name[len - 1] == 'b' && map_name[len - 2] == 'u' 
            && map_name[len - 3] == 'c' && map_name[len - 4] == '.')
			return (0);
		return (1);
	}
	else
		return (1);
}

int	file_control(t_cub3d *game, char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ultimate_print("file could not be opened", 'r', game);
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
		ultimate_print("file is empty or could not be opened", 'r', game);
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
	game->map_text = text;
	map = ft_split(text, '\n');
	free(text);
	return (map);
}

