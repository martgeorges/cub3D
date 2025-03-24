/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:55:03 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/24 10:43:21 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_map_line(char *line)
{
	while (*line)
	{
		if (*line == '1' || *line == '0' || *line == 'N' || *line == 'S'
			|| *line == 'E' || *line == 'W')
			return (1);
		line++;
	}
	return (0);
}

void	check_textures_and_colors(char **map)
{
	int	i;
	int	has_no;
	int	has_so;
	int	has_we;
	int	has_ea;
	int	has_floor;
	int	has_ceiling;

	has_no = 0;
	has_so = 0;
	has_we = 0;
	has_ea = 0;
	has_floor = 0;
	has_ceiling = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], "NO", 2) == 0)
			has_no = 1;
		else if (ft_strncmp(map[i], "SO", 2) == 0)
			has_so = 1;
		else if (ft_strncmp(map[i], "WE", 2) == 0)
			has_we = 1;
		else if (ft_strncmp(map[i], "EA", 2) == 0)
			has_ea = 1;
		else if (ft_strncmp(map[i], "F", 1) == 0)
			has_floor = 1;
		else if (ft_strncmp(map[i], "C", 1) == 0)
			has_ceiling = 1;
		else if (is_map_line(map[i]))
			break ;
		i++;
	}
	if (!has_no || !has_so || !has_we || !has_ea)
	{
		printf("\033[31mError: Missing (NO, SO, WE,EA) in the file.\033[0m\n");
		exit(EXIT_FAILURE);
	}
	if (!has_floor || !has_ceiling)
	{
		printf("\033[31mError: Missing colors (F and/or C) in the file.\033[0m\n");
		exit(EXIT_FAILURE);
	}
}