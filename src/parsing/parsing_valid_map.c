/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_valid_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:42:10 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/05 14:36:43 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int check_line(char* map_i)
{
    int i = 0;
    while (map_i[i] == ' ')
        ++i;
    if (map_i[i] != 1 || map_i[ft_strlen(map_i) - 1] != 1)
    {
        printf("%c\n", map_i[i]);
        return (0);
    }    
    return 1;
}

int check_N_M_S_E(char* map_i)
{
    int i = 0;
    while (map_i[i] == ' ' || map_i[i] == '\t')
        ++i;
    int count = 0;
    while (map_i[i])
    {
        if (map_i[i] == 'N' || map_i[i] == 'M' || map_i[i] == 'S' || map_i[i] == 'E')
            ++count;   
        ++i;
    }
    return count;
}

int check_side_up_down(char** map, int count)
{
    int i = 0;
    int j = 0;
    int size = ft_strlen(map[0]);
    while (i < size)
    {
        while (map[0][i] == ' ')
            ++i;
        if (map[0][i] != '1')
            return (printf("map-y verevy bac e\n"), 0);
        ++i;
    }
    i = 1;
    while (i < count - 1)
    {
        j = 0;
        while (map[i][j] == ' ')
            ++j;
        if (map[i][j] != '1')
            return (printf("map-y koxqy bacc e dimacic\n"), 0);
        if (map[i][ft_strlen(map[i]) - 1] != '1')
            return (printf("map-koxqy bac e hetevic\n"), 0);
        ++i;
    }
    i = 0;
    while (map[count - 1][i])
    {
        while (map[count - 1][i] == ' ')
            ++i;
        if (map[count - 1][i] != '1')
            return (printf("map-y nerqevy bac e\n"), 0);
        ++i;
    }
    return (1);
}

int ft_len_map(char** map)
{
    int count = 0;
    while (map[count++])
        ;
    return count;
}

int find_player(char** map, int* position_i, int* position_j)
{
    int i = 0;
    while (map[i])
    {
        int j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'N')
            {
                *position_i = i;
                *position_j = j;
                return (1);
            }
            ++j;
        }
        ++i;
    }
    return (0);
}

int check_in_map_space_and_tab(char** map, int count)
{
    int i = 0;
    int j = 0;
    while (i < count)
    {
        j = 0;
        int len_line_map = ft_strlen(map[i]);
        while (map[i][j] && map[i][j] == ' ')
            ++j;
        while (map[i][j] && map[i][j] != ' ')
            ++j;
        if (j != len_line_map)
            return (0);
        ++i;
    }
    return (1);
}

int is_walkable(char map_elem, char new_elem)
{
    return map_elem == '0' || map_elem == 'N' || map_elem == 'S' || map_elem == 'E' || map_elem == 'W' || map_elem == new_elem;
}

int floot_fill(char** map, int i, int j, char elem, char pos_elem)
{
    if (i < 0 || i >= ft_len_map(map))
        return (printf("i < 0 || i >= map_len\n"), 0);
    if (j < 0 || j >= (int)ft_strlen(map[i]))
        return (printf("j < 0 || j >= map_len_len\n"), 0);
    if (!is_walkable(map[i][j], pos_elem) || map[i][j] == 'X')
        return 1;
    map[i][j] = 'X';
    int up = floot_fill(map, i + 1, j, elem, pos_elem);
    int down = floot_fill(map, i - 1, j, elem, pos_elem);
    int left = floot_fill(map, i, j + 1, elem, pos_elem);
    int right = floot_fill(map, i, j - 1, elem, pos_elem);
    return (up && down && left && right);
}

char* add_one_space_and_new_allocate(char** map, int max_length)
{
    char* tmp = (char*)malloc(sizeof(char) * (max_length + 1));
    if (!tmp)
        return NULL;
    int i = 0;
    ft_memcpy(tmp, *map, ft_strlen(*map));
    while (i < max_length)
    {
        if (tmp[i] != '0' && tmp[i] != '1' && tmp[i] != 'N' && tmp[i] != 'S' && tmp[i] != 'W' && tmp[i] != 'E')
            tmp[i] = '1';
        ++i;
    }
    tmp[i] = '\0';
    free(*map);
    return (tmp);
}

int add_one_to_space(t_map* map)
{
    int max_length_map_line = ft_strlen(map->map[0]);
    int i = 1;
    while (map->map[i])
    {
        if (max_length_map_line < (int)ft_strlen(map->map[i]))
            max_length_map_line = ft_strlen(map->map[i]);
        ++i;
    }
    i = 0;
    while (map->map[i])
    {
        if (max_length_map_line >= (int)ft_strlen(map->map[i]))
        {
            map->map[i] = add_one_space_and_new_allocate(&(map->map[i]), max_length_map_line);
            if (!map->map[i])
                return (0);
        }
        ++i;
    }
    return (1);
}

char** copy_map_pointer(t_map *map)
{
    char** str = (char**)malloc(sizeof(char*) * map->count);
    int i = 0;
    while (i < map->count)
    {
        str[i] = ft_strdup(map->map[i]);
        if (!str[i])
        {
            while (i)
                free(str[i--]);
            free(str);
            return NULL;
        }
        ++i;
    }
    str[map->count] = NULL;
    return str;
}

int floot_fill_recur(t_map* map, int pos_i, int pos_j)
{
    char** map_i = copy_map_pointer(map);
    if (!map_i)
        return (0);
    if (!floot_fill(map_i, pos_i, pos_j, '0', map_i[pos_i][pos_j]))
        return (printf("floot fill durs e ekel sahnmanneric"), 0);
    if (!check_side_up_down(map->map, map->count))
        return (printf("check_side_up_down\n"), 0);
    return (1);
}

int parsing_valid_map(t_map* map)
{
    int position_i = -1;
    int position_j = -1;
    if (!find_player(map->map, &position_i, &position_j))
        return (printf("no player\n"), 0);
    if (!floot_fill_recur(map, position_i, position_j))
        return (printf("floot_fill_recur\n"), 0);
    if (!add_one_to_space(map))
        return (printf("add_one_to_space\n"), 0);
    if (!map->map)
        return (printf("map->map"), 0);
    if (!check_side_up_down(map->map, map->count))
        return (printf("check_side_up_down\n"), 0);
    if (!check_in_map_space_and_tab(map->map, map->count))
        return (printf("check_in_map_space_and_tab\n"), 0);
    if (!find_player(map->map, &position_i, &position_j))
        return (printf("no player\n"), 0);
    int i = 0;
    while (map->map[i])
        printf("%s\n", map->map[i++]);
    return (1);
}