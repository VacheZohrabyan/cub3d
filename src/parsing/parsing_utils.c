/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:39:46 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/15 10:30:06 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// static int	find_player(char **map, int *position_i, int *position_j)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] == 'N')
// 			{
// 				*position_i = i;
// 				*position_j = j;
// 				return (1);
// 			}
// 			++j;
// 		}
// 		++i;
// 	}
// 	return (0);
// }

int	check_in_map_space_and_tab(char **map, int count)
{
	int	i;
	int	j;
	int	len_line_map;

	i = 0;
	while (i < count)
	{
		j = 0;
		len_line_map = ft_strlen(map[i]);
		while (map[i][j] && map[i][j] == ' ')
			++j;
		while (map[i][j] && map[i][j] != ' ')
			++j;
		if (j != len_line_map)
			return (0);
		++i;
	}
	return (1);
}

char	*add_one_space_and_new_allocate(char *map, int max_length)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (max_length + 1));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, map, ft_strlen(map));
	i = ft_strlen(map);
	while (i < max_length)
	{
		tmp[i] = ' ';
		++i;
	}
	i = 0;
	while (tmp && i < max_length)
	{
		if (tmp[i] != '0' && tmp[i] != '1' && tmp[i] != 'N'
			&& tmp[i] != 'S' && tmp[i] != 'W' && tmp[i] != 'E')
			tmp[i] = '1';
		++i;
	}
	tmp[i] = '\0';
	free(map);
	return (tmp);
}

int	add_one_to_space(t_map *map)
{
	int	max_length_map_line;
	int	i;

	i = 1;
	max_length_map_line = ft_strlen(map->map[0]);
	map->len = max_length_map_line;
	while (map->map[i])
	{
		if (max_length_map_line < (int)ft_strlen(map->map[i]))
			max_length_map_line = ft_strlen(map->map[i]);
		++i;
	}
	i = 0;
	while (map->map[i])
	{
		if (max_length_map_line >= (int)ft_strlen(map->map[i]))
		{
			map->map[i] = add_one_space_and_new_allocate(
					(map->map[i]), max_length_map_line);
			if (!map->map[i])
				return (0);
		}
		++i;
	}
	return (1);
}
