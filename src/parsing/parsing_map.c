/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:28:05 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/06 16:13:36 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	check_ident_full(t_ident ident)
{
	if (!ident.flag_no)
		return (0);
	if (!ident.flag_so)
		return (0);
	if (!ident.flag_we)
		return (0);
	if (!ident.flag_ea)
		return (0);
	if (!ident.flag_c)
		return (0);
	if (!ident.flag_f)
		return (0);
	return (1);
}

int	check_map(t_ident ident, char *map_i)
{
	int	i;

	i = 0;
	(void)ident;
	while (map_i[i] == ' ')
		++i;
	if (check_ident(map_i))
		return (0);
	while (map_i[i])
	{
		if (map_i[i] != '1' && map_i[i] != '0'
			&& map_i[i] != 'N' && map_i[i] != 'S'
			&& map_i[i] != 'E' && map_i[i] != 'W'
			&& map_i[i] != ' ')
			return (0);
		++i;
	}
	return (1);
}
