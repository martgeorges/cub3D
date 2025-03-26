/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:06:22 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/26 17:10:28 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	is_line_empty(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t' && *line != '\n')
			return (0);
		line++;
	}
	return (1);
}

void	check_cub_file(char **map)
{
	int	i;
	int	has_map;
	int	has_content;

	i = 0;
	has_map = 0;
	has_content = 0;
	while (map[i])
	{
		if (!is_line_empty(map[i]))
			has_content = 1;
		if (!ft_strncmp(map[i], "NO", 2) || !ft_strncmp(map[i], "SO", 2)
			|| !ft_strncmp(map[i], "WE", 2) || !ft_strncmp(map[i], "EA", 2)
			|| !ft_strncmp(map[i], "F", 1) || !ft_strncmp(map[i], "C", 1))
			has_map = 1;
		i++;
	}
	if (!has_content)
	{
		printf("\033[31mError: [.cub] file is completely empty.\033[0m\n");
		exit(EXIT_FAILURE);
	}
	print_info(has_map);
}

void	print_info(int has_map)
{
	if (!has_map)
	{
		printf("\033[31mError: only map in file\033[0m\n");
		exit(EXIT_FAILURE);
	}
}
