/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 14:05:36 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/07 17:49:48 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	is_digit(char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		++i;
	}
	return (1);
}

char	*cat_space(char *number)
{
	int	i;
	int	start;

	i = 0;
	while (number[i])
	{
		if (ft_isdigit(number[i]))
			++i;
		else
		{
			if (number[i] == ' ')
			{
				start = i;
				while (number[i] == ' ')
					++i;
				if (number[i] == '\0')
					return (number[start] = '\0', number);
			}
			return (number);
		}
	}
	return (number);
}

int	check_color_number(char *map_i)
{
	int		size;
	char	**number;

	size = 0;
	number = ft_split(map_i, ',');
	while (number[size])
		++size;
	if (size != 3)
		return (printf("size\n"), free_split(number), 0);
	number[size - 1] = cat_space(number[size - 1]);
	size = 0;
	while (number[size])
	{
		if (!is_digit(number[size]))
			return (printf("is_digit\n"), free_split(number), 0);
		if (ft_atoi(number[size]) < 0 || ft_atoi(number[size]) > 255)
			return (printf("ft_atoi\n"), free_split(number), 0);
		++size;
	}
	return (free_split(number), 1);
}
