#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "../minilibx-linux/mlx.h"
#include <error.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct s_f
{
	int red;
	int green;
	int blue;
} t_f;

typedef struct s_c
{
	int red;
	int green;
	int blue;
} t_c;

typedef struct s_ident
{
	char* type_ident_NO;
	char* type_ident_SO;
	char* type_ident_WE;
	char* type_ident_EA;
	t_c type_ident_C;
	t_f type_ident_F;
	int flag_NO;
	int flag_SO;
	int flag_WE;
	int flag_EA;
	int flag_C;
	int flag_F;
} t_ident;

typedef struct s_map
{
	char** map;
	int count;
} t_map;

typedef struct s_map_info
{
	t_ident ident;
	t_map map;
	char** map_storage;
}	t_map_info;

int parsing(char* map_file, t_map_info* map_info);
int parsing_texture(t_map_info* map_info, char* map_i);
int is_map_valid(t_map_info* map_info);
void free_map_type_idet(t_map_info* map_info);
void free_split(char** str);
void free_map(t_map_info* map_info);
int check_ident_full(t_ident ident);
int check_map(t_ident ident, char* map_i);
void init_ident_color(char* map_i, int i, t_ident* ident, char type);
int parsing_valid_map(t_map* map);
int check_ident(char* map_i);

#endif