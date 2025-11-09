#include "../inc/cub3d.h"

void initialize_struct_map(t_map* map)
{
    map->type_idet_NO.flag = 0;
    map->type_idet_NO.type_idet_NO = NULL;
    map->type_idet_SO.flag = 0;
    map->type_idet_SO.type_idet_SO = NULL;
    map->type_idet_EA.flag = 0;
    map->type_idet_EA.type_idet_EA = NULL;
    map->type_idet_WE.flag = 0;
    map->type_idet_WE.type_idet_WE = NULL;
    map->type_idet_C.flag = 0;
    map->type_idet_C.type_idet_C = NULL;
    map->type_idet_F.flag = 0;
    map->type_idet_F.type_idet_F = NULL;
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printf("to many argument\n");
        return (1);
    }
    t_map map;
    initialize_struct_map(&map);
    if (!parsing(argv[1], &map))
    {
        free_map_type_idet(&map);
        return (1);
    }
    free_map_type_idet(&map);

    return (1);
}