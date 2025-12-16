/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:20:39 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/16 13:25:52 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void put_pixel(int x, int y, int color, t_game* game)
{
    if (x >= game->display_width || y >= game->displey_heigth || x < 0 || y < 0)
        return ;
    int index = y * game->size_line + x * (game->bpp / 8);
    game->data[index] = (color) & 0xFF;
    game->data[index + 1] = (color >> 8) & 0xFF;
    game->data[index + 2] = (color >> 16) & 0xFF;    
} 

void put_texture_pixel(t_texture *texture, int tex_x, int tex_y, int x, int y, t_game *game)
{
    int color = ((int*)texture->addr)[tex_y * (texture->size_line / 4) + tex_x];
    ((int*)game->data)[y * (game->size_line / 4) + x] = color;
}
void draw_texture(t_texture *texture, int start_x, int start_y, t_game *game)
{
    for (int y = 0; y < texture->heigth; y++)
    {
        for (int x = 0; x < texture->width; x++)
        {
            int gx = start_x + x;
            int gy = start_y + y;
            if (gx >= 0 && gx < game->display_width && gy >= 0 && gy < game->displey_heigth)
                put_texture_pixel(texture, x, y, gx, gy, game);
        }
    }
}

void draw_square(int x, int y, int size, int color, t_game* game)
{
    int i = 0;
    while (i < size)
    {
        put_pixel(x + i, y, color, game);
        ++i;
    }
    i = 0;
    while (i < size)
    {
        put_pixel(x, y + i, color, game);
        ++i;
    }
    i = 0;
    while (i < size)
    {
        put_pixel(x + size, y + i, color, game);
        ++i;
    }
    i = 0;
    while (i < size)
    {
        put_pixel(x + i, y + size, color, game);
        ++i;
    }
        
}

void init_texture(t_game* game, t_img* img, t_map_info* map_info)
{
    img->east.img = mlx_xpm_file_to_image(game->mlx, map_info->ident.type_ident_ea, &(img->east.width), &(img->east.heigth));
    if (!img->east.img)
    {
        printf("init_texture(east) chexav\n");
        return ;
    }
    img->east.addr = mlx_get_data_addr(img->east.img, &img->east.bpp, &img->east.size_line, &img->east.endian);
    img->north.img = mlx_xpm_file_to_image(game->mlx, map_info->ident.type_ident_no, &(img->north.width), &(img->north.heigth));
    if (!img->north.img)
    {
        printf("init_texture(north) chexav\n");
        return ;
    }
    img->north.addr = mlx_get_data_addr(img->north.img, &(img->north.bpp), &(img->north.size_line), &(img->north.endian));
    img->south.img = mlx_xpm_file_to_image(game->mlx, map_info->ident.type_ident_so, &(img->south.width), &(img->south.heigth));
    if (!img->south.img)
    {
        printf("init_texture(south) chexav\n");
        return ;
    }
    img->south.addr = mlx_get_data_addr(img->south.img, &(img->south.bpp), &(img->south.size_line), &(img->south.endian));
    img->west.img = mlx_xpm_file_to_image(game->mlx, map_info->ident.type_ident_we, &(img->west.width), &(img->west.heigth));
    if (!img->west.img)
    {
        printf("init_texture(west) chexav\n");
        return ;
    }
    img->west.addr = mlx_get_data_addr(img->west.img, &(img->west.bpp), &(img->west.size_line), &(img->west.endian));
}

void init_game(t_game* game, t_map_info* map_info)
{
    game->map_info = map_info;
    game->map = map_info->map.map;
    game->map_size_line = map_info->map.count_of_line;
    game->display_width = SCREEN_W;
    game->displey_heigth = SCREEN_H;
    init_player(game, &(game->player), game->display_width, game->displey_heigth);
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, game->display_width, game->displey_heigth, "cub3d");
    game->img = mlx_new_image(game->mlx, game->display_width, game->displey_heigth);
    game->data = mlx_get_data_addr(game->img, &game->bpp, &game->size_line, &game->endian);
    init_texture(game, &(game->img_t), map_info);
}

