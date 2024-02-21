/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:57:58 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/21 16:06:15 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_up(t_data *info, t_img *map)
{
    printf("%d\n", info->player_row);
    printf("%d\n", info->player_col);
    info->player_row += 1;
    ft_map(info, map);
    printf("%d\n", info->player_row);    
    printf("%d\n", info->player_col);
}