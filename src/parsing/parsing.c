/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:05:41 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/06 16:02:46 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	is_map_valid_format(char *map_file)
{
	size_t	size;

	size = ft_strlen(map_file);
	if (size >= 4)
	{
		if (!ft_strncmp(map_file + ft_strlen(map_file) - 4,
				".cub", ft_strlen(".cub")))
			return (1);
	}
	return (0);
}

int	get_line_size_file(char *map_file)
{
	int		fd;
	char	*buffer;
	int		size;

	size = -1;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		if (errno == EISDIR)
			printf("map is a directory\n");
		else
			perror("open");
		return (-1);
	}
	buffer = get_next_line(fd);
	while (buffer)
	{
		free(buffer);
		++size;
		buffer = get_next_line(fd);
	}
	close(fd);
	return (size + 1);
}

char	*open_file_and_allocate_map_storage(int *fd,
	t_map_info *map_info, char *map_file, int size)
{
	char	*buffer;

	buffer = NULL;
	*fd = open(map_file, O_RDONLY);
	if (*fd < 0)
		return (NULL);
	map_info->map_storage = (char **)malloc(sizeof(char *) * (size + 1));
	if (!(map_info->map_storage))
		return (NULL);
	buffer = get_next_line(*fd);
	if (!buffer)
		return (printf("mup is empty\n"), close(*fd), NULL);
	return (buffer);
}

static int	init_map(char *map_file, t_map_info *map_info)
{
	int		size;
	char	*buffer;
	int		fd;

	size = get_line_size_file(map_file);
	if (size == -1)
		return (0);
	buffer = open_file_and_allocate_map_storage(&fd, map_info, map_file, size);
	if (!buffer)
		return (0);
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

int	parsing(char *map_file, t_map_info *map_info)
{
	if (!is_map_valid_format(map_file))
	{
		printf("is not valid format .cub\n");
		return (0);
	}
	if (!init_map(map_file, map_info))
		return (printf("Error init_map\n"), 0);
	if (!is_map_valid(map_info))
		return (printf("Error is_map_valid\n"), 0);
	if (!parsing_valid_map(&(map_info->map)))
		return (printf("Error parsing_valid_map\n"), 0);
	return (1);
}
