/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_macos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:52:49 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/24 10:44:04 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	movement_qd(t_data *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	if (game->keys[STRAFE_LEFT])
	{
		new_x -= cos(game->player.angle + M_PI / 2) * MOVE_SPEED;
		new_y -= sin(game->player.angle + M_PI / 2) * MOVE_SPEED;
	}
	if (game->keys[STRAFE_RIGHT])
	{
		new_x -= cos(game->player.angle - M_PI / 2) * MOVE_SPEED;
		new_y -= sin(game->player.angle - M_PI / 2) * MOVE_SPEED;
	}
	if (game->map[(int)new_y][(int)new_x] != '1')
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

void	movement_zs(t_data *game)
{
	float	new_x;
	float	new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	if (game->keys[FORWARD])
	{
		new_x += cos(game->player.angle) * MOVE_SPEED;
		new_y += sin(game->player.angle) * MOVE_SPEED;
	}
	if (game->keys[BACKWARD])
	{
		new_x -= cos(game->player.angle) * MOVE_SPEED;
		new_y -= sin(game->player.angle) * MOVE_SPEED;
	}
	if (game->map[(int)new_y][(int)new_x] != '1')
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

int	update_game(t_data *game)
{
	movement_zs(game);
	movement_qd(game);
	if (game->keys[LEFT])
		game->player.angle -= ROT_SPEED;
	if (game->keys[RIGHT])
		game->player.angle += ROT_SPEED;
	raycasting(game);
	return (0);
}

int	key_press(int keycode, t_data *game)
{
	if (keycode == 53)
		close_window(game);
	if (keycode == 123)
		game->keys[LEFT] = 1;
	else if (keycode == 124)
		game->keys[RIGHT] = 1;
	else if (keycode == 13)
		game->keys[FORWARD] = 1;
	else if (keycode == 1)
		game->keys[BACKWARD] = 1;
	else if (keycode == 0)
		game->keys[STRAFE_LEFT] = 1;
	else if (keycode == 2)
		game->keys[STRAFE_RIGHT] = 1;
	return (0);
}

int	key_release(int keycode, t_data *game)
{
	if (keycode == 123)
		game->keys[LEFT] = 0;
	else if (keycode == 124)
		game->keys[RIGHT] = 0;
	else if (keycode == 13)
		game->keys[FORWARD] = 0;
	else if (keycode == 1)
		game->keys[BACKWARD] = 0;
	else if (keycode == 0)
		game->keys[STRAFE_LEFT] = 0;
	else if (keycode == 2)
		game->keys[STRAFE_RIGHT] = 0;
	return (0);
}
