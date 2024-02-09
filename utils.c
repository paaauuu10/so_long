/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:03:59 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/09 14:04:30 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_params(t_data *info)
{
	int	row;
	int col;

	row = 0;
	while (info->map[row])
	{
		col = 0;
		while (info->map[row][col])
		{
			if (info->map[row][col] != 'E' && info->map[row][col] != 'P' && \
				info->map[row][col]	!= 'C' && info->map[row][col] != '0' && \
				info->map[row][col]	!= '1')
				ft_error_free("Found character not accepted in the map", info);
			col++;
		}
		row++;
	}
}