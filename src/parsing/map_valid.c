/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:19:47 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/06 15:35:35 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	delete_space_front(char **map_i)
{
	char	*tmp;
	int		end;

	end = 0;
	while ((*map_i)[end] == ' ')
		++end;
	tmp = ft_strdup((*map_i) + end);
	free(*map_i);
	*map_i = tmp;
}

int	check_ident(char *map_i)
{
	int	i;

	i = 0;
	while (map_i[i] == ' ' || map_i[i] == '\t')
		++i;
	return (!ft_strncmp(map_i + i, "F ", 2)
		|| !ft_strncmp(map_i + i, "C ", 2)
		|| !ft_strncmp(map_i + i, "NO ", 2)
		|| !ft_strncmp(map_i + i, "SO ", 3)
		|| !ft_strncmp(map_i + i, "WE ", 3)
		|| !ft_strncmp(map_i + i, "EA ", 3));
}

int	allocate_map_map(int i, char **map_storage, t_map *map)
{
	int	count;

	count = 0;
	while (map_storage[i])
	{
		if (map_storage[i][0] != '\0')
			++count;
		++i;
	}
	map->count = count;
	map->map = (char **)malloc(sizeof(char *) * (count + 1));
	if (!map->map)
		return (0);
	return (1);
}

int	is_map_valid(t_map_info *map_info)
{
	int	i;
	int	map_line_count;

	i = 0;
	map_line_count = 0;
	if (!loop_map_storage(map_info, map_line_count, i))
		return (0);
	return (1);
}
