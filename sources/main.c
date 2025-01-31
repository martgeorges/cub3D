/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:30:15 by mgeorges          #+#    #+#             */
/*   Updated: 2025/01/10 10:31:39 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int main(int ac, char **av)
{
    //init arguments entered into params
        // si 2 args OK, sinon KO
    if (ac != 2)
    {
        printf("error: ./cub3D maps/map.cub");
        return (1);
    }
    //init window with minilibx adequate functions
    //free pour eviter les leaks 
    //puis exit proprement avec fonction exit 
}
