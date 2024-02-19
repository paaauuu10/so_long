/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:04:17 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/19 12:21:23 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

int	key_hook(int keycode)
{
	if (keycode == 53)   // Código de tecla 'Esc'
		printf("Saliendo...\n");
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
    map->mlx = mlx_init();
    map->mlx_window = mlx_new_window(map->mlx, info->n_row * 32, \
    info->n_col * 32, "so_long");
    mlx_key_hook(map->mlx_window, key_hook, &map);
	//mlx_hook(data.mlx_w, 17, 0, &ft_esc, &data);
    mlx_loop(map->mlx);
}