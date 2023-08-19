/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:01:55 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/19 21:12:08 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	open_textures(t_cub3d *game)
{
	game->north.image = mlx_xpm_file_to_image(game->mlx, game->north.path, &(game->north.w), &(game->north.h));
	game->south.image = mlx_xpm_file_to_image(game->mlx, game->south.path, &(game->south.w), &(game->south.h));
	game->west.image = mlx_xpm_file_to_image(game->mlx, game->west.path, &(game->west.w), &(game->west.h));
	game->east.image = mlx_xpm_file_to_image(game->mlx, game->east.path, &(game->east.w), &(game->east.h));
	if(!game->north.image || !game->south.image || !game->west.image || !game->east.image)
		color_print("Texture error" , 'r');
	game->north.data = mlx_get_data_addr(game->north.image, &(game->north.bpp), &(game->north.sizeline), &(game->north.endian));
	game->south.data = mlx_get_data_addr(game->south.image, &(game->south.bpp), &(game->south.sizeline), &(game->south.endian));
	game->west.data = mlx_get_data_addr(game->west.image, &(game->west.bpp), &(game->west.sizeline), &(game->west.endian));
	game->east.data = mlx_get_data_addr(game->east.image, &(game->east.bpp), &(game->east.sizeline), &(game->east.endian));	
    
}