/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 17:34:34 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/25 15:22:11 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	destroy_img(t_game *game)
{
	if (!game || !game->mlx)
		return ;
	if (game->img_t.east.img)
		mlx_destroy_image(game->mlx, game->img_t.east.img);
	if (game->img_t.east.img)
		mlx_destroy_image(game->mlx, game->img_t.east.img);
	if (game->img_t.east.img)
		mlx_destroy_image(game->mlx, game->img_t.east.img);
	if (game->img_t.east.img)
		mlx_destroy_image(game->mlx, game->img_t.east.img);
	if (game->mlx && game->img)
	{
		mlx_destroy_image(game->mlx, game->img);
		game->img = NULL;
	}
}

void	destroy_mlx_pointer(t_game *game)
{
	if (game->mlx && game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
}

void	clear_map(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (i < game->map_size_line)
			free(game->map[i++]);
		free(game->map);
		game->map = NULL;
	}
	if (game->map_info)
	{
		free(game->map_info);
		game->map_info = NULL;
	}
}

void	destroy(t_game *game, char *message)
{
	if (!game || game->is_destroyed)
		return ;
	game->is_destroyed = 1;
	if (message)
		printf("%s\n", message);
	if (game->mlx)
		mlx_loop_end(game->mlx);
	if (game->mlx && game->win)
	{
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
	}
	destroy_img(game);
	clear_map(game);
	mlx_loop_end(game->mlx);
}
