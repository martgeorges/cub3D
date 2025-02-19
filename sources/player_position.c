/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:40:54 by mgeorges          #+#    #+#             */
/*   Updated: 2025/02/19 12:50:35 by mgeorges         ###   ########.fr       */
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

//int find_player(char **map, t_player *player)
int find_player(t_data	*data)
{
    int y = 0;
    printf("Map contents:\n");
    int map_row = 0;
    while (data->game.map[map_row])
    {
        printf("%s\n", data->game.map[map_row]);
        map_row++;
    }

    while (data->game.map[y])
    {
        int x = 0;
        while (data->game.map[y][x])
        {
            printf("Checking position: x = %d, y = %d, char = %c\n", x, y, data->game.map[y][x]);
            if (data->game.map[y][x] == 'N' || data->game.map[y][x] == 'S' || data->game.map[y][x] == 'E' || data->game.map[y][x] == 'W')
            {
                data->game.player.p_x = (float)x;
                data->game.player.p_y = (float)y;
                data->game.player.view_angle = get_angle(data->game.map[y][x]);

                if (data->game.player.view_angle == -1)
                {
                    printf("Error: Angle not recognized!\n");
                    return 0;
                }
                data->game.map[y][x] = '0'; // remplace le joueur par '0' une fois trouvé
                printf("Initial player position: x = %f, y = %f, angle = %f\n",
                       data->game.player.p_x, data->game.player.p_y, data->game.player.view_angle);
                return 1; //1 pour indiquer qu'on a trouvé le joueur
            }
            x++;
        }
        y++;
    }
    printf("Error: Player not found in map!\n");
    return 0; // 0 si aucun joueur trouvé
}

/*void	find_player(char **map, t_player *player)
{
	int y;

	y = 0;
	printf("Map contents: \n");
	int	map_row = 0;
	while (map[map_row])
    {
        printf("%s\n", map[map_row]);
        map_row++;
    }
	while (map[y])
	{
		int x = 0;
		while (map[y][x])
		{
			printf("checking position : x = %d, y = %d, char = %c\n", x, y, map[y][x]);
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E'
				|| map[y][x] == 'W')
            {
                player->p_x = (float)x;
                player->p_y = (float)y;
                player->view_angle = get_angle(map[y][x]);
				if (player->view_angle == -1)
				{
					printf("error : angle not good\n");
					return;
				}
				map[y][x] = '0';
				printf("initial player position : x = %f, y = %f, angle = %f\n",player->p_x, player->p_y, player->view_angle);
				return;
            }
			x++;
		}
		y++;
	}
}*/
