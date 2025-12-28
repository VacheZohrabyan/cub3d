/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 17:00:54 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/28 15:39:58 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= game->display_width || y >= game->displey_heigth || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * (game->bpp / 8);
	game->data[index] = (color) & 0xFF;
	game->data[index + 1] = (color >> 8) & 0xFF;
	game->data[index + 2] = (color >> 16) & 0xFF;
}

void	put_texture_pixel(t_texture *texture, t_utils utils, t_game *game)
{
	int	color;

	color = ((int *)texture->addr)[utils.x
		* (texture->size_line / 4) + utils.x];
	((int *)game->data)[utils.gy * (game->size_line / 4) + utils.gx] = color;
}
