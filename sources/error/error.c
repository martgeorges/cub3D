/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 13:30:53 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/26 20:46:09 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_cub_file(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
	{
		printf("\033[31mError: file needs to have .cub\033[0m\n");
		return (0);
	}
	if (filename[len - 4] != '.' || filename[len - 3] != 'c' || filename[len
			- 2] != 'u' || filename[len - 1] != 'b')
	{
		printf("\033[31mError: file needs to have extension .cub\033[0m\n");
		return (0);
	}
	return (1);
}

int	check_error(int ac, char **av)
{
	if (ac != 2)
	{
		printf("\033[31mError: ./cub3D maps/pathtomap.cub\033[0m\n");
		exit(1);
	}
	if (!is_cub_file(av[1]))
	{
		exit(1);
	}
	return (1);
}
