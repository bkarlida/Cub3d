/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:32:17 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/19 15:01:07 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

#include <stdio.h>
#include "./libft/libft.h"
#include "./gnl/get_next_line.h"
#include <fcntl.h>
#include "minilbx/mlx.h"

typedef struct s_img{
	void    *window;
	int     *image;
	char    *data;
	int     bpp; 
	int     sizeline;
	int     endian; 
}   t_img;

typedef struct s_color{
	int r;
	int g;
	int b;
	int use;
}   t_color;

typedef struct s_texture{
	void    *image;
	char    *path;
	char    *data;
	int     use;
	int     w;
	int     h;
	int     bpp;
	int     sizeline;
	int     endian;    
}   t_texture;

typedef struct s_player{
	double  x;
	double  y;
	double  dir_x;
	double  dir_y;
	double  speed;
	double  rot_speed;

} t_player;


//genel oyun kuralları
typedef struct s_cub3d{
	t_img       img; 
	   
	void        *mlx;
	char        **map;
	int		    max_size;
	int         move[6];
	
	char        **c_map;
	char		*map_text;
	
	t_texture   north;
	t_texture   south;
	t_texture   west;
	t_texture   east;
	t_color     sky;
	t_color     floor;
	t_player    player;
}   t_cub3d;

//Map
void    start_map(t_cub3d *game, char *map_name);
void    map_name_control(char *map_name);
int     file_control(t_cub3d *game, char *map_name);
char    **file_read(t_cub3d *game, int fd);
void    take_textures(t_cub3d *game);
int     extract_data(t_cub3d *game, int i);
int     texture_path(t_cub3d *game, int i, char *key, char **path);
int     take_color(t_cub3d *game, int i, char *key, t_color *color);
int     take_color_number(t_cub3d *game, t_color *color, char *str);
void    map_char_control(t_cub3d *game);
void	copy_map(t_cub3d *game);
void	xpm_control(t_cub3d *game);
void	name_xpm(t_cub3d *game);
void	map_division_control(t_cub3d *game);

//Tool
void    start_game(t_cub3d *game);
void    color_print(char *msg, char color);


//Mlx






#endif