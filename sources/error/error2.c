/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:44:37 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/03 11:47:56 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	get_last_valid_line(char **map)
{
	int	last_line;
	int	i;

	last_line = 0;
	i = 0;
	while (map[i])
	{
		if (strchr(map[i], '1') || strchr(map[i], '0') || strchr(map[i], 'N')
			|| strchr(map[i], 'S') || strchr(map[i], 'E') || strchr(map[i],
				'W'))
			last_line = i;
		i++;
	}
	return (last_line);
}

int	check_trailing_lines(char **map, int last_line)
{
	int	i;
	int	j;

	i = last_line + 2;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '\t' && map[i][j] != '\n'
				&& map[i][j] != '\r')
			{
				printf("\033[31mError: content on line %d\033[0m\n", i);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map_end(char **map)
{
	int	last_line;

	if (!map)
		return (0);
	last_line = get_last_valid_line(map);
	return (check_trailing_lines(map, last_line));
}
