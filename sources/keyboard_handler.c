/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:48:51 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/16 18:36:39 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
	if (keycode == 65307)
		close_window(game);
	if (keycode == 65361)
		game->keys[LEFT] = 1;
	else if (keycode == 65363)
		game->keys[RIGHT] = 1;
	else if (keycode == 122)
		game->keys[FORWARD] = 1;
	else if (keycode == 115)
		game->keys[BACKWARD] = 1;
	else if (keycode == 113)
		game->keys[STRAFE_LEFT] = 1;
	else if (keycode == 100)
		game->keys[STRAFE_RIGHT] = 1;
	return (0);
}

int	key_release(int keycode, t_data *game)
{
	if (keycode == 65361)
		game->keys[LEFT] = 0;
	else if (keycode == 65363)
		game->keys[RIGHT] = 0;
	else if (keycode == 122)
		game->keys[FORWARD] = 0;
	else if (keycode == 115)
		game->keys[BACKWARD] = 0;
	else if (keycode == 113)
		game->keys[STRAFE_LEFT] = 0;
	else if (keycode == 100)
		game->keys[STRAFE_RIGHT] = 0;
	return (0);
}
