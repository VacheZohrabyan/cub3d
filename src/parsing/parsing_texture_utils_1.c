/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture_utils_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 14:04:17 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/07 17:50:50 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	handle_no_and_so(char *map_i, t_map_info *map_info, int i)
{
	if (!ft_strncmp(map_i, "NO", 2))
	{
		if (add_type_to_struct(&(map_info->ident.type_ident_no), map_i, i))
		{
			map_info->ident.flag_no = 1;
			return (1);
		}
		return (printf("add_type_to_struct_NO\n"), 0);
	}
	else if (!ft_strncmp(map_i, "SO", 2))
	{
		if (add_type_to_struct(&(map_info->ident.type_ident_so), map_i, i))
		{
			map_info->ident.flag_so = 1;
			return (1);
		}
		return (printf("add_type_to_struct_SO\n"), 0);
	}
	return (1);
}

int	handle_we_and_ea(char *map_i, t_map_info *map_info, int i)
{
	if (!ft_strncmp(map_i, "WE", 2))
	{
		if (add_type_to_struct(&(map_info->ident.type_ident_we), map_i, i))
		{
			map_info->ident.flag_we = 1;
			return (1);
		}
		return (printf("add_type_to_struct_WE\n"), 0);
	}
	else if (!ft_strncmp(map_i, "EA", 2))
	{
		if (add_type_to_struct(&(map_info->ident.type_ident_ea), map_i, i))
		{
			map_info->ident.flag_ea = 1;
			return (1);
		}
		return (printf("add_type_to_struct_EA\n"), 0);
	}
	return (1);
}

int	handle_c_f_values(char *map_i, int i, t_ident *ident)
{
	i = 1;
	if (!ft_strncmp(map_i, "F", 1))
	{
		i += delete_space_middle(map_i + i);
		if (check_color_number(map_i + i))
			return (init_ident_color(map_i, i, ident, 'F'), 1);
		return (printf("check_color_number\n"), 0);
	}
	else if (!ft_strncmp(map_i, "C", 1))
	{
		i += delete_space_middle(map_i + i);
		if (check_color_number(map_i + i))
			return (init_ident_color(map_i, i, ident, 'C'), 1);
		return (0);
	}
	return (1);
}
