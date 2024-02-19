/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:04:17 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/19 16:03:28 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	key_hook(int keycode)
{
	if (keycode == 53)   // Código de tecla 'Esc'
		ft_close();
    else if (keycode == 124 || keycode == 2)
        printf("Nos hemos movido a la derecha\n");
    else if (keycode == 126 || keycode == 13)
        printf("Nos hemos movido hacia arriba\n");
    else if (keycode == 123 || keycode == 0)
        printf("Nos hemos movido a la izquierda\n");
    else if (keycode == 125 || keycode == 1)
        printf("Nos hemos movido hacia abajo\n");
	/*else
		printf("Has presionado una tecla con código: %d\n", keycode);*/
	return (0);
}

void    init_game(t_data *info, t_img *map)
{
    int img_width;
    int img_height;
    char *relative_path = "hp.xpm";
    char *relative_path_2 = "grass.xpm";
    map->mlx = mlx_init();
    map->mlx_window = mlx_new_window(map->mlx, info->n_row * 50, \
    info->n_col * 50, "so_long");
    mlx_key_hook(map->mlx_window, key_hook, &map);
    map->img = mlx_xpm_file_to_image(map->mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(map->mlx, map->mlx_window, map->img, info->player_col * 50, info->player_row * 50);
    map->img2 = mlx_xpm_file_to_image(map->mlx, relative_path_2, &img_width, &img_height);
    int row = 0;
    int col = 1;
  
    mlx_put_image_to_window(map->mlx, map->mlx_window, map->img2, row * 50, col * 50);
    row = 1;
    col = 0;
    mlx_put_image_to_window(map->mlx, map->mlx_window, map->img2, row * 50, col * 50);
    row = 0;
    col = 0;
    mlx_put_image_to_window(map->mlx, map->mlx_window, map->img2, row * 50, col * 50);
    mlx_put_image_to_window(map->mlx, map->mlx_window, map->img2, info->player_col * 50, info->player_row * 50);
    mlx_put_image_to_window(map->mlx, map->mlx_window, map->img, info->player_col * 50, info->player_row * 50);
       
    mlx_hook(map->mlx_window, 17, 0, ft_close, map);
    mlx_loop(map->mlx);
}