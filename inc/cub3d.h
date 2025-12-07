/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:09:15 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/06 16:10:57 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
// # include "../minilibx-linux/mlx.h"
# include <error.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_f
{
	int		red;
	int		green;
	int		blue;
}	t_f;

typedef struct s_c
{
	int		red;
	int		green;
	int		blue;
}	t_c;

typedef struct s_ident
{
	char	*type_ident_no;
	char	*type_ident_so;
	char	*type_ident_we;
	char	*type_ident_ea;
	t_c		type_ident_c;
	t_f		type_ident_f;
	int		flag_no;
	int		flag_so;
	int		flag_we;
	int		flag_ea;
	int		flag_c;
	int		flag_f;
}	t_ident;

typedef struct s_map
{
	char	**map;
	int		count;
}	t_map;

typedef struct s_map_info
{
	t_ident	ident;
	t_map	map;
	char	**map_storage;
}	t_map_info;

int		parsing(char *map_file, t_map_info *map_info);
int		parsing_texture(t_map_info *map_info, char *map_i);
int		is_map_valid(t_map_info *map_info);
void	free_map_type_idet(t_ident *ident);
void	free_split(char **str);
void	free_map(t_map_info *map_info);
void	free_map_map(char **map);
int		check_ident_full(t_ident ident);
int		check_map(t_ident ident, char *map_i);
void	init_ident_color(char *map_i, int i, t_ident *ident, char type);
int		parsing_valid_map(t_map *map);
int		check_ident(char *map_i);
int		check_side_up_down(char **map, int count);
int		floot_fill_recur(t_map *map, int pos_i, int pos_j);
int		ft_len_map(char **map);
int		add_one_to_space(t_map *map);
char	*add_one_space_and_new_allocate(char *map, int max_length);
int		check_in_map_space_and_tab(char **map, int count);
int		find_player(char **map, int *position_i, int *position_j);
int		handle_no_and_so(char *map_i, t_map_info *map_info, int i);
int		handle_we_and_ea(char *map_i, t_map_info *map_info, int i);
int		handle_c_f_values(char *map_i, int i, t_ident *ident);
int		add_type_to_struct(char **ident, char *map_i, int i);
int		delete_space_middle(char *map_i);
int		check_color_number(char *map_i);
int		loop_map_storage(t_map_info *map_info, int map_line_count, int i);
void	delete_space_front(char **map_i);
int		allocate_map_map(int i, char **map_storage, t_map *map);
#endif