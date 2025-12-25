/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 14:47:08 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/25 15:12:43 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	player_key_realse(int keycode, t_game *game)
{
	if (keycode == LEFT)
		game->player.left_rotate = 0;
	if (keycode == RIGHT)
		game->player.right_rotate = 0;
	if (keycode == W)
		game->player.key_up = 0;
	if (keycode == S)
		game->player.key_down = 0;
	if (keycode == A)
		game->player.key_left = 0;
	if (keycode == D)
		game->player.key_right = 0;
	if (keycode == LEFT)
		game->player.left_rotate = 0;
	if (keycode == RIGHT)
		game->player.right_rotate = 0;
	return (1);
}

int	player_key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		destroy(game, "escape\n");
		exit (0);
	}
	if (keycode == LEFT)
		game->player.left_rotate = 1;
	if (keycode == RIGHT)
		game->player.right_rotate = 1;
	if (keycode == W)
		game->player.key_up = 1;
	if (keycode == S)
		game->player.key_down = 1;
	if (keycode == A)
		game->player.key_left = 1;
	if (keycode == D)
		game->player.key_right = 1;
	if (keycode == LEFT)
		game->player.left_rotate = 1;
	if (keycode == RIGHT)
		game->player.right_rotate = 1;
	return (0);
}
