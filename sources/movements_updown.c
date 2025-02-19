/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:52:54 by mgeorges          #+#    #+#             */
/*   Updated: 2025/02/19 11:21:56 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//void    move_up(t_player *player, char **map)
void    move_up(t_game *game, char **map)
{
    //(void) map;
    //(void) game;
    //printf("position x : %f\n", game->player.p_x);
    printf("Player position before move: p_x = %f, p_y = %f, angle before = %f\n", game->player.p_x, game->player.p_y, game->player.view_angle);
    //printf("Player position before move:\n");
       
    float new_x = game->player.p_x + cos(game->player.view_angle * M_PI / 180);
    float new_y =game->player.p_y + sin(game->player.view_angle * M_PI / 180);
    
    printf("Trying to move to: new_x = %f, new_y = %f, new_angle = %f\n", new_x, new_y, game->player.view_angle);

    if (can_move(map, new_y, new_x))
    {
        game->player.p_x = new_x;
        game->player.p_y = new_y;
    }
    
}

void    move_down(t_game *game, char **map)
{
    //(void) map;
    //(void) game;
    //printf("position x : %f\n", game->player.p_x);
    printf("Player position before move: p_x = %f, p_y = %f, angle before = %f\n", game->player.p_x, game->player.p_y, game->player.view_angle);
    //printf("Player position before move:\n");
       
    float new_x = game->player.p_x - cos(game->player.view_angle * M_PI / 180);
    float new_y =game->player.p_y - sin(game->player.view_angle * M_PI / 180);
    
    printf("Trying to move to: new_x = %f, new_y = %f\n", new_x, new_y);

    if (can_move(map, new_y, new_x))
    {
        game->player.p_x = new_x;
        game->player.p_y = new_y;
    }
    
}

int up_down(t_game *game, int direction)
{
    //t_player *player = &game->player;

    if (direction == 119 || direction == 65362)
        move_up(game, game->map);
    else if (direction == 115 || direction == 65364)
        move_down(game, game->map);
    return (1);
}
