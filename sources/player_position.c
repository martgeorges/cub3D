/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:40:54 by mgeorges          #+#    #+#             */
/*   Updated: 2025/02/06 10:48:46 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	get_angle(char c)
{
	if (c == 'N')
		return 90;
	if (c == 'S')
		return 270;
	if (c == 'E')
		return 0;
	if (c == 'W')
		return 180;
	return -1;
}

void	find_player(char **map, t_player *player)
{
	int y;

	y = 0;
	while (map[y])
	{
		int x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
            {
                player->p_x = x;
                player->p_y = y;
                player->view_angle = get_angle(map[y][x]);

				map[y][x] = '0';
				return;
            }
			x++;
		}
		y++;
	}
}