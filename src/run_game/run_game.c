/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 14:20:39 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/28 14:34:59 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	clear_image(t_game *game)
{
	int	i;
	int	j;

	j = 0;
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

int	touch(float px, float py, t_game *game)
{
	int	map_w;
	int	x;
	int	y;
	int	map_h;

	if (!game->map)
		return (0);
	x = (int)(px / BLOCK);
	y = (int)(py / BLOCK);
	map_h = 0;
	while (game->map[map_h])
		map_h++;
	if (y < 0 || y >= map_h)
		return (0);
	map_w = ft_strlen(game->map[y]);
	if (x < 0 || x >= map_w)
		return (0);
	return (game->map[y][x] == '1');
}

void	perform_dda(t_ray *ray, t_game *game)
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
			}
			++j;
		}
		++i;
	}
}

int	run_game(t_game *game, t_map_info *map_info)
{
	t_utils	utils;

	if (!init_game(game, map_info))
		return (0);
	find_player(game->map, &(game->player.x), &(game->player.y));
	mlx_hook(game->win, 2, 1L << 0, player_key_press, game);
	mlx_hook(game->win, 3, 1L << 1, player_key_realse, game);
	mlx_hook(game->win, 17, 0, close_window, &game);
	utils.x = game->display_width;
	utils.y = game->displey_heigth;
	utils.size = 10;
	utils.color = 0x00FF00;
	draw_square(utils, game);
	mlx_loop_hook(game->mlx, draw_loop, game);
	mlx_loop(game->mlx);
	return (0);
}
