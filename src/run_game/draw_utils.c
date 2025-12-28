/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:30:10 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/28 14:31:20 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	prepare_texture_sampling(t_game *g, t_ray *ray, t_texture **tex, int *tex_x)
{
	(*tex) = get_texture(g, get_wall_side(ray));
	if (!(*tex) || !(*tex)->addr)
		return (0);
	*tex_x = get_tex_x(ray, *tex, &g->player);
	if (*tex_x >= (*tex)->width)
		*tex_x = (*tex)->width - 1;
	if (*tex_x < 0)
		*tex_x = 0;
	return (1);
}

void	compute_wall_slice_bounds(t_utils *utils, t_game *g, t_ray *ray)
{
	utils->line_h = (int)(g->displey_heigth / get_wall_dist(ray, &g->player));
	utils->start = -(utils->line_h) / 2 + g->displey_heigth / 2;
	utils->end = utils->line_h / 2 + g->displey_heigth / 2;
	if (utils->start < 0)
		utils->start = 0;
	if (utils->end >= g->displey_heigth)
		utils->end = g->displey_heigth - 1;
}

void	draw_textured_wall_column(t_utils utils, t_texture *tex,
		t_game *g, int x)
{
	utils.y = utils.start;
	while (utils.y < utils.end)
	{
		utils.d = utils.y * 256 - g->displey_heigth * 128 + utils.line_h * 128;
		utils.tex_y = ((utils.d * tex->heigth) / utils.line_h) / 256;
		if (utils.tex_y >= tex->heigth)
			utils.tex_y = tex->heigth - 1;
		if (utils.tex_y < 0)
			utils.tex_y = 0;
		utils.color = ((int *)tex->addr)
		[utils.tex_y * (tex->size_line / 4) + utils.tex_x];
		put_pixel(x, utils.y, utils.color, g);
		utils.y++;
	}
}
