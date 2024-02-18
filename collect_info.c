/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:36:13 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/18 14:54:37 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_n_coins(t_data *info)
{
    int col;
    int row;

    row = 0;
    while (info->map[row])
    {
        col = 0;
        while(info->map[row][col])
        {
            if (info->map[row][col] == 'C')
                info->n_coins++;
            col++;
        }
        row++;
    }
    if (info->n_coins < 1)
        ft_error_free("No collectable objects found", info);
}

void    ft_player_position(t_data *info)
{
    int col;
    int row;

    row = 0;
    while (info->map[row])
    {
        col = 0;
        while(info->map[row][col])
        {
            if (info->map[row][col] == 'P')
            {
                info->player_row = row;
                info->player_col = col;
                return ;
            }
            col++;
        }
        row++;
    }


}

void    ft_collect_info(t_data *info)
{
    ft_n_coins(info);
    ft_player_position(info);
    ft_exit_position(info); /*must do*/
}