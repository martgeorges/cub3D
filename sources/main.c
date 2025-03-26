/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgeorges <mgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 09:30:15 by mgeorges          #+#    #+#             */
/*   Updated: 2025/03/26 07:24:22 by mgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int main(int ac, char **av)
{
    t_data *game;
    int y; 
	int x;

    check_error(ac, av);
    game = malloc(sizeof(t_data));
    if (!game)
    {
        printf("\033[31mError: malloc failed for game struct\033[0m\n");
        return (1);
    }
    game->map = read_map_file(av[1]);
    display_messages(game->map);
    check_textures_and_colors(game->map);
    game->map_height = 0;
    game->map_width = 0;
    while (game->map[game->map_height])
    {
        if ((int)strlen(game->map[game->map_height]) > game->map_width)
            game->map_width = strlen(game->map[game->map_height]);
        game->map_height++;
    }
    y = 0;
    while (game->map[y])
    {
        parse_map_info(game, game->map[y]);
        y++;
    }
    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            if (game->map[y][x] == 'N' || game->map[y][x] == 'S' ||
                game->map[y][x] == 'E' || game->map[y][x] == 'W')
            {
                game->player.x = x + 0.5;
                game->player.y = y + 0.5;
                if (game->map[y][x] == 'N')
                    game->player.angle = 3 * M_PI / 2;
                else if (game->map[y][x] == 'S')
                    game->player.angle = M_PI / 2;
                else if (game->map[y][x] == 'E')
                    game->player.angle = 0;
                else if (game->map[y][x] == 'W')
                    game->player.angle = M_PI;
                game->map[y][x] = '0';
            }
            x++;
        }
        y++;
    }
    if (!is_map_closed(game))
    {
        printf("\033[31mError: Map is not closed.\033[0m\n");
        return (1);
    }
    game->mlx = mlx_init();
    if (!game->mlx)
        return (1);
    if (game->floor_color == -1 || game->ceiling_color == -1)
    {
        printf("\033[31mError: invalid colors in -> .cub\033[0m\n");
        return (1);
    }
    if (!load_textures_from_map(game, av[1]))
    {
        printf("\033[31mError loading textures from map.\033[0m\n");
        return (1);
    }
    printf("Game starting...\n\n");
    printf("░█▀▀░█░█░█▀▄░▀▀█░█▀▄░░\n");
    printf("░█░░░█░█░█▀▄░░▀▄░█░█░░\n");
    printf("░▀▀▀░▀▀▀░▀▀░░▀▀░░▀▀░░░\n");
    game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
    if (!game->win)
        return (1);
    game->img.img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (!game->img.img)
        return (1);
    game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
            &game->img.line_length, &game->img.endian);
    game->cell_size = 20;
    ft_memset(game->keys, 0, sizeof(game->keys));
    raycasting(game);
    mlx_hook(game->win, 2, (1L << 0), key_press, game);
    mlx_hook(game->win, 3, (1L << 1), key_release, game);
    mlx_loop_hook(game->mlx, update_game, game);
    mlx_hook(game->win, 17, 0, close_window, game);
    mlx_loop(game->mlx);
    close_window(game);
    return (0);
}
