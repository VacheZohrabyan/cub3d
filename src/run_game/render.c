/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 17:09:48 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/25 17:09:57 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"


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