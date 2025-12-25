/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 15:30:45 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/25 17:12:07 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_ray(t_ray *ray, t_player *p, float angle)
{
	init_ray_member(ray, p, angle);
	ray->hit = 0;
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (p->x / BLOCK - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - p->x / BLOCK)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (p->y / BLOCK - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - p->y / BLOCK)
			* ray->delta_dist_y;
	}
}

int	init_texture(t_game *game, t_img *img, t_map_info *map_info)
{
	if (!init_texture_img(game, img, map_info))
		return (destroy(game, "init_texture_img\n"), 0);
	if (!init_texture_addr(img))
		return (destroy(game, "init_texture_addr\n"), 0);
	return (1);
}

void	init_player(t_game *game, t_player *player, int width, int heigth)
{
	(void)width;
	(void)heigth;
	(void)game;
	player->key_down = 0;
	player->key_left = 0;
	player->key_right = 0;
	player->key_up = 0;
	player->angle = PI / 2;
	player->left_rotate = 0;
	player->right_rotate = 0;
}

int	init_game(t_game *game, t_map_info *map_info)
{
	game->map_info = map_info;
	game->map = map_info->map.map;
	game->map_size_line = map_info->map.count_of_line;
	game->display_width = SCREEN_W;
	game->displey_heigth = SCREEN_H;
	game->is_destroyed = 1;
	init_player(game, &(game->player), game->display_width,
		game->displey_heigth);
	if (!init_mlx_new(game))
		return (destroy(game, "init_mlx_new\n"), 0);
	if (!init_texture(game, &(game->img_t), map_info))
		return (destroy(game, "init_texture\n"), 0);
	return (1);
}
