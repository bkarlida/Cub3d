/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultimate_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muerdoga <muerdoga@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:36:16 by muerdoga          #+#    #+#             */
/*   Updated: 2023/08/14 14:06:53 by muerdoga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ultimate_print(char *str, char c, t_cub3d *game)
{
    if(c == 'r')
        printf(RED "%s\n" RESET, str);
    else if(c == 'g')
        printf(GREEN "%s\n" RESET, str);
    else if(c == 'y')
        printf(YELLOW "%s\n" RESET, str);
}