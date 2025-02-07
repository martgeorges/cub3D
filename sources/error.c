/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:11:41 by mgeorges          #+#    #+#             */
/*   Updated: 2025/02/07 10:28:52 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

//check si il y a un autre charactère que 1, 0 ou N S E W ou c 
void    check_map(t_game *game)
{
    while (game->map)
    {
        if (game->map != '1' && game->map != '0')
        {
            printf("error : no walls or floor\n");
        }
    }
}