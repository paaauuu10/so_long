/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:57:20 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/22 17:32:36 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_check_rectangle(t_data *info)
{
	int	columns;
	int	line;
	int	first_column;

	columns = 0;
	line = 1;
	first_column = 0;
	while (info->map[0][first_column])
		first_column++;
	while (info->map[line])
	{
		columns = 0;
		while (info->map[line][columns] != '\0')
		{
			if (columns > first_column)
				ft_error_free("The map is not a rectangle", info);
			columns++;
		}
		line++;
		if (columns != first_column)
			ft_error_free("The map is not a rectangle", info);
	}
}

void	ft_check_1st_walls(t_data *info)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (info->map[row])
	{
		if (info->map[row][0] != '1')
			ft_error_free("1st column: not made of walls", info);
		row++;
	}
	while (info->map[0][col])
	{
		if (info->map[0][col] != '1')
			ft_error_free("1st line: not made of walls", info);
		col++;
	}
}

void	ft_check_last_walls(t_data *info)
{
	int	row;
	int	col;

	row = 0;
	col = info->n_col - 1;
	while (info->map[row])
	{
		if (info->map[row][col] != '1')
			ft_error_free("Last column: not made of walls", info);
		row++;
	}
	row = info->n_row - 1;
	col = 0;
	while (info->map[row][col])
	{
		if (info->map[row][col] != '1')
			ft_error_free("Last line: not made of walls", info);
		col++;
	}
}

void	ft_check_doubles(t_data *info)
{
	int	row;
	int	col;
	int	p;
	int	e;

	p = 0;
	e = 0;
	row = -1;
	while (info->map[++row])
	{
		col = 0;
		while (info->map[row][col])
		{
			if (info->map[row][col] == 'P')
				p++;
			else if (info->map[row][col] == 'E')
				e++;
			ft_check_params(info);
			col++;
		}
	}
	if (p > 1 || e > 1)
		ft_error_free("There is more than one P or E", info);
	else if (p < 1 || e < 1)
		ft_error_free("P or E is missing", info);
}

void	ft_check_map_errors(t_data *info)
{
	ft_check_rectangle(info);
	ft_check_1st_walls(info);
	ft_check_last_walls(info);
	ft_check_doubles(info);
}
