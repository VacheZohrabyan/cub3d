/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:05:41 by vzohraby          #+#    #+#             */
/*   Updated: 2025/11/09 18:07:06 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int is_map_valid_format(char* map_file)
{
	size_t size = ft_strlen(map_file);
	if (size >= 4)
	{
		if (!ft_strncmp(map_file + ft_strlen(map_file) - 4, ".cub", ft_strlen(".cub")))
			return (1);
	}
	return (0);
}

static int check_idet(char* buffer, int* i, const char* path, const char* idef)
{
	if (!ft_strncmp(buffer + (*i), idef, ft_strlen(idef)))
	{
		(*i) += ft_strlen(idef);
		if (buffer[*i] != ' ')
			return (1);
		if (buffer[*i] == ' ')
		{
			(*i)++;
			while (buffer[*i] == ' ')
				++(*i);
			if (!ft_strncmp(buffer + (*i), path, ft_strlen(buffer + (*i)) - 1))
				return (0);
			return (1);
		}
	}
	return (1);
}

static int find_non_digit(char* str)
{
	int i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		++i;
	if (str[i] == '\0')
		return (1);
	return (0);
}

static int check_idet_C_F(char* buffer, int *i)
{
	if (!ft_strncmp(buffer + (*i), "F", 1) || !ft_strncmp(buffer + (*i), "C", 1))
	{
		++(*i);
		if (buffer[*i] != ' ')
			return (1);
		while (buffer[*i] == ' ')
			++(*i);
		char** str = ft_split(buffer + (*i), ',');
		int count = 0;
		while (str[count])
			++count;
		if (count != 3)
			return (free_split(str), 1);
		count = 0;
		while (str[count])
		{
			if (!find_non_digit(str[count]))
						return (free_split(str), 1);
			int num = ft_atoi(str[count]);
			if (num < 0 || num > 255)
						return (free_split(str), 1);
			++count;
		}
		return (free_split(str), 0);
	}
	return (1);
}

static void no_correct_message()
{
	printf("no correct map\n");
}

static int init_map_idet(char* buffer, t_map* map, int *count)
{
	int i = 0;
	while (buffer[i] == ' ')
		++i;
	if (!ft_strncmp(buffer + i, "NO", 2))
	{
		if (!(map->type_idet_NO.flag) && !check_idet(buffer, &i, "./xpm/north.xpm", "NO"))
		{
			map->type_idet_NO.type_idet_NO = ft_strdup(buffer + i);
			map->type_idet_NO.flag = 1;
			(*count)++;
			return (1);
		}
		return (no_correct_message(), 0);
	}
	else if (!ft_strncmp(buffer + i, "SO", 2))
	{
		if (!(map->type_idet_SO.flag) && !check_idet(buffer, &i, "./xpm/south.xpm", "SO"))
		{
			map->type_idet_SO.type_idet_SO = ft_strdup(buffer + i);
			map->type_idet_SO.flag = 1;
			(*count)++;
			return (1);
		}
		return (no_correct_message(), 0);

	}
	else if (!ft_strncmp(buffer + i, "WE", 2))
	{
		if (!(map->type_idet_WE.flag) && !check_idet(buffer, &i, "./xpm/west.xpm", "WE"))
		{
			map->type_idet_WE.type_idet_WE = ft_strdup(buffer + i);
			map->type_idet_WE.flag = 1;
			(*count)++;
			return (1);
		}
		return (no_correct_message(), 0);

	}
	else if (!ft_strncmp(buffer + i, "EA", 2))
	{
		if (!(map->type_idet_EA.flag) && !check_idet(buffer, &i, "./xpm/east.xpm", "EA"))
		{
			map->type_idet_EA.type_idet_EA = ft_strdup(buffer + i);
			map->type_idet_EA.flag = 1;
			(*count)++;
			return (1);
		}
		return (no_correct_message(), 0);
	}
	else if (!ft_strncmp(buffer + i, "F", 1))
	{
		if (!(map->type_idet_F.flag) && !check_idet_C_F(buffer, &i))
		{
			map->type_idet_F.type_idet_F = ft_strdup(buffer + i);
			map->type_idet_F.flag = 1;
			(*count)++;
			return (1);
		}
		return (no_correct_message(), 0);
	}
	else if (!ft_strncmp(buffer + i, "C", 1))
	{
		if (!(map->type_idet_C.flag) && !check_idet_C_F(buffer, &i))
		{
			map->type_idet_C.type_idet_C = ft_strdup(buffer + i);
			map->type_idet_C.flag = 1;
			(*count)++;
			return (1);
		}
		return (no_correct_message(), 0);
	}
	return (1);
}

static int is_map_valid(char* map_file, t_map* map)
{
	int fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		printf("map not found");
		return (0);
	}
	char* buffer = get_next_line(fd);
	int count = 0;
	if (buffer == NULL)
	{
		printf("map is empty\n");
		return (0);
	}
	buffer[ft_strlen(buffer) - 1] = '\0';
	if (!init_map_idet(buffer, map, &count))
	{
		free(buffer);
		buffer = NULL;
		free_map_type_idet(map);
		return (0);
	}
	while (buffer)
	{
		free(buffer);
		buffer = get_next_line(fd);
		if (buffer && count != 6)
		{
			if (buffer[ft_strlen(buffer) - 1] == '\n')
				buffer[ft_strlen(buffer) - 1] = '\0';
			if (!init_map_idet(buffer, map, &count))
			{
				free(buffer);
				close(fd);
				return (0);
			}
		}
		else
		{
			free(buffer);
			break;
		}
	}
	if (count != 6)
		return (no_correct_message(), 0);
	close(fd);
	return (1);
} 

int parsing(char* map_file, t_map* map)
{
	if (!is_map_valid_format(map_file))
	{
		printf("map dont valid format\n");
		return (0);
	}
	if (!is_map_valid(map_file, map))
		return (0);
	return (1);
}