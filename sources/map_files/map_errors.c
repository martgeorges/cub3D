/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 09:53:09 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/26 20:55:55 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static int	analyze_line(char *line)
{
	int	j;
	int	player_count;

	j = 0;
	player_count = 0;
	while (line[j] == ' ' || line[j] == '\t')
		j++;
	if (!(ft_strncmp(line, "NO", 2) == 0 || ft_strncmp(line, "SO", 2) == 0
			|| ft_strncmp(line, "WE", 2) == 0 || ft_strncmp(line, "EA",
				2) == 0))
	{
		while (line[j])
		{
			if (line[j] == 'N' || line[j] == 'S' || line[j] == 'E'
				|| line[j] == 'W')
			{
				player_count++;
				//printf("Joueur détecté: %c à la position: %d dans la ligne:%s\n", line[j], j, line);
			}
			j++;
		}
	}
	return (player_count);
}

static int	count_players(char **map, int start)
{
	int	i;
	int	player_count;

	player_count = 0;
	i = start;
	while (map[i])
	{
		player_count += analyze_line(map[i]);
		i++;
	}
	return (player_count);
}

static int	get_start_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (ft_strncmp(map[i], "NO", 2) != 0 && ft_strncmp(map[i], "SO", 2) != 0
			&& ft_strncmp(map[i], "WE", 2) != 0 && ft_strncmp(map[i], "EA",
				2) != 0 && ft_strncmp(map[i], "F", 1) != 0 && ft_strncmp(map[i],
				"C", 1) != 0)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

//static void	normalize_texture_lines(char **map);

void	display_messages(char **map)
{
	int	start_map;
	int	player_count;

	//normalize_texture_lines(map);
	start_map = get_start_map(map);
	check_cub_file(map);
	if (start_map == -1)
	{
		printf("\033[31mError: Map not found in the file\033[0m\n");
		exit(EXIT_FAILURE);
	}
	player_count = count_players(map, start_map);
	if (player_count != 1)
	{
		printf("\033[31mError: map must contain exactly [1] player.\033[0m\n");
		printf("\033[31m->Number of players: [%d]\033[0m\n", player_count);
		exit(EXIT_FAILURE);
	}
}

/*static void	normalize_texture_lines(char **map)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ' || map[i][j] == '\t')
			// Ignorer les espaces/tabs en début de ligne
			j++;
		if (!ft_strncmp(&map[i][j], "NO", 2) || !ft_strncmp(&map[i][j], "SO", 2)
			|| !ft_strncmp(&map[i][j], "WE", 2) || !ft_strncmp(&map[i][j], "EA",
				2)
			|| !ft_strncmp(&map[i][j], "F", 1) || !ft_strncmp(&map[i][j], "C",
				1))
		{
			new_line = strdup(&map[i][j]);
				// On copie la ligne sans les espaces avant
			if (!new_line)
			{
				printf("\033[31mError: Memory allocation failed.\033[0m\n");
				exit(EXIT_FAILURE);
			}
			free(map[i]); // On libère l'ancienne ligne
			map[i] = new_line; // On met la nouvelle ligne sans espaces
		}
		i++;
	}
}*/
