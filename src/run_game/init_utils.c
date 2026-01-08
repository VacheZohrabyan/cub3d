/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 15:26:19 by vzohraby          #+#    #+#             */
/*   Updated: 2026/01/08 12:23:36 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	init_ray_member(t_ray *ray, t_player *p, float angle)
{
	ray->ray_dir_x = cos(angle);
	ray->ray_dir_y = sin(angle);
	ray->map_x = (int)(p->x / BLOCK);
	ray->map_y = (int)(p->y / BLOCK);
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

int	init_texture_img(t_game *game, t_img *img, t_map_info *map_info)
{
	img->east.img = NULL;
	img->north.img = NULL;
	img->south.img = NULL;
	img->west.img = NULL;
	img->east.img = mlx_xpm_file_to_image(game->mlx,
			map_info->ident.type_ident_ea, &(img->east.width),
			&(img->east.heigth));
	if (!img->east.img)
		return (0);
	img->north.img = mlx_xpm_file_to_image(game->mlx,
			map_info->ident.type_ident_no, &(img->north.width),
			&(img->north.heigth));
	if (!img->north.img)
		return (0);
	img->south.img = mlx_xpm_file_to_image(game->mlx,
			map_info->ident.type_ident_so, &(img->south.width),
			&(img->south.heigth));
	if (!img->south.img)
		return (0);
	img->west.img = mlx_xpm_file_to_image(game->mlx,
			map_info->ident.type_ident_we, &(img->west.width),
			&(img->west.heigth));
	if (!img->west.img)
		return (0);
	return (1);
}

int	init_texture_addr(t_img *img)
{
	img->east.addr = NULL;
	img->south.addr = NULL;
	img->north.addr = NULL;
	img->west.addr = NULL;
	img->east.addr = mlx_get_data_addr(img->east.img, &img->east.bpp,
			&img->east.size_line, &img->east.endian);
	if (!img->east.addr)
		return (0);
	img->north.addr = mlx_get_data_addr(img->north.img, &(img->north.bpp),
			&(img->north.size_line), &(img->north.endian));
	if (!img->north.addr)
		return (0);
	img->south.addr = mlx_get_data_addr(img->south.img, &(img->south.bpp),
			&(img->south.size_line), &(img->south.endian));
	if (!img->south.addr)
		return (0);
	img->west.addr = mlx_get_data_addr(img->west.img, &(img->west.bpp),
			&(img->west.size_line), &(img->west.endian));
	if (!img->west.addr)
		return (0);
	return (1);
}
