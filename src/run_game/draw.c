/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:45:20 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/28 15:45:44 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	draw_texture(t_texture *texture, int start_x, int start_y, t_game *game)
{
	t_utils	utils;

	utils.y = 0;
	while (utils.y < texture->heigth)
	{
		utils.x = 0;
		while (utils.x < texture->width)
		{
			utils.gx = start_x + utils.x;
			utils.gy = start_y + utils.y;
			if (utils.gx >= 0 && utils.gx < game->display_width && utils.gy >= 0
				&& utils.gy < game->displey_heigth)
				put_texture_pixel(texture, utils, game);
			++(utils.x);
		}
		(utils.y)++;
	}
}

void	draw_square(t_utils utils, t_game *game)
{
	int	i;

	i = 0;
	while (i < utils.size)
	{
		put_pixel(utils.x + i, utils.y, utils.color, game);
		put_pixel(utils.x, utils.y + i, utils.color, game);
		put_pixel(utils.x + utils.size, utils.y + i, utils.color, game);
		put_pixel(utils.x + i, utils.y + utils.size, utils.color, game);
		++i;
	}
}

void	draw_map(t_game *game)
{
	char	**map;
	t_utils	utils;

	map = game->map;
	utils.x = 0;
	utils.y = 0;
	utils.color = 0x0000FF;
	utils.size = 1;
	while (map[utils.y])
	{
		utils.x = 0;
		while (map[utils.y][utils.x])
		{
			if (map[utils.y][utils.x] == '1')
				draw_square(utils, game);
			++(utils.x);
		}
		++(utils.y);
	}
}

int	draw_loop(t_game *game)
{
	t_player	*player;
	t_utils		utils;

	player = &game->player;
	move_player(game, player);
	clear_image(game);
	render(game);
	if (DEBUG)
	{
		utils.color = 10;
		utils.x = player->x;
		utils.y = player->y;
		utils.size = 10;
		draw_square(utils, game);
		draw_map(game);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

void	draw_column(t_game *g, int x, float angle)
{
	t_ray			ray;
	t_texture		*tex;
	t_utils			utils;

	init_ray(&ray, &g->player, angle);
	perform_dda(&ray, g);
	compute_wall_slice_bounds(&utils, g, &ray);
	if (!prepare_texture_sampling(g, &ray, &tex, &utils.tex_x))
		return ;
	draw_textured_wall_column(utils, tex, g, x);
}
