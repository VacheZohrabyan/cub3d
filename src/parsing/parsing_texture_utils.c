/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:51:29 by vzohraby          #+#    #+#             */
/*   Updated: 2025/11/13 13:57:30 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void init_ident_color_C(char* map_i, int i, t_ident* ident)
{
    char** number = ft_split(map_i + i, ',');
    ident->type_ident_C.red = ft_atoi(number[0]);
    ident->type_ident_C.green = ft_atoi(number[1]);
    ident->type_ident_C.blue = ft_atoi(number[2]);
    ident->flag_C = 1;
    free_split(number);
}

void init_ident_color_F(char* map_i, int i, t_ident* ident)
{
    char** number = ft_split(map_i + i, ',');
    ident->type_ident_F.red = ft_atoi(number[0]);
    ident->type_ident_F.green = ft_atoi(number[1]);
    ident->type_ident_F.blue = ft_atoi(number[2]);
    ident->flag_F = 1;
    free_split(number);
}

void init_ident_color(char* map_i, int i, t_ident* ident, char type)
{
    if (type == 'C')
        init_ident_color_C(map_i, i, ident);
    else
        init_ident_color_F(map_i, i, ident);
}

