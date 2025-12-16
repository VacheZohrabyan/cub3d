/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:42:53 by vzohraby          #+#    #+#             */
/*   Updated: 2025/12/15 13:15:58 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void init_player(t_game* game, t_player* player, int width, int heigth)
{
    (void)width;
    (void)heigth;
    (void)game;
    // player->x = width / 2;
    // player->y = heigth / 2;
    player->key_down = 0;
    player->key_left = 0;
    player->key_right = 0;
    player->key_up = 0;
    player->angle = PI / 2;
    player->left_rotate = 0;
    player->right_rotate = 0;
}

int key_press(int keycode, t_player* player)
{
    if (keycode == LEFT)
        player->left_rotate = 1;
    if (keycode == RIGHT)
        player->right_rotate = 1;
    if (keycode == W)
        player->key_up = 1;
    if (keycode == S)
        player->key_down = 1;
    if (keycode == A)
        player->key_left = 1;
    if (keycode == D)
        player->key_right = 1;
    if (keycode == LEFT)
        player->left_rotate = 1;
    if (keycode == RIGHT)
        player->right_rotate = 1;
    return (0);
}

int key_realse(int keycode, t_player* player)
{
    if (keycode == LEFT)
        player->left_rotate = 0;
    if (keycode == RIGHT)
        player->right_rotate = 0;
    if (keycode == W)
        player->key_up = 0;
    if (keycode == S)
        player->key_down = 0;
    if (keycode == A)
        player->key_left = 0;
    if (keycode == D)
        player->key_right = 0;
    if (keycode == LEFT)
        player->left_rotate = 0;
    if (keycode == RIGHT)
        player->right_rotate = 0;
    return (1);
}

static int beyond_the_wall(t_game* game, float x, float y)
{
    int map_x = (int)(x / BLOCK);
    int map_y = (int)(y / BLOCK);

    int map_h = game->map_size_line;

    if (map_y < 0 || map_y >= map_h)
        return (1);
    if (map_x < 0 || map_x >= (int)ft_strlen(game->map[map_y]))
        return (1);

    return (game->map[map_y][map_x] == '1');
}

void move_player(t_game* game, t_player* player)
{
    int speed = 3;
    float angle_speed = 0.03;
    float cos_angle = cos(player->angle);
    float sin_angle = sin(player->angle);

    int new_x = player->x;
    int new_y = player->y;

    if (player->left_rotate)
        player->angle -= angle_speed;
    if (player->right_rotate)
        player->angle += angle_speed;
    if (player->angle > 2 * PI)
        player->angle = 0;
    if (player->angle < 0)
        player->angle = 2 * PI;
    
    if (player->key_up)
    {
        new_x += cos_angle * speed;
        new_y += sin_angle * speed;
    }
    if (player->key_down)
    {
        new_x -= cos_angle * speed;
        new_y -= sin_angle * speed;
    }
    if (player->key_left)
    {
        new_x += sin_angle * speed;
        new_y -= cos_angle * speed;
    }
    if (player->key_right)
    {
        new_x -= sin_angle * speed;
        new_y += cos_angle * speed;
    }
    
    if (!beyond_the_wall(game, new_x, new_y))
    {
        player->x = new_x;
        player->y = new_y;            
    }
    
}