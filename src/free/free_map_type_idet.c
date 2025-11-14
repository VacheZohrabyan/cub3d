/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_info_type_idet.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:00:35 by vzohraby          #+#    #+#             */
/*   Updated: 2025/11/13 10:11:34 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void free_map_type_idet(t_map_info* map_info)
{
    if (map_info->ident.flag_NO)
        if (map_info->ident.type_ident_NO)
            free(map_info->ident.type_ident_NO);
    if (map_info->ident.flag_SO)
        if (map_info->ident.type_ident_SO)
            free(map_info->ident.type_ident_SO);
    if (map_info->ident.flag_WE)
        if (map_info->ident.type_ident_WE)
            free(map_info->ident.type_ident_WE);
    if (map_info->ident.flag_EA)
        if (map_info->ident.type_ident_EA)
            free(map_info->ident.type_ident_EA);
}