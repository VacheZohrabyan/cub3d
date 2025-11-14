/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:05:41 by vzohraby          #+#    #+#             */
/*   Updated: 2025/11/13 15:01:26 by vzohraby         ###   ########.fr       */
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

static int init_map(char* map_file, t_map_info* map_info)
{
	size_t size = 0;
	int fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		if (errno == EISDIR)
			printf("map is a directory\n");
		else
			perror("open");
		return (0);
	}
	while (get_next_line(fd))
		++size;
	close(fd);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	map_info->map_storage = (char**)malloc(sizeof(char*) * (size + 1));
	if (!(map_info->map_storage))
		return (0);
	char* buffer;
	buffer = get_next_line(fd);
	if (!buffer)
	{
		printf("mup is empty\n");
		close(fd);
		return (0);
	}
	size = 0;
	while (buffer)
	{
		if (buffer[ft_strlen(buffer) - 1] == '\n')
			buffer[ft_strlen(buffer) - 1] = '\0';
		map_info->map_storage[size] = ft_strdup(buffer);
		++size;
		free(buffer);
		buffer = get_next_line(fd);
	}
	map_info->map_storage[size] = NULL;
	close(fd);
	return (1);
}

int parsing(char* map_file, t_map_info* map_info)
{
	if (!is_map_valid_format(map_file))
	{
		printf("is not valid format .cub\n");
		return (0);
	}
	if (!init_map(map_file, map_info) || !is_map_valid(map_info))
		return (printf("Error\n"), 0);
	return (1);
}
