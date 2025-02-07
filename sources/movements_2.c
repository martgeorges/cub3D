/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:52:54 by mgeorges          #+#    #+#             */
/*   Updated: 2025/02/07 11:16:30 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void    move_up(t_player *player, char **map)
{
    //find_player(map, player);
    printf("Player position before move: p_x = %f, p_y = %f, angle before = %f\n", player->p_x, player->p_y, player->view_angle);
    float new_x = player->p_x + cos(player->view_angle * M_PI / 180);
    float new_y = player->p_y + sin(player->view_angle * M_PI / 180);
    printf("Trying to move to: new_x = %f, new_y = %f\n", new_x, new_y);

    if (can_move(map, new_y, new_x))
    {
        player->p_x = new_x;
        player->p_y = new_y;
    }
}

void    move_down(t_player *player, char **map)
{
    printf("Player position before move: p_x = %f, p_y = %f\n", player->p_x, player->p_y);
    float new_x = player->p_x - cos(player->view_angle * M_PI / 180);
    float new_y = player->p_y - sin(player->view_angle * M_PI / 180);

    printf("Trying to move to: new_x = %f, new_y = %f\n", new_x, new_y);
    
    if (can_move(map, new_y, new_x))
    {
        printf("Move allowed: Updating player position\n");
        player->p_x = new_x;
        player->p_y = new_y;
    }
    else
    {
        printf("move blocked \n");
    }
}

int up_down(t_game *game, int direction)
{
    t_player *player = &game->player;
    
    if (direction == 119 || direction == 65362)
        move_up(player, game->map);
    else if (direction == 115 || direction == 65364)
        move_down(player, game->map);
    return (1);
}