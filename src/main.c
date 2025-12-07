/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 14:21:11 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/06 16:07:07 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	initialize_struct_map(t_map_info *map_info)
{
	map_info->ident.flag_no = 0;
	map_info->ident.flag_so = 0;
	map_info->ident.flag_we = 0;
	map_info->ident.flag_ea = 0;
	map_info->ident.flag_f = 0;
	map_info->ident.flag_c = 0;
	map_info->ident.type_ident_no = NULL;
	map_info->ident.type_ident_so = NULL;
	map_info->ident.type_ident_we = NULL;
	map_info->ident.type_ident_ea = NULL;
	map_info->ident.type_ident_f.red = 0;
	map_info->ident.type_ident_f.green = 0;
	map_info->ident.type_ident_f.blue = 0;
	map_info->ident.type_ident_c.red = 0;
	map_info->ident.type_ident_c.green = 0;
	map_info->ident.type_ident_c.blue = 0;
	map_info->map.map = NULL;
}

int	main(int argc, char **argv)
{
	t_map_info	map_info;

	if (argc != 2)
		return (printf("usage: ./cub3d <path/to/map.cub>"), 0);
	initialize_struct_map(&map_info);
	if (!parsing(argv[1], &map_info))
	{
		free_map(&map_info);
		return (1);
	}
	free_map(&map_info);
	return (1);
}
