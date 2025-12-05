/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:19:47 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/04 16:17:40 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void delete_space_front(char** map_i)
{
	int end = 0;
	while ((*map_i)[end] == ' ')
		++end;
	char* tmp = ft_strdup((*map_i) + end);
	free(*map_i);
	*map_i = tmp;
}

int check_ident(char* map_i)
{
	int i = 0;
	while (map_i[i] == ' ' || map_i[i] == '\t')
		++i;

	return (!ft_strncmp(map_i + i, "F ", 2)
			|| !ft_strncmp(map_i + i, "C ", 2)
			|| !ft_strncmp(map_i + i, "NO ", 2)
			|| !ft_strncmp(map_i + i, "SO ", 3)
			|| !ft_strncmp(map_i + i, "WE ", 3)
			|| !ft_strncmp(map_i + i, "EA ", 3));
}

int allocate_map_map(int i, char** map_storage, t_map* map)
{
	int count = 0;
	while (map_storage[i])
	{
		if (map_storage[i][0] != '\0')
			++count;
		++i;
	}
	map->count = count;
	map->map = (char**)malloc(sizeof(char*) * (count + 1));
	if (!map->map)
		return (0);
	return (1);
}

int is_map_valid(t_map_info* map_info)
{
	int i = 0;
	int count = 0;
	int flag = 0;
	int map_line_count = 0;
	while (map_info->map_storage[i])
	{
		if (count == 6)
			flag = 1;
		if (!flag)
		{
			if (map_info->map_storage[i][0] == ' ')
				delete_space_front(&(map_info->map_storage[i]));
			if (check_ident(map_info->map_storage[i]))
			{
				if (!parsing_texture(map_info, map_info->map_storage[i]))
					return (printf("parsing_texture\n"), 0);
				++count;
			}
		}
		else
		{
			if (map_info->map_storage[i][0] != '\0')
			{
				if (!check_map(map_info->ident, map_info->map_storage[i]))
					return (printf("check_map\n"), 0);
				if (!map_info->map.map && !allocate_map_map(i, map_info->map_storage, &(map_info->map)))
					return (printf("allocate_map_map\n"), 0);
				map_info->map.map[map_line_count] = ft_strdup(map_info->map_storage[i]);
				if (!map_info->map.map[map_line_count])
					return (0);
				++map_line_count;
			}
		}
		++i;
	}
	map_info->map.map[map_line_count] = NULL;
	return (1);
}