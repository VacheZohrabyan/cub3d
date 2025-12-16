/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 16:09:15 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/16 11:45:43 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx-linux/mlx.h"
# include <error.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
#include <math.h>
#include <X11/Xlib.h>

#define DEBUG 0

#define SCREEN_W 1280
#define SCREEN_H 720

#define W 119
#define A 97
#define S 115
#define D 100
#define BLOCK 64
#define LEFT 65361
#define RIGHT 65363

#define PI 3.14159265358979

typedef enum e_wall_side
{
    NORTH,
    SOUTH,
    EAST,
    WEST
} t_wall_side;

typedef struct s_ray
{
    float ray_dir_x;
    float ray_dir_y;
    int map_x;
    int map_y;

    float side_dist_x;
    float side_dist_y;

    float delta_dist_x;
    float delta_dist_y;

    int step_x;
    int step_y;

    int hit;
    int side; // 0 = X hit, 1 = Y hit
} t_ray;

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
	int		count_of_line;
	int 	len;
}	t_map;

typedef struct s_map_info
{
	t_ident	ident;
	t_map	map;
	char	**map_storage;
}	t_map_info;

typedef struct s_texture
{
	void* img;
	char* addr;
	int width;
	int heigth;
	int bpp;
	int size_line;
	int endian;
} t_texture;

typedef struct s_img
{
	t_texture east;
	t_texture north;
	t_texture south;
	t_texture west;
} t_img;

typedef struct s_player
{
	float x;
	float y;
	float angle;
	
	int key_up;
	int key_down;
	int key_left;
	int key_right;

	int left_rotate;
	int right_rotate;
} t_player;

typedef struct s_game
{
	char** map;
	int map_size_line;
	void* img;
	void* mlx;
	void* win;
	t_player player;
	t_img img_t;
	t_map_info* map_info;
	char* data;
	int size_line;
	int bpp;
	int endian;
	int display_width;
	int displey_heigth;
	int color_f;
	int color_c;
} t_game;

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
// int		find_player(char **map, int *position_i, int *position_j);
int		handle_no_and_so(char *map_i, t_map_info *map_info, int i);
int		handle_we_and_ea(char *map_i, t_map_info *map_info, int i);
int		handle_c_f_values(char *map_i, int i, t_ident *ident);
int		add_type_to_struct(char **ident, char *map_i, int i);
int		delete_space_middle(char *map_i);
int		check_color_number(char *map_i);
int		loop_map_storage(t_map_info *map_info, int map_line_count, int i);
void	delete_space_front(char **map_i);
int		allocate_map_map(int i, char **map_storage, t_map *map);

//
int run_game(t_game* game, t_map_info* map_info);
void init_player(t_game* game, t_player* player, int width, int heigth);
int key_realse(int keycode, t_player* player);
int key_press(int keycode, t_player* player);
void move_player(t_game* game, t_player* player);

#endif