/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:19:47 by vzohraby          #+#    #+#             */
/*   Updated: 2025/11/13 16:39:56 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void delete_space_front(char** map_i)
{
    int end = 0;
    while ((*map_i)[end] == ' ')
        ++end;
    char* tmp = ft_strdup((*map_i) + end);
    free(*map_i);
    *map_i = tmp;
}

static int check_ident(char* map_i)
{
    return (ft_strncmp(map_i, "F", 1)
            || ft_strncmp(map_i, "C", 1)
            || ft_strncmp(map_i, "NO", 2)
            || ft_strncmp(map_i, "SO", 2)
            || ft_strncmp(map_i, "WE", 2)
            || ft_strncmp(map_i, "EA", 2));
}

int allocate_map_map(int i, char** map_storage, t_map* map)
{
    int start = i;
    while (map_storage[start])
        ++start;
    map->map = (char**)malloc(sizeof(char*) * (start - i + 1));
    if (!map->map)
        return (0);
    return (1);
}

int is_map_valid(t_map_info* map_info)
{
    int i = 0;
    int flag = 0;
    int start = 0;
    // int count = 0;
    while (map_info->map_storage[i])
    {
        if (check_map(map_info->map_storage[i]))
        {
            if (!check_ident_full(map_info->ident))
                return (0);
            if (map_info->map_storage[i] == NULL && !flag)
                return (0);
            if (!map_info->map.map && !allocate_map_map(i, map_info->map_storage, &(map_info->map)))
                return (0);
            map_info->map.map[start] = ft_strdup(map_info->map_storage[i]);
            if (!map_info->map.map[start])
                return (0);
            map_info->map.map[start + 1] = NULL;
            ++start;
            flag = 1;
        }
        if (map_info->map_storage[i][0] == ' ' && !flag)
            delete_space_front(&(map_info->map_storage[i]));
        if (check_ident(map_info->map_storage[i]) && !flag)
        {
            // if (map_info->map_storage[i][0] != '\0')
            //     ++count;
            if (!parsing_texture(map_info, map_info->map_storage[i]))
                return (0);
        }
        ++i;
    }
    return 1;
}