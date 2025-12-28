/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:42:53 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/28 16:23:34 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	collides_wall(t_game *game, float x, float y)
{
	int	map_x_left;
	int	map_x_right;
	int	map_y_top;
	int	map_y_bottom;

	map_x_left = (int)((x - (WALL_MARGIN * BLOCK)) / BLOCK);
	map_x_right = (int)((x + (WALL_MARGIN * BLOCK)) / BLOCK);
	map_y_top = (int)((y - (WALL_MARGIN * BLOCK)) / BLOCK);
	map_y_bottom = (int)((y + (WALL_MARGIN * BLOCK)) / BLOCK);
	if (map_y_top < 0 || map_y_bottom >= game->map_size_line)
		return (1);
	if (map_x_left < 0 || map_x_right >= (int)ft_strlen(game->map[map_y_top]))
		return (1);
	if (game->map[map_y_top][map_x_left] == '1')
		return (1);
	if (game->map[map_y_top][map_x_right] == '1')
		return (1);
	if (game->map[map_y_bottom][map_x_left] == '1')
		return (1);
	if (game->map[map_y_bottom][map_x_right] == '1')
		return (1);
	return (0);
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
