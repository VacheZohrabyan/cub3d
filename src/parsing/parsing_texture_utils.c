/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:51:29 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/06 16:11:45 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	init_ident_color_c(char *map_i, int i, t_ident *ident)
{
	char	**number;

	number = ft_split(map_i + i, ',');
	ident->type_ident_c.red = ft_atoi(number[0]);
	ident->type_ident_c.green = ft_atoi(number[1]);
	ident->type_ident_c.blue = ft_atoi(number[2]);
	ident->flag_c = 1;
	free_split(number);
}

static void	init_ident_color_f(char *map_i, int i, t_ident *ident)
{
	char	**number;

	number = ft_split(map_i + i, ',');
	ident->type_ident_f.red = ft_atoi(number[0]);
	ident->type_ident_f.green = ft_atoi(number[1]);
	ident->type_ident_f.blue = ft_atoi(number[2]);
	ident->flag_f = 1;
	free_split(number);
}

void	init_ident_color(char *map_i, int i, t_ident *ident, char type)
{
	if (type == 'C')
		init_ident_color_c(map_i, i, ident);
	else
		init_ident_color_f(map_i, i, ident);
}
