#ifndef CUB3D_H
#define CUB3D_H

#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
#include "../minilibx-linux/mlx.h"

typedef struct s_no
{
	char* type_idet_NO;
	int flag;
} t_no;

typedef struct s_so
{
	char	*type_idet_SO;
	int flag;
} t_so;

typedef struct s_we
{
	char	*type_idet_WE;
	int flag;
} t_we;

typedef struct s_ea
{
	char	*type_idet_EA;
	int flag;
} t_ea;

typedef struct s_f
{
	char	*type_idet_F;
	int flag;
} t_f;

typedef struct s_c
{
	char	*type_idet_C;
	int flag;
} t_c;

typedef struct s_map
{
	t_no type_idet_NO;
	t_so type_idet_SO;
	t_we type_idet_WE;
	t_ea type_idet_EA;
	t_f type_idet_F;
	t_c type_idet_C;
}	t_map;

int parsing(char* map_file, t_map* map);
void free_map_type_idet(t_map* map);
void free_split(char** str);
#endif