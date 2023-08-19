/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 13:09:26 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/19 13:14:32 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void color_print(char *msg, char color){
    if(color == 'r')
        printf(RED "%s\n" RESET, msg);
    else if(color == 'g')
        printf(GREEN "%s\n" RESET, msg);
    else if(color == 'y')
        printf(YELLOW "%s\n" RESET, msg);
}

