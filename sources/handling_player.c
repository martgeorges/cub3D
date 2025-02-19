/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:03:07 by mgeorges          #+#    #+#             */
/*   Updated: 2025/02/19 07:20:35 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//macos
/*int	keyboard_handler(int keycode, t_data *data)
{
    int command;

    command = 0;
	if (keycode == 53)
		close_window(data);
    if (keycode == 13 || keycode == 126)
        command = up_down(&data->game, 126);
    if (keycode == 1 || keycode == 125)
        command = up_down(&data->game, 125);
    if (command)
    {
        printf("ok well used %d, keycode == %d\n", command, keycode);
    }
    return (0);
    if (keycode == 0 || keycode == 123)
        command = ; //right_left
    if (keycode == 2 || keycode == 124)
        command = ; //right_left
	return (0);
}*/

//linux
int	keyboard_handler(int keycode, t_data *data)
{
    int command;

    command = 0;
	if (keycode == 65307)
		close_window(data);
    if (keycode == 119 || keycode == 65362)
        command = up_down(&data->game, 119);
    if (keycode == 115 || keycode == 65364)
        command = up_down(&data->game, 115);
    return (0);
}

    /*if (keycode == 97 || keycode == 65361)
        command = ; //right_left
    if (keycode == 124 || keycode == 65363)
        command = ; //right_left*/