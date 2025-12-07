/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floot_flit_checking.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:34:18 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/06 13:44:45 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	is_walkable(char map_elem, char new_elem)
{
	return (map_elem == '0' || map_elem == 'N' || map_elem == 'S'
		|| map_elem == 'E' || map_elem == 'W' || map_elem == new_elem);
}

static char	**copy_map_pointer(t_map *map)
{
	char	**str;
	int		i;

	str = (char **)malloc(sizeof(char *) * (map->count + 1));
	i = 0;
	while (i < map->count)
	{
		str[i] = ft_strdup(map->map[i]);
		if (!str[i])
		{
			while (i)
				free(str[i--]);
			free(str);
			return (NULL);
		}
		++i;
	}
	str[i] = NULL;
	return (str);
}

static int	floot_fill(char **map, int i, int j, char pos_elem)
{
	int	up;
	int	down;
	int	left;
	int	right;

	if (i < 0 || i >= ft_len_map(map))
		return (printf("i < 0 || i >= map_len\n"), 0);
	if (j < 0 || j >= (int)ft_strlen(map[i]))
		return (printf("j < 0 || j >= map_len_len\n"), 0);
	if (!is_walkable(map[i][j], pos_elem) || map[i][j] == 'X')
		return (1);
	map[i][j] = 'X';
	up = floot_fill(map, i + 1, j, pos_elem);
	down = floot_fill(map, i - 1, j, pos_elem);
	left = floot_fill(map, i, j + 1, pos_elem);
	right = floot_fill(map, i, j - 1, pos_elem);
	return (up && down && left && right);
}

int	floot_fill_recur(t_map *map, int pos_i, int pos_j)
{
	char	**map_i;

	map_i = copy_map_pointer(map);
	if (!map_i)
		return (0);
	if (!floot_fill(map_i, pos_i, pos_j, map_i[pos_i][pos_j]))
		return (printf("floot fill durs e ekel sahnmanneric"),
			free_map_map(map_i), 0);
	if (!check_side_up_down(map->map, map->count))
		return (printf("check_side_up_down\n"), free_map_map(map_i), 0);
	return (free_map_map(map_i), 1);
}
