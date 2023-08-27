/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 21:03:13 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/27 13:44:46 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void start_mlx(t_cub3d *game){
    open_textures(game);
}

void start_img(t_cub3d *game){
    int bpp;
    int sizeline;
    int endian;

    game->img.image = mlx_new_image(game->mlx, 800, 600);
    game->img.data = mlx_get_data_addr(game->img.image, &bpp, &sizeline, &endian);
    game->img.bpp = bpp;
    game->img.sizeline = sizeline;
    game->img.endian = endian;
}