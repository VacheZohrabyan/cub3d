/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 17:09:48 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/28 13:24:07 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	to_paint_the_floor_and_celling(int x, t_game *g)
{
	int	mid;
	int	y;

	mid = g->displey_heigth / 2;
	y = 0;
	while (y < mid)
	{
		put_pixel(x, y, color_to_c(g->map_info->ident.type_ident_c), g);
		++y;
	}
	y = 0;
	while (y < g->displey_heigth)
	{
		put_pixel(x, y, color_to_f(g->map_info->ident.type_ident_f), g);
		++y;
	}
}

void	render(t_game *g)
{
	float	fov;
	float	step;
	float	angle;
	int		x;

	x = 0;
	while (x < g->display_width)
	{
		to_paint_the_floor_and_celling(x, g);
		++x;
	}
	fov = PI / 3;
	step = fov / g->display_width;
	angle = g->player.angle - fov / 2;
	x = 0;
	while (x < g->display_width)
	{
		draw_column(g, x, angle);
		angle += step;
		++x;
	}
}
