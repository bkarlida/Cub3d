/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkarlida <bkarlida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 12:32:17 by muerdoga          #+#    #+#             */
/*   Updated: 2023/09/02 20:10:38 by bkarlida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define WIDTH 800
# define HEIGHT 600
# define TEX_W 64
# define TEX_H 64
# define PI 3.141592653589793

# include <stdio.h>
# include "./libft/libft.h"
# include "./gnl/get_next_line.h"
# include <fcntl.h>
# include "minilbx/mlx.h"
# include <math.h>
# include <string.h>

typedef struct s_img{
	void	*window;
	int		*image;
	char	*data;
	int		bpp; 
	int		sizeline;
	int		endian; 
}	t_img;

typedef struct s_color{
	int	r;
	int	g;
	int	b;
	int	use;
}	t_color;

typedef struct s_texture{
	void	*image;
	char	*path;
	char	*data;
	int		use;
	int		w;
	int		h;
	int		bpp;
	int		sizeline;
	int		endian;
}	t_texture;

typedef struct s_player{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	speed;
	double	rot_speed;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_cub3d{
	t_img		img;
	void		*mlx;
	void		*gun1;
	void		*gun2;
	void		*gun3;
	void		*gun4;
	char		**map;
	int			max_size;
	int			move[6];
	int			loc_x;
	int			loc_y;
	int			m_old_pos_y;
	int			m_old_pos_x;
	int			lock;
	int			x;
	int			gun_w;
	int			gun_h;
	int			gun_flag;
	int			y;
	double		wall_x;
	double		tex_x;
	double		step;
	double		tex_pos;
	int			draw_start;
	int			draw_end;
	int			line_height;
	double		camera_x;
	double		scale;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			map_wd;
	int			map_he;
	double		perp_wall_dist;
	char		**c_map;
	char		**x_map;
	char		**b_map;
	char		*map_text;
	t_texture	north;
	t_texture	south;
	t_texture	west;
	t_texture	east;
	t_color		sky;
	t_color		floor;
	t_player	player;
}	t_cub3d;

void			start_map(t_cub3d *game, char *map_name);
void			map_name_control(char *map_name);
int				file_control(t_cub3d *game, char *map_name);
char			**file_read(t_cub3d *game, int fd);
void			take_textures(t_cub3d *game);
int				extract_data(t_cub3d *game, int i);
int				texture_path(t_cub3d *game, int i, char *key, char **path);
int				take_color(t_cub3d *game, int i, char *key, t_color *color);
int				take_color_number(t_cub3d *game, t_color *color, char *str);
void			map_char_control(t_cub3d *game);
void			copy_map(t_cub3d *game);
void			xpm_control(t_cub3d *game);
void			name_xpm(t_cub3d *game);
void			map_division_control(t_cub3d *game);
void			fill_x_map(t_cub3d *game);
void			map_cover_x(t_cub3d *game);
void			map_cover_b(t_cub3d *game);
void			map_x_control(t_cub3d *game);
void			start_game(t_cub3d *game);
void			color_print(char *msg, char color);
void			start_mlx(t_cub3d *game);
void			open_textures(t_cub3d *game);
void			start_img(t_cub3d *game);
int				x_close(int keycode, t_cub3d *game);
int				key_press(int key_code, t_cub3d *game);
int				key_release(int key_code, t_cub3d *game);
void			start_img(t_cub3d *game);
int				ft_game_loop(t_cub3d *game);
void			player_move(t_cub3d *game);
void			game_arithmetic(t_cub3d *game);
void			calc_texture_pixel_color(t_cub3d *game);
void			print_player(t_cub3d *game, int x, int y, double scale);
void			print_mini_map(t_cub3d *game);
void			put_px_img(t_cub3d *f, int x, int y, int color);
int				create_trgb(int t, int r, int g, int b);
unsigned int	get_pixel_in_tex(t_texture tex, int x, int y);
void			rotate_with_mouse(t_cub3d *game);
void			rotate_left(t_cub3d *game);
void			rotate_right(t_cub3d *game);
void			draw_pause(t_cub3d *game);
void			find_player(t_cub3d *game);
void			player_first_rotate(t_cub3d *game);
void			free_map(t_cub3d *game, char **map);
void			double_free(char **game);
void			map_height(t_cub3d *game);
void			color_print_exit(char *msg, char color);
int				is_user_char(int c);
void			map_char_control(t_cub3d *game);
void			map_char_control_utils(t_cub3d *g, int *m, int *i, int *c);
void			gun_show(t_cub3d *game);
#endif