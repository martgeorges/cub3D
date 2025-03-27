/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_floor_ceiling.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:43:42 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/27 13:09:31 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	handle_color_error(const char *msg)
{
	printf("\033[31mError: %s\033[0m\n", msg);
	exit(EXIT_FAILURE);
}

int	parse_color(char *line, t_data *game)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;
	int		color;

	while (*line == ' ')
		line++;
	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		free_map(game->map);
		if (rgb)
		{
			int i = 0;
			while (rgb[i])
			{
				free(rgb[i]);
				i++;
			}
			free(rgb);
		}
		handle_color_error("Invalid format must be 'R, G, B' with 3 values.");
		return (-1);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_map(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	color = (r << 16) | (g << 8) | b;
	return (color);
}

void	parse_map_info(t_data *game, char *line)
{
	while (*line == ' ')
		line++;
	if (*line == 'F')
		game->floor_color = parse_color(line + 1, game);
	else if (*line == 'C')
		game->ceiling_color = parse_color(line + 1, game);
}
