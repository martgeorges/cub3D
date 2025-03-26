/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 08:17:26 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/26 09:05:53 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
//# include "../minilibx-macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#ifndef M_PI
#define M_PI 3.141592653589793
#endif

// raycasting
# define FOV 1.0471975512

// Controls
# define ROT_SPEED 0.01
# define MOVE_SPEED 0.01
# define LEFT 0
# define RIGHT 1
# define FORWARD 2
# define BACKWARD 3
# define STRAFE_LEFT 4
# define STRAFE_RIGHT 5

# define BUFFER_SIZE 1024
# define MAX_LINES 1000
# define MAX_COLS 1000

# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;
	char		direction;
}				t_player;

typedef struct s_image
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_texture
{
	t_image		wall_north;
	t_image		wall_south;
	t_image		wall_east;
	t_image		wall_west;
}				t_texture;

typedef struct s_ray
{
	double		x;
	double		y;
	double		dx;
	double		dy;
	int			map_x;
	int			map_y;
	double		delta_dist_x;
	double		delta_dist_y;
}				t_ray;

typedef struct s_step
{
	int			x;
	int			y;
	double		dist_x;
	double		dist_y;
}				t_step;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_width;
	int			map_height;
	int			cell_size;
	t_player	player;
	t_texture	textures;
	t_image		img;
	t_ray		ray;
	int			keys[512];
	int			ceiling_color;
	int			floor_color;
}				t_data;

typedef struct s_texture_info
{
	int			start;
	int			end;
	int			texture_x;
	int			wall_height;
}				t_texture_info;

// map
char			**read_map_file(char *filename);

// Raycasting
void			raycasting(t_data *game);
void			clear_background(t_data *game);
void			draw_column(t_data *game, int x, double perp_dist, int side);
void			cast_ray(t_data *game, double angle, double *perp_dist,
					int *side);
void			init_ray(t_data *game, double angle);
void			set_step(t_data *game, t_step *step);
void			perform_dda(t_data *game, t_step *step, int *side);
void			calculate_perp_dist(t_data *game, t_step *step, int side,
					double *perp_dist);
void			determine_ray_step(t_data *game, t_step *step, int *side);

// draw column utils
t_image			*get_texture(t_data *game, int side);
void			get_column_dimensions(int *start, int *end, int *wall_height,
					double perp_dist);
int				get_texture_x(t_data *game, t_image *texture, double perp_dist,
					int side);
void			draw_texture_column(t_data *game, int x, t_image *texture,
					t_texture_info *info);

// handling player & keyboard
int				update_game(t_data *game);
int				key_release(int keycode, t_data *game);
int				key_press(int keycode, t_data *game);

// textures
void			parse_map_info(t_data *game, char *line);
int				load_texture(t_data *game, t_image *texture,
					const char *file_path);
// int				load_textures_wall(t_data *game);

// test textures
char			*get_next_line(int fd);
int				load_texture(t_data *game, t_image *texture,
					const char *file_path);
int				load_texture_by_id(t_data *game, char *line, t_image *texture);
int				load_textures_from_map(t_data *game, const char *map_file);
int				parse_map_file(t_data *game, const char *map_file);

// error management
int				is_cub_file(const char *filename);
int				check_error(int ac, char **av);

// map error
void			display_messages(char **map);

int				is_line_empty(char *line);
void			check_cub_file(char **map);
int				is_map_line(char *line);
void			check_textures_and_colors(char **map);
void			print_info(int has_map);

int is_map_closed(t_data *game);

// memory management
void			free_textures(t_data *game);
void			conditions_for_closing(t_data *data);

// mlx utils
int				close_window(t_data *data);
void			print_map(char **map);
void			free_map(char **map);

// libft
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memcpy(void *dest, void const *src, size_t n);
void			*ft_memset(void *str, int c, size_t n);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
char			**ft_split(char const *s, char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(const char *s, const char *set);

#endif