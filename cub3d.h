/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:32:17 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/16 12:40:24 by bkarlida         ###   ########.fr       */
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

//mlx resim için
typedef struct s_img{
    void    *window;
    int     *image;
    char    *data;
    int     bpp; 
    int     sizeline;
    int     endian; 
}   t_img;


//yer ve gök renk kodları
typedef struct s_color{
    int r;
    int g;
    int b;
    int use;
}   t_color;

typedef struct s_texture{
    char    *path;
    int     use;

    
}   t_texture;


//genel oyun kuralları
typedef struct s_cub3d{
    t_img   img;    
    void    *mlx;
    char    **map;
    char    **c_map;
    char    **x_map;
    char    **b_map;
	char 	*map_text;
    int		max_size;
    t_texture   north;
    t_texture   south;
    t_texture   west;
    t_texture   east;
    t_color     sky;
    t_color     floor;
}   t_cub3d;

//malx
void    start_mlx(t_cub3d *game);
void    start_img(t_cub3d *game);

//utils
void    ultimate_print(char *str, char c, t_cub3d *game);
void	start_cub3d(t_cub3d *game);

//map
void    start_map(t_cub3d *game, char *map_name);
int     map_name_control(char *map_name);
int     file_control(t_cub3d *game, char *map_name);
char    **file_read(t_cub3d *game, int fd);
int     start_textures(t_cub3d *game);
int     extract_data(t_cub3d *game, int i);
int     texture_path(t_cub3d *game, int i, char *key, char **path);
int     take_color_number(t_cub3d *game, t_color *color, char *str);
int     take_color(t_cub3d *game, int i, char *key, t_color *color);
void    map_write(t_cub3d *game);
void    copy_map(t_cub3d *game, int map_index);
void 	fill_X_map(t_cub3d *game);
void	map_add_x(t_cub3d *game);
void	map_add_b(t_cub3d *game);
void    map_x_control(t_cub3d *game);
void	map_char_control(t_cub3d *game, int map_index);
void    xpm_control(t_cub3d *game);
void	name_xpm(t_cub3d *game);


#endif