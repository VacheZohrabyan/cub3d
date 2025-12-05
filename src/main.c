#include "../inc/cub3d.h"

void initialize_struct_map(t_map_info* map_info)
{
    map_info->ident.flag_NO = 0;
    map_info->ident.flag_SO = 0;
    map_info->ident.flag_WE = 0;
    map_info->ident.flag_EA = 0;
    map_info->ident.flag_F = 0;
    map_info->ident.flag_C = 0;
    map_info->ident.type_ident_NO = NULL;
    map_info->ident.type_ident_NO = NULL;
    map_info->ident.type_ident_NO = NULL;
    map_info->ident.type_ident_NO = NULL;
    map_info->ident.type_ident_F.red = 0;
    map_info->ident.type_ident_F.green = 0;
    map_info->ident.type_ident_F.blue = 0;
    map_info->ident.type_ident_C.red = 0;
    map_info->ident.type_ident_C.green = 0;
    map_info->ident.type_ident_C.blue = 0;
    map_info->map.map = NULL;
}

int main(int argc, char** argv)
{
    if (argc != 2)
        return (printf("usage: ./cub3d <path/to/map.cub>"), 0);
    t_map_info map_info;
    initialize_struct_map(&map_info);
    if (!parsing(argv[1], &map_info))
    {
        free_map(&map_info);
        return (1);
    }

    // printf("NO = %s\n", map_info.ident.type_ident_NO);
    // printf("SO = %s\n", map_info.ident.type_ident_SO);
    // printf("WE = %s\n", map_info.ident.type_ident_WE);
    // printf("EA = %s\n", map_info.ident.type_ident_EA);
    // printf("Cred =   %d\n", map_info.ident.type_ident_C.red);
    // printf("Cgreen = %d\n", map_info.ident.type_ident_C.green);
    // printf("Cblue =  %d\n", map_info.ident.type_ident_C.blue);    
    // printf("Fred =   %d\n", map_info.ident.type_ident_F.red);
    // printf("Fgreen = %d\n", map_info.ident.type_ident_F.green);
    // printf("Fblue =  %d\n", map_info.ident.type_ident_F.blue);
    // int i = 0;
    // while (map_info.map.map[i])
    //     printf("%s\n", map_info.map.map[i++]);
    free_map(&map_info);

    return (1);
}