void clear_image(t_game* game)
{
    int i = 0;
    int j = 0;
    while (j < game->display_width)
    {
        i = 0;
        while (i < game->displey_heigth)
        {
            put_pixel(j, i, 0, game);
            ++i;
        }
        ++j;
    }
}

void draw_map(t_game* game)
{
    char** map = game->map;
    int color = 0x0000FF;
    int x = 0;
    int y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '1')
                draw_square(x, y, 1, color, game);
            ++x;
        }
        ++y;
    }
}
int touch(float px, float py, t_game* game)
{
    if (!game->map)
        return 0;

    int x = (int)(px / BLOCK);
    int y = (int)(py / BLOCK);

    int map_h = 0;
    while (game->map[map_h])
        map_h++;

    if (y < 0 || y >= map_h)
        return 0;

    int map_w = ft_strlen(game->map[y]);
    if (x < 0 || x >= map_w)
        return 0;

    return (game->map[y][x] == '1');
}

float distance(float x, float y)
{
    return sqrt((x * x) + (y * y));
}

float fixed_distance(float x1, float y1, float x2, float y2, t_game* game)
{
    float delta_x = x2 - x1;
    float delta_y = y2 - y1;
    float angle = atan2(delta_y, delta_x) - game->player.angle;
    float fix_dist = distance(delta_x, delta_y) * cos(angle);
    return fix_dist;
}

void init_ray(t_ray *ray, t_player *p, float angle)
{
    ray->ray_dir_x = cos(angle);
    ray->ray_dir_y = sin(angle);

    ray->map_x = (int)(p->x / BLOCK);
    ray->map_y = (int)(p->y / BLOCK);

    ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
    ray->delta_dist_y = fabs(1 / ray->ray_dir_y);

    ray->hit = 0;

    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (p->x / BLOCK - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - p->x / BLOCK) * ray->delta_dist_x;
    }

    if (ray->ray_dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (p->y / BLOCK - ray->map_y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - p->y / BLOCK) * ray->delta_dist_y;
    }
}

void perform_dda(t_ray *ray, t_game *game)
{
    while (!ray->hit)
    {
        if (ray->side_dist_x < ray->side_dist_y)
        {
            ray->side_dist_x += ray->delta_dist_x;
            ray->map_x += ray->step_x;
            ray->side = 0;
        }
        else
        {
            ray->side_dist_y += ray->delta_dist_y;
            ray->map_y += ray->step_y;
            ray->side = 1;
        }
        if (game->map[ray->map_y][ray->map_x] == '1')
            ray->hit = 1;
    }
}

t_wall_side get_wall_side(t_ray *ray)
{
    if (ray->side == 0)
        return (ray->ray_dir_x > 0) ? WEST : EAST;
    else
        return (ray->ray_dir_y > 0) ? NORTH : SOUTH;
}

t_texture *get_texture(t_game *g, t_wall_side side)
{
    if (side == NORTH) return &g->img_t.north;
    if (side == SOUTH) return &g->img_t.south;
    if (side == EAST)  return &g->img_t.east;
    return &g->img_t.west;
}

float get_wall_dist(t_ray *ray, t_player *p)
{
    if (ray->side == 0)
        return (ray->map_x - p->x / BLOCK + (1 - ray->step_x) / 2)
            / ray->ray_dir_x;
    else
        return (ray->map_y - p->y / BLOCK + (1 - ray->step_y) / 2)
            / ray->ray_dir_y;
}

int get_tex_x(t_ray *ray, t_texture *tex, t_player *p)
{
    float wall_x;

    if (ray->side == 0)
        wall_x = p->y / BLOCK + get_wall_dist(ray, p) * ray->ray_dir_y;
    else
        wall_x = p->x / BLOCK + get_wall_dist(ray, p) * ray->ray_dir_x;

    wall_x -= floor(wall_x);

    int tex_x = (int)(wall_x * tex->width);

    if ((ray->side == 0 && ray->ray_dir_x > 0)
        || (ray->side == 1 && ray->ray_dir_y < 0))
        tex_x = tex->width - tex_x - 1;

    return tex_x;
}

