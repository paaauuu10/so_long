/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:36:13 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/22 18:18:09 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_n_coins(t_data *info)
{
	int	col;
	int	row;

	row = 0;
	while (info->map[row])
	{
		col = 0;
		while (info->map[row][col])
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

void	ft_player_position(t_data *info)
{
	int	col;
	int	row;

	row = 0;
	while (info->map[row])
	{
		col = 0;
		while (info->map[row][col])
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

void	ft_fill(t_data *info, int player_row, int player_col)
{
	if ((player_col < 0 || player_row < 0 || player_col >= info->n_col || \
	player_row >= info->n_row || info->map[player_row][player_col] != '0') \
	&& (info->map[player_row][player_col] != 'C' \
	&& info->map[player_row][player_col] != 'P' \
	&& info->map[player_row][player_col] != 'E'))
		return ;
	if (info->map[player_row][player_col] == 'E')
	{
		info->correct_exit = 1;
		info->map[player_row][player_col] = 'e';
	}
	else if (info->map[player_row][player_col] == 'P')
		info->map[player_row][player_col] = 'p';
	else if (info->map[player_row][player_col] == '0')
		info->map[player_row][player_col] = 'o';
	else if (info->map[player_row][player_col] == 'C')
	{
		info->map[player_row][player_col] = 'c';
		info->n_coins_fill += 1;
	}
	info->i++;
	ft_fill(info, player_row + 1, player_col);
	ft_fill(info, player_row - 1, player_col);
	ft_fill(info, player_row, player_col - 1);
	ft_fill(info, player_row, player_col + 1);
}

void	ft_flood_fill(t_data *info)
{
	ft_fill(info, info->player_row, info->player_col);
	if (info->n_coins != info->n_coins_fill)
		ft_error_free("Not possible to find all collectables", info);
	else if (info->correct_exit != 1)
		ft_error_free("Not possible to find the exit", info);
}

void	ft_collect_info(t_data *info)
{
	ft_n_coins(info);
	ft_player_position(info);
	ft_flood_fill(info);
}
