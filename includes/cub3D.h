/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:17:26 by mgeorges          #+#    #+#             */
/*   Updated: 2025/02/03 12:58:12 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
//# include "../minilibx-macos/mlx.h"
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

// main

// map

char		**read_map_file(char *filename);
// handling player & keyboard

// mlx utils
int			close_window(t_data *data);
int			keyboard_handler(int keycode, t_data *data);
void		print_map(char **map);
void		free_map(char **map);

#endif