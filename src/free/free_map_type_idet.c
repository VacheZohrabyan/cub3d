/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_type_idet.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:00:35 by vzohraby          #+#    #+#             */
/*   Updated: 2025/11/09 17:39:48 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void free_map_type_idet(t_map* map)
{
    if (map->type_idet_NO.flag)
        if (map->type_idet_NO.type_idet_NO)
            free(map->type_idet_NO.type_idet_NO);
    if (map->type_idet_SO.flag)
        if (map->type_idet_SO.type_idet_SO)
            free(map->type_idet_SO.type_idet_SO);
    if (map->type_idet_WE.flag)
        if (map->type_idet_WE.type_idet_WE)
            free(map->type_idet_WE.type_idet_WE);
    if (map->type_idet_EA.flag)
        if (map->type_idet_EA.type_idet_EA)
            free(map->type_idet_EA.type_idet_EA);
    if (map->type_idet_F.flag)
        if (map->type_idet_F.type_idet_F)    
            free(map->type_idet_F.type_idet_F);
    if (map->type_idet_C.flag)
        if (map->type_idet_C.type_idet_C)
            free(map->type_idet_C.type_idet_C);
}