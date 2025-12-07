/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_valid_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:42:10 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/06 13:45:07 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// int	check_line(char *map_i)
// {
// 	int	i;

// 	i = 0;
// 	while (map_i[i] == ' ')
// 		++i;
// 	if (map_i[i] != 1 || map_i[ft_strlen(map_i) - 1] != 1)
// 	{
// 		printf("%c\n", map_i[i]);
// 		return (0);
// 	}
// 	return (1);
// }

// int	check_n_m_s_e(char *map_i)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	while (map_i[i] == ' ' || map_i[i] == '\t')
// 		++i;
// 	count = 0;
// 	while (map_i[i])
// 	{
// 		if (map_i[i] == 'N' || map_i[i] == 'M'
// 			|| map_i[i] == 'S' || map_i[i] == 'E')
// 			++count;
// 		++i;
// 	}
// 	return (count);
// }

int	ft_len_map(char **map)
{
	int	count;

	count = 0;
	while (map[count++])
		;
	return (count);
}

int	parsing_valid_map(t_map *map)
{
	int	position_i;
	int	position_j;

	position_i = -1;
	position_j = -1;
	if (!find_player(map->map, &position_i, &position_j))
		return (printf("no player\n"), 0);
	if (!floot_fill_recur(map, position_i, position_j))
		return (printf("floot_fill_recur\n"), 0);
	if (!add_one_to_space(map))
		return (printf("add_one_to_space\n"), 0);
	if (!map->map)
		return (printf("map->map"), 0);
	if (!check_side_up_down(map->map, map->count))
		return (printf("check_side_up_down\n"), 0);
	if (!check_in_map_space_and_tab(map->map, map->count))
		return (printf("check_in_map_space_and_tab\n"), 0);
	if (!find_player(map->map, &position_i, &position_j))
		return (printf("no player\n"), 0);
	return (1);
}
