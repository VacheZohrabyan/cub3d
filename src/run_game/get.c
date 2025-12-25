/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 16:57:49 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/25 16:58:40 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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