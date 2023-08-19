/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_cover.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 17:09:44 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/19 18:28:21 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void map_cover_x(t_cub3d *game) {
    int i;
    int y;

    i = 0;
    y = 0;
    while (game->c_map[i])
        i++;
    game->x_map = ft_calloc(i + 3, sizeof(char *));
    if (!game->x_map) {
        color_print("malloc error", 'y');
        exit(0);
    }
    int j = 0;
    while (j < i + 4) {
        game->x_map[j] = ft_calloc(game->max_size + 3, sizeof(char));
        if (!game->x_map[j]) {
            color_print("malloc error", 'y');
            // Önce tahsis edilen bellekleri serbest bırakmayı unutmayın.
            while (j > 0) {
                j--;
                free(game->x_map[j]);
            }
            free(game->x_map);
            return;
        }
        j++;
    }
    j = 0;
    while (j < game->max_size + 2) {
        game->x_map[0][j] = 'X';
        j++;
    }
    y = 0;
    while (game->c_map[y] != NULL) {
        char *temp = game->x_map[y + 1];
        game->x_map[y + 1] = ft_strjoin("X", game->c_map[y]);
        free(temp);
        while (game->max_size + 2 > ft_strlen(game->x_map[y + 1])) {
            temp = game->x_map[y + 1];
            game->x_map[y + 1] = ft_strjoin(game->x_map[y + 1], "X");
            free(temp);
        }
        y++;
    }
    j = 0;
    while (j < game->max_size + 2) {
        game->x_map[y + 1][j] = 'X';
        j++;
    }
    game->x_map[y + 1][game->max_size + 2] = '\0';
    game->x_map[y + 2] = NULL;
}

void map_cover_b(t_cub3d *game) {
    int i;
    int y;

    i = 0;
    y = 0;
    while (game->x_map[i])
        i++;
    game->b_map = ft_calloc(i + 3, sizeof(char *));
    if (!game->b_map) {
        color_print("malloc error", 'y');
        exit(0);
    }
    int j = 0;
    while (j < i + 4) {
        game->b_map[j] = ft_calloc(game->max_size + 7, sizeof(char));
        if (!game->b_map[j]) {
            color_print("malloc error", 'y');
            // Önce tahsis edilen bellekleri serbest bırakmayı unutmayın.
            while (j > 0) {
                j--;
                free(game->b_map[j]);
            }
            free(game->b_map);
            return;
        }
        j++;
    }
    j = 0;
    while (j < game->max_size + 4) {
        game->b_map[0][j] = 'B';
        j++;
    }
    y = 0;
    while (game->x_map[y] != NULL) {
        char *temp = game->b_map[y + 1];
        game->b_map[y + 1] = ft_strjoin("B", game->x_map[y]);
        free(temp);
        while (game->max_size + 4 > ft_strlen(game->b_map[y + 1])) {
            temp = game->b_map[y + 1];
            game->b_map[y + 1] = ft_strjoin(game->b_map[y + 1], "B");
            free(temp);
        }
        y++;
    }
    j = 0;
    while (j < game->max_size + 4) {
        game->b_map[y + 1][j] = 'B';
        j++;
    }
    game->b_map[y + 1][game->max_size + 4] = '\0';
    game->b_map[y + 2] = NULL;
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
					color_print("faulty map layout", 'r');
					exit(0);
				}
				else if(game->b_map[y][x - 1] == '0')
				{
					color_print("faulty map layout", 'r');
					exit(0);
				}
				else if(game->b_map[y + 1][x] == '0')
				{
					color_print("faulty map layout", 'r');
					exit(0);
				}
				else if(game->b_map[y - 1][x] == '0')
				{
					color_print("faulty map layout", 'r');
					exit(0);	
				}
			}
			x++;
		}
		y++;
	}
}