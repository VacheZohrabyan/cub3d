/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:28:05 by vzohraby          #+#    #+#             */
/*   Updated: 2025/11/14 16:04:23 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int check_ident_full(t_ident ident)
{
    if (!ident.flag_NO)
        return (0);
    if (!ident.flag_SO)
        return (0);
    if (!ident.flag_WE)
        return (0);
    if (!ident.flag_EA)
        return (0);
    if (!ident.flag_C)
        return (0);
    if (!ident.flag_F)
        return (0);
    return (1);
}

int check_map(char* map_i)
{
    printf("map = %s\n", map_i);
    int i = 0;
    while (map_i[i] == ' ')
        ++i;
    if (map_i[i] == 'F' || map_i[i] == 'C'
        || !ft_strncmp(map_i + i, "NO", 2) || !ft_strncmp(map_i + i, "SO", 2)
        || !ft_strncmp(map_i + i, "WE", 2) || !ft_strncmp(map_i + i, "EA", 2))
        return (0);
    while (map_i[i])
    {
        if (map_i[i] != '1' && map_i[i] != '0' && map_i[i] != 'N' && map_i[i] != 'S' && map_i[i] != 'E' && map_i[i] != 'W' && map_i[i] != ' ')
            return (0);
        ++i;   
    }
    return (1);
}