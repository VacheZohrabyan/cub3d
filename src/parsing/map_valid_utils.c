/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:18:20 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/07 17:25:00 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	add_line_map_map(t_map_info *map_info, int *map_line_count, int i)
{
	if (!check_map(map_info->ident, map_info->map_storage[i]))
		return (printf("check_map\n"), 0);
	if (!map_info->map.map && !allocate_map_map(
			i, map_info->map_storage, &(map_info->map)))
		return (printf("allocate_map_map\n"), 0);
	map_info->map.map[*map_line_count]
		= ft_strdup(map_info->map_storage[i]);
	if (!map_info->map.map[*map_line_count])
		return (0);
	++(*map_line_count);
	return (1);
}

int	add_line_texture(t_map_info *map_info, int i, int *count)
{
	if (map_info->map_storage[i][0] == ' ')
		delete_space_front(&(map_info->map_storage[i]));
	if (check_ident(map_info->map_storage[i]))
	{
		if (!parsing_texture(map_info, map_info->map_storage[i]))
			return (printf("parsing_texture\n"), 0);
		++(*count);
	}
	return (1);
}

int	loop_map_storage(t_map_info *map_info, int map_line_count, int i)
{
	int	count;
	int	flag;

	count = 0;
	flag = 0;
	while (map_info->map_storage[i])
	{
		if (count == 6)
			flag = 1;
		if (!flag)
		{
			if (!add_line_texture(map_info, i, &count))
				return (printf("add_line_texture\n"), 0);
		}
		else
		{
			if (map_info->map_storage[i][0] != '\0')
				if (!add_line_map_map(map_info, &map_line_count, i))
					return (0);
		}
		++i;
	}
	map_info->map.map[map_line_count] = NULL;
	return (1);
}
