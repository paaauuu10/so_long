/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:36:13 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/18 15:52:34 by pbotargu         ###   ########.fr       */
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
void    ft_fill(t_data *info, int player_col, int player_row)
{
    if ((player_col < 0 || player_row < 0 || player_col >= info->n_row || \
    player_row >= info->n_col || info->map[player_row][player_col] != '0') \
    && (info->map[player_row][player_col] != 'C' \
    && info->map[player_row][player_col] != 'P' \
    && info->map[player_row][player_col] != 'E'))
        return ;
    if (info->map[player_row][player_col] == 'E')
        info->correct_exit = 1;
    else if (info->map[player_row][player_col] == 'P')
        info->map[player_row][player_col] = 'p';
    else if (info->map[player_row][player_col] == 'C')
    {
        info->map[player_row][player_col] = 'c';
        info->n_coins_fill += 1;
    }
    ft_fill(info, player_col - 1, player_row);
    ft_fill(info, player_col + 1, player_row);
    ft_fill(info, player_col, player_row - 1);
    ft_fill(info, player_col, player_row + 1);
}
void    ft_flood_fill(t_data *info)
{
    ft_fill(info, info->player_col, info->player_row);
    if (info->n_coins != info->n_coins_fill)
        ft_error_free("Not possible to find all collectables", info);
}

void    ft_collect_info(t_data *info)
{
    ft_n_coins(info);
    ft_player_position(info);
    ft_flood_fill(info);
    //ft_exit_position(info); /*must do*/
}