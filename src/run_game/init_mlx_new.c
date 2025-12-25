/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 14:48:51 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/25 15:23:40 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	init_mlx_new(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (printf("init_game(mlx)\n"), 0);
	game->win = mlx_new_window(game->mlx, game->display_width,
			game->displey_heigth, "cub3d");
	if (!game->win)
		return (destroy(game, "init_game(win)"), 0);
	game->img = mlx_new_image(game->mlx, game->display_width,
			game->displey_heigth);
	if (!game->img)
		return (destroy(game, "init_game(img)\n"), 0);
	game->data = mlx_get_data_addr(game->img, &game->bpp,
			&game->size_line, &game->endian);
	if (!game->data)
		return (destroy(game, "init_game(data)\n"), 0);
	return (1);
}
