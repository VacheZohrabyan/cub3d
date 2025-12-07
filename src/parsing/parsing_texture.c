/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:16:40 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/06 15:56:55 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	delete_space_middle(char *map_i)
{
	int	i;

	i = 0;
	if (map_i[i] != ' ')
		return (i);
	else
	{
		while (map_i[i] == '\t' || map_i[i] == '\n' || map_i[i] == '\v'
			|| map_i[i] == '\f' || map_i[i] == '\r' || map_i[i] == ' ')
			++i;
	}
	return (i);
}

int	check_path_xpm(char *map, int i)
{
	int	fd;

	fd = -1;
	if (ft_strncmp((map + ft_strlen(map)) - 4, ".xpm", ft_strlen(".xpm")))
		return (printf(".xpm not valid\n"), 0);
	fd = open(map + i, O_RDONLY);
	if (fd < 0)
		return (printf("open faild\n"), 0);
	close(fd);
	return (1);
}

int	add_type_to_struct(char **ident, char *map_i, int i)
{
	i += 2;
	i += delete_space_middle(map_i + i);
	if (!check_path_xpm(map_i, i))
	{
		*ident = ft_strdup(map_i + i);
		return (1);
	}
	return (0);
}

int	parsing_texture(t_map_info *map_info, char *map_i)
{
	int	i;

	i = 0;
	if (!ft_strncmp(map_i, "F", 1) || !ft_strncmp(map_i, "C", 1))
	{
		if (!handle_c_f_values(map_i, i, &(map_info->ident)))
			return (1);
		return (printf("handle_c_f_values\n"), 0);
	}
	else if (!ft_strncmp(map_i, "NO", 2) || !ft_strncmp(map_i, "SO", 2))
	{
		if (handle_no_and_so(map_i, map_info, i))
			return (1);
		return (printf("handle_no_and_so\n"), 0);
	}
	else if (!ft_strncmp(map_i, "WE", 2) || !ft_strncmp(map_i, "EA", 2))
	{
		if (handle_we_and_ea(map_i, map_info, i))
			return (1);
		return (printf("handle_we_and_ea\n"), 0);
	}
	return (1);
}