void draw_column(t_game *g, int x, float angle)
{
    t_ray ray;
    init_ray(&ray, &g->player, angle);
    perform_dda(&ray, g);

    float dist = get_wall_dist(&ray, &g->player);
    int line_h = (int)(g->displey_heigth / dist);

    int start = -line_h / 2 + g->displey_heigth / 2;
    int end = line_h / 2 + g->displey_heigth / 2;

    if (start < 0) start = 0;
    if (end >= g->displey_heigth) end = g->displey_heigth - 1;

    t_wall_side side = get_wall_side(&ray);
    t_texture *tex = get_texture(g, side);
    if (!tex || !tex->addr)
        return;
    int tex_x = get_tex_x(&ray, tex, &g->player);
    if (tex_x >= tex->width) tex_x = tex->width - 1;
    if (tex_x < 0) tex_x = 0;
    for (int y = start; y < end; y++)
    {
        int d = y * 256 - g->displey_heigth * 128 + line_h * 128;
        int tex_y = ((d * tex->heigth) / line_h) / 256;
        if (tex_y >= tex->heigth) tex_y = tex->heigth - 1;
        if (tex_y < 0) tex_y = 0;
        int color = ((int *)tex->addr)[tex_y * (tex->size_line / 4) + tex_x];
        put_pixel(x, y, color, g);
    }
}

int color_to_c(t_c c)
{
    return (c.red << 16) | (c.green << 8) | c.blue;
}
int color_to_f(t_f f)
{
    return (f.red << 16) | (f.green << 8) | f.blue;
}

void render(t_game *g)
{

    int mid = g->displey_heigth / 2;
    for (int x = 0; x < g->display_width; x++)
    {
        for (int y = 0; y < mid; y++) // ceiling
            put_pixel(x, y, color_to_c(g->map_info->ident.type_ident_c), g);

        for (int y = mid; y < g->displey_heigth; y++) // floor
            put_pixel(x, y, color_to_f(g->map_info->ident.type_ident_f), g);
    }
    float fov = PI / 3;
    float step = fov / g->display_width;
    float angle = g->player.angle - fov / 2;

    for (int x = 0; x < g->display_width; x++)
    {
        draw_column(g, x, angle);
        angle += step;
    }
}

// int draw_loop(t_game* game)
// {
//     t_player* player = &(game->player);
//     move_player(game, player);
//     clear_image(game);
//     if (DEBUG)
//     {
//         draw_square(player->x, player->y, 10, 0X00FF00, game);
//         draw_map(game);
//     }
    
//     float fraction = PI / 3 / game->display_width;
//     float start_x = player->angle - PI / 6;
//     int i = 0;
//     while (i < game->display_width)
//     {
//         draw_line(player, game, start_x, i);
//         start_x += fraction;
//         i++;
//     }
//     // draw_texture(&game->img_t, 100, 100, game);
//     mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
//     return (0);
// }

int draw_loop(t_game* game)
{
    t_player* player = &game->player;

    move_player(game, player);
    clear_image(game);

    render(game);

    if (DEBUG)
    {
        draw_square(player->x, player->y, 10, 0x00FF00, game);
        draw_map(game);
    }

    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
    return (0);
}

static void	find_player(char **map, float *position_i, float *position_j)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
			{
				*position_i = j * BLOCK + BLOCK / 2;
				*position_j = i * BLOCK + BLOCK / 2;
                // game->player.angle = -PI / 2;
				return ;
			}
			++j;
		}
		++i;
	}
}

int run_game(t_game* game, t_map_info* map_info)
{
    (void)map_info;
    init_game(game, map_info);
    find_player(game->map, &(game->player.x), &(game->player.y));
    mlx_hook(game->win, 2, 1L<<0, key_press, &game->player);
    mlx_hook(game->win, 3, 1L<<1, key_realse, &game->player);
    draw_square(game->display_width / 2, game->displey_heigth / 2, 10, 0x00FF00, game);
    mlx_loop_hook(game->mlx, draw_loop, game);
    mlx_loop(game->mlx);
    return (0);
}