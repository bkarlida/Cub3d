/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:09:20 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/19 13:19:21 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av){
    t_cub3d *game;

    if(ac == 2){
        game = malloc(sizeof(t_cub3d));
        start_game(game);
        start_map(game, av[1]);
    }
    else{
        color_print("number of erroneous parameters", 'r');
    }
}

void start_game(t_cub3d *game){
    game->map = NULL;
    
    game->north.path = NULL;
    game->south.path = NULL;
    game->east.path = NULL;
    game->west.path = NULL;

    game->north.use = 0;
    game->south.use = 0;
    game->east.use = 0;
    game->west.use = 0;
    game->floor.use = 0;
    game->sky.use = 0;
}