/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:04:17 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/19 11:34:27 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./mlx/mlx.h"

void    init_game(t_data *info, t_img *map)
{
    map->mlx = mlx_init();
    map->mlx_window = mlx_new_window(map->mlx, info->n_row * 32, \
    info->n_col * 32, "so_long");
    mlx_loop(map->mlx);
}