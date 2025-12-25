/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_speed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 14:52:12 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/24 15:21:54 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	player_speed(t_player *player, t_player_utils *player_utils)
{
	if (player->key_up)
	{
		player_utils->new_x += player_utils->cos_angle * player_utils->speed;
		player_utils->new_y += player_utils->sin_angle * player_utils->speed;
	}
	if (player->key_down)
	{
		player_utils->new_x -= player_utils->cos_angle * player_utils->speed;
		player_utils->new_y -= player_utils->sin_angle * player_utils->speed;
	}
	if (player->key_left)
	{
		player_utils->new_x += player_utils->sin_angle * player_utils->speed;
		player_utils->new_y -= player_utils->cos_angle * player_utils->speed;
	}
	if (player->key_right)
	{
		player_utils->new_x -= player_utils->sin_angle * player_utils->speed;
		player_utils->new_y += player_utils->cos_angle * player_utils->speed;
	}
}
