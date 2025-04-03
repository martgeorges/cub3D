/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncollign <ncollign@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 13:30:34 by ncollign          #+#    #+#             */
/*   Updated: 2025/04/03 14:00:13 by ncollign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_tab(int tab[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
}

int	is_texture_line(char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		return (1);
	if (ft_strncmp(line, "SO", 2) == 0)
		return (1);
	if (ft_strncmp(line, "WE", 2) == 0)
		return (1);
	if (ft_strncmp(line, "EA", 2) == 0)
		return (1);
	if (ft_strncmp(line, "F", 1) == 0)
		return (1);
	if (ft_strncmp(line, "C", 1) == 0)
		return (1);
	return (0);
}

int	is_empty_line(char *line)
{
	while (*line)
	{
		if (!ft_isspace(*line))
			return (0);
		line++;
	}
	return (1);
}
