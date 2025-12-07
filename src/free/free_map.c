/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 10:29:41 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/06 13:05:28 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_map(t_map_info *map_info)
{
	int	i;

	if (map_info->map_storage)
	{
		i = 0;
		while (map_info->map_storage[i])
			free(map_info->map_storage[i++]);
		free(map_info->map_storage);
	}
	free_map_type_idet(&(map_info->ident));
	free_map_map(map_info->map.map);
}
