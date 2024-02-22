/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:57:58 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/22 17:22:15 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_up(t_data *info)
{
	int	flag;

	flag = 0;
	if (info->map[info->player_row][info->player_col] != 'e')
		info->map[info->player_row][info->player_col] = 'o';
	info->player_row -= 1;
	if (info->map[info->player_row][info->player_col] != '1')
		info->movements += 1;
	else if (info->map[info->player_row][info->player_col] == '1')
		info->player_row += 1;
	if (info->map[info->player_row][info->player_col] == 'c')
		info->collect_coins += 1;
	if (info->map[info->player_row][info->player_col] == 'e')
	{
		if (info->collect_coins == info->n_coins)
			ft_close(info, 1);
		flag = 1;
	}
	info->map[info->player_row][info->player_col] = 'p';
	ft_map(info);
	if (flag == 1)
		info->map[info->player_row][info->player_col] = 'e';
}

void	ft_down(t_data *info)
{
	int	flag;

	flag = 0;
	if (info->map[info->player_row][info->player_col] != 'e')
		info->map[info->player_row][info->player_col] = 'o';
	info->player_row += 1;
	if (info->map[info->player_row][info->player_col] != '1')
		info->movements += 1;
	else if (info->map[info->player_row][info->player_col] == '1')
		info->player_row -= 1;
	if (info->map[info->player_row][info->player_col] == 'c')
		info->collect_coins += 1;
	if (info->map[info->player_row][info->player_col] == 'e')
	{
		if (info->collect_coins == info->n_coins)
			ft_close(info, 1);
		flag = 1;
	}
	info->map[info->player_row][info->player_col] = 'p';
	ft_map(info);
	if (flag == 1)
		info->map[info->player_row][info->player_col] = 'e';
}

void	ft_left(t_data *info)
{
	int	flag;

	flag = 0;
	if (info->map[info->player_row][info->player_col] != 'e')
		info->map[info->player_row][info->player_col] = 'o';
	info->player_col -= 1;
	if (info->map[info->player_row][info->player_col] != '1')
		info->movements += 1;
	else if (info->map[info->player_row][info->player_col] == '1')
		info->player_col += 1;
	if (info->map[info->player_row][info->player_col] == 'c')
		info->collect_coins += 1;
	if (info->map[info->player_row][info->player_col] == 'e')
	{
		if (info->collect_coins == info->n_coins)
			ft_close(info, 1);
		flag = 1;
	}
	info->map[info->player_row][info->player_col] = 'p';
	ft_map(info);
	if (flag == 1)
		info->map[info->player_row][info->player_col] = 'e';
}

void	ft_right(t_data *info)
{
	int	flag;

	flag = 0;
	if (info->map[info->player_row][info->player_col] != 'e')
		info->map[info->player_row][info->player_col] = 'o';
	info->player_col += 1;
	if (info->map[info->player_row][info->player_col] != '1')
		info->movements += 1;
	else if (info->map[info->player_row][info->player_col] == '1')
		info->player_col -= 1;
	if (info->map[info->player_row][info->player_col] == 'c')
		info->collect_coins += 1;
	if (info->map[info->player_row][info->player_col] == 'e')
	{
		if (info->collect_coins == info->n_coins)
			ft_close(info, 1);
		flag = 1;
	}
	info->map[info->player_row][info->player_col] = 'p';
	ft_map(info);
	if (flag == 1)
		info->map[info->player_row][info->player_col] = 'e';
}
