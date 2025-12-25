/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:45:20 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/25 17:07:59 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void draw_texture(t_texture *texture, int start_x, int start_y, t_game *game)
{
	int	y;
	int	x;
	int	gx;
	int	gy;

	y = 0;
	while (y < texture->heigth)
	{
		x = 0;
		while (x < texture->width)
		{
			gx = start_x + x;
			gy = start_y + y;
			if (gx >= 0 && gx < game->display_width && gy >= 0 && gy < game->displey_heigth)
				put_texture_pixel(texture, x, y, gx, gy, game);
			++x;
		}
		y++;
	}
}

void	draw_square(int x, int y, int size, int color, t_game* game)
{
	int	i;

	// i = 0;
	// while (i < size)
	// 	put_pixel(x + (i++), y, color, game);
	// i = 0;
	// while (i < size)
	// 	put_pixel(x, y + (i++), color, game);
	// i = 0;
	// while (i < size)
	// 	put_pixel(x + size, y + (i++), color, game);
	// i = 0;
	// while (i < size)
	// 	put_pixel(x + (i++), y + size, color, game);
	i = 0;
	while (i < size)
	{
			put_pixel(x + (i++), y, color, game);
			put_pixel(x, y + (i++), color, game);

		put_pixel(x + size, y + (i++), color, game);

			put_pixel(x + (i++), y + size, color, game);
		++i;
	}
}

void	draw_map(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map;
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(x, y, 1, 0x0000FF, game);
			++x;
		}
		++y;
	}
}

int	draw_loop(t_game *game)
{
	t_player	*player;

	player = &game->player;
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