/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_valid_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:42:10 by vzohraby          #+#    #+#             */
/*   Updated: 2026/01/05 17:51:28 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_len_map(char **map)
{
	int	count;

	count = 0;
	while (map[count++])
		;
	return (count);
}

static int	find_player(char **map, int *position_i, int *position_j)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
			{
				*position_i = i;
				*position_j = j;
				return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

int	check_other_player(char **map)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'W' || map[i][j] == 'E')
				++count;
			++j;
		}
		++i;
	}
	return (count == 1);
}

int	parsing_valid_map(t_map *map)
{
	int	position_i;
	int	position_j;

	position_i = -1;
	position_j = -1;
	if (!check_other_player(map->map))
		return (printf("to many player\n"), 0);
	if (!find_player(map->map, &position_i, &position_j))
		return (printf("no player\n"), 0);
	if (!floot_fill_recur(map, position_i, position_j))
		return (printf("floot_fill_recur\n"), 0);
	if (!add_one_to_space(map))
		return (printf("add_one_to_space\n"), 0);
	if (!map->map)
		return (printf("map->map"), 0);
	if (!check_side_up_down(map->map, map->count_of_line))
		return (printf("check_side_up_down\n"), 0);
	if (!check_in_map_space_and_tab(map->map, map->count_of_line))
		return (printf("check_in_map_space_and_tab\n"), 0);
	return (1);
}
