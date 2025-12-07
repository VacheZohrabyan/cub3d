/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_up_side_down_file.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 13:31:47 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/06 13:38:39 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	check_up(char *map)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(map))
	{
		while (map[i] == ' ')
			++i;
		if (map[i] != '1')
			return (printf("map-y verevy bac e\n"), 0);
		++i;
	}
	return (1);
}

static int	check_down(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		while (map[i] == ' ')
			++i;
		if (map[i] != '1')
			return (printf("map-y nerqevy bac e\n"), 0);
		++i;
	}
	return (1);
}

static int	check_side(char **map, int count)
{
	int	i;
	int	j;

	i = 1;
	while (i < count - 1)
	{
		j = 0;
		while (map[i][j] == ' ')
			++j;
		if (map[i][j] != '1')
			return (printf("map-y koxqy bacc e dimacic\n"), 0);
		if (map[i][ft_strlen(map[i]) - 1] != '1')
			return (printf("map-koxqy bac e hetevic\n"), 0);
		++i;
	}
	return (1);
}

int	check_side_up_down(char **map, int count)
{
	if (!check_up(map[0]))
		return (0);
	if (!check_down(map[count - 1]))
		return (0);
	if (!check_side(map, count))
		return (0);
	return (1);
}
