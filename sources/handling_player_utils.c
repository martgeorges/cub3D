/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_player_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:28:19 by mgeorges          #+#    #+#             */
/*   Updated: 2025/01/31 11:38:40 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int up_down(t_game *game, int direction)
{
    int new_y = game->player_y + direction;

    if (game->map[new_y][game->player_x] == '0')
    {
        game->player_y = new_y;
        return (1);
    }
    return (0);
}

int right_left(t_game *game, int direction)
{
    int new_x = game->player_x + direction;

    if (game->map[game->player_y][new_x] == '0')
    {
        game->player_x = new_x;
        return (1);
    }
    return (0);
}
