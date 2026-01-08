/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:48:51 by vzohraby          #+#    #+#             */
/*   Updated: 2026/01/08 12:21:57 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	init_mlx_new(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->win = mlx_new_window(game->mlx, game->display_width,
			game->displey_heigth, "");
	if (!game->win)
		return (destroy(game, ""), 0);
	game->img = mlx_new_image(game->mlx, game->display_width,
			game->displey_heigth);
	if (!game->img)
		return (destroy(game, ""), 0);
	game->data = mlx_get_data_addr(game->img, &game->bpp,
			&game->size_line, &game->endian);
	if (!game->data)
		return (destroy(game, ""), 0);
	return (1);
}
