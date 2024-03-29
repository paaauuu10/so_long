/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:14:05 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/22 18:14:56 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error_free(char *message, t_data *info)
{
	int	i;

	i = 0;
	if (info->map)
	{
		while (info->map[i])
		{
			free(info->map[i]);
			i++;
		}
		free(info->map);
	}
	write(2, "Error\n", 6);
	i = 0;
	while (message[i] != '\0')
	{
		write(2, &message[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit (1);
}

void	ft_error(char *message)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	while (message[i] != '\0')
	{
		write(2, &message[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit (1);
}

int	ft_close(t_data *info, int i)
{
	if (i == 1)
	{
		ft_printf("Number of movements: %d\n", info->movements);
		ft_printf("\n🧙🏼YOU'VE CATCH THE SNITCH🧙🏼\n");
		ft_printf("\nThanks for playing so_long by @pbotargu\n\n");
	}
	mlx_destroy_window(info->mlx, info->mlxw);
	exit(0);
}
