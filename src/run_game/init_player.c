/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:42:53 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/24 15:33:52 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	collides_wall(t_game *game, float x, float y)
{
	int	map_x;
	int	map_y;
	int	map_h;

	map_x = (int)(x / BLOCK);
	map_y = (int)(y / BLOCK);
	map_h = game->map_size_line;
	if (map_y < 0 || map_y >= map_h)
		return (1);
	if (map_x < 0 || map_x >= (int)ft_strlen(game->map[map_y]))
		return (1);
	return (game->map[map_y][map_x] == '1');
}

void	move_player(t_game *game, t_player *player)
{
	player->player_utils.speed = 3;
	player->player_utils.angle_speed = 0.03;
	player->player_utils.new_x = player->x;
	player->player_utils.new_y = player->y;
	if (player->left_rotate)
		player->angle -= player->player_utils.angle_speed;
	if (player->right_rotate)
		player->angle += player->player_utils.angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	player->player_utils.cos_angle = cos(player->angle);
	player->player_utils.sin_angle = sin(player->angle);
	player_speed(player, &player->player_utils);
	if (!collides_wall(game, player->player_utils.new_x,
			player->player_utils.new_y))
	{
		player->x = player->player_utils.new_x;
		player->y = player->player_utils.new_y;
	}
}
