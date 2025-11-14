/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:16:40 by vzohraby          #+#    #+#             */
/*   Updated: 2025/11/13 15:14:51 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int delete_space_middle(char* map_i)
{
    int i = 0;
    if (map_i[i] != ' ')
            return i;
    else
    {
        while (map_i[i] == '\t' || map_i[i] == '\n' || map_i[i] == '\v'
		    || map_i[i] == '\f' || map_i[i] == '\r' || map_i[i] == ' ')
		    ++i;
    }
    return (i);
}

static int is_digit(char* num)
{
    int i = 0;
    while (num[i])
    {
        if (!ft_isdigit(num[i]))
            return (0);
        ++i;
    }
    return (1);
}

char* cat_space(char* number)
{
    int i = 0;
    while (number[i])
    {
        if (ft_isdigit(number[i]))
            ++i;
        else
        {
            if (number[i] == ' ')
            {
                int start = i;
                while (number[i] == ' ')
                    ++i;
                if (number[i] == '\0')
                    return (number[start] = '\0', number);
            }
            return number;
        }
    }
    return number;
}

static int check_color_number(char* map_i)
{
    int size = 0;
    char** number = ft_split(map_i, ',');
    while (number[size])
        ++size;
    if (size != 3)
        return (0);
    number[size - 1] = cat_space(number[size - 1]);
    size = 0;
    while (number[size])
    {
        if (!is_digit(number[size]))
            return (free_split(number), 0);
        if (ft_atoi(number[size]) < 0 || ft_atoi(number[size]) > 255)
            return (0);
        ++size;
    }
    free(number);
    return (1);
}

static int handle_c_f_values(char* map_i, int i, t_ident* ident)
{
    i = 1;
    if (!ft_strncmp(map_i, "F", 1))
    {
        i += delete_space_middle(map_i + i);
        if (check_color_number(map_i + i))
            return (init_ident_color(map_i, i, ident, 'F'), 1);
        return (0);
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

int parsing_texture(t_map_info* map_info, char* map_i)
{
    int i = 0;
    if (!ft_strncmp(map_i, "F", 1) || !ft_strncmp(map_i, "C", 1))
    {
        if (handle_c_f_values(map_i, i, &(map_info->ident)))
            return (1);
        return (0);
    }
    else if (!ft_strncmp(map_i, "NO", 2))
    {
        i += 2;
        i += delete_space_middle(map_i + i);
        if (!ft_strncmp(map_i + i, "./xpm/north.xpm", ft_strlen(map_i + i)))
        {
            map_info->ident.type_ident_NO = ft_strdup(map_i + i);
            map_info->ident.flag_NO = 1;
            return (1);
        }
        return (0);
    }
    else if (!ft_strncmp(map_i, "SO", 2))
    {
        i += 2;
        i += delete_space_middle(map_i + i);
        if (!ft_strncmp(map_i + i, "./xpm/south.xpm", ft_strlen(map_i + i)))
        {
            map_info->ident.type_ident_SO = ft_strdup(map_i + i);
            map_info->ident.flag_SO = 1;
            return (1);
        }
        return (0);
    }
    else if (!ft_strncmp(map_i, "WE", 2))
    {
        i += 2;
        i += delete_space_middle(map_i + i);
        if (!ft_strncmp(map_i + i, "./xpm/west.xpm", ft_strlen(map_i + i)))
        {
            map_info->ident.type_ident_WE = ft_strdup(map_i + i);
            map_info->ident.flag_WE = 1;
            return (1);
        }
        return (0);
    }
    else if (!ft_strncmp(map_i, "EA", 2))
    {
        i += 2;
        i += delete_space_middle(map_i + i);
        if (!ft_strncmp(map_i + i, "./xpm/east.xpm", ft_strlen(map_i + i)))
        {
            map_info->ident.type_ident_EA = ft_strdup(map_i + i);
            map_info->ident.flag_EA = 1;
            return (1);
        }
        return (0);
    }
    return (1);
}