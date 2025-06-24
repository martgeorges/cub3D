/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:44:37 by mgeorges          #+#    #+#             */
/*   Updated: 2025/04/04 07:06:39 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_last_line(char **map)
{
	int	last_line;
	int	i;

	last_line = -1;
	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], '1') || ft_strchr(map[i], '0')
			|| ft_strchr(map[i], 'N') || ft_strchr(map[i], 'S')
			|| ft_strchr(map[i], 'E') || ft_strchr(map[i], 'W'))
		{
			last_line = i;
		}
		i++;
	}
	return (last_line);
}

int	check_invalid_characters_after_last_line(char **map, int last_line)
{
	int	i;
	int	j;

	i = last_line + 1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '\t' && map[i][j] != '\n'
				&& map[i][j] != '\r')
			{
				printf("\033[31mError: found something after map\033[0m\n");
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

	last_line = check_last_line(map);
	if (!check_invalid_characters_after_last_line(map, last_line))
	{
		return (0);
	}
	return (1);
}
