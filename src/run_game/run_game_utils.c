/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 17:00:14 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/28 14:39:20 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

float	distance(float x, float y)
{
	return (sqrt((x * x) + (y * y)));
}

// float	fixed_distance(float x1, float y1, float x2, float y2, t_game *game)
// {
// 	float	delta_x;
// 	float	delta_y;
// 	float	angle;
// 	float	fix_dist;

// 	delta_x = x2 - x1;
// 	delta_y = y2 - y1;
// 	angle = atan2(delta_y, delta_x) - game->player.angle;
// 	fix_dist = distance(delta_x, delta_y) * cos(angle);
// 	return (fix_dist);
// }

int	color_to_c(t_c c)
{
	return ((c.red << 16) | (c.green << 8) | c.blue);
}

int	color_to_f(t_f f)
{
	return ((f.red << 16) | (f.green << 8) | f.blue);
}

int	close_window(void *tmp)
{
	t_game	*game;

	game = (t_game *)tmp;
	if (game)
	{
		destroy(game, " close");
		exit(0);
	}
	return (0);
}
