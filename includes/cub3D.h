/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:17:26 by mgeorges          #+#    #+#             */
/*   Updated: 2025/02/05 14:45:25 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//# include "../minilibx-linux/mlx.h"
# include "../minilibx-macos/mlx.h"
//# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define BUFFER_SIZE 1024
# define MAX_LINES 100
# define MAX_COLS 100

typedef struct s_data
{
	void	*mlx;
	void	*win;
}			t_data;

typedef struct s_map
{
    char *textures[4]; // NO, SO, WE, EA
    int floor[3];
    int ceiling[3];
} t_map;

typedef	struct s_game
{
	char	**map;
	int	height;
	int	width;
	
}	t_game;

typedef struct s_player
{
	float	p_x;
	float	p_y;
	float	view_angle;
}	t_player;

// main

// map

char		**read_map_file(char *filename);
// handling player & keyboard
int	get_angle(char c);
void	find_player(char **map, t_player *player);
// textures

// mlx utils
int			close_window(t_data *data);
int			keyboard_handler(int keycode, t_data *data);
void		print_map(char **map);
void		free_map(char **map);

// libft

void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memcpy(void *dest, void const *src, size_t n);

#endif