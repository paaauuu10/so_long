/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:14:05 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/09 14:27:08 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_error_free(char *message, t_data *info)
{
    int i;

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
    write(1, "Error\n", 6);
    i = 0;
    while (message[i] != '\0')
    {
        write(2, &message[i], 1);
        i++;
    }
    write(2, "\n", 1);
    exit (1);
}

void    ft_error(char *message)
{
    int i;

    i = 0;
    write(1, "Error\n", 6);
    while (message[i] != '\0')
    {
        write(2, &message[i], 1);
        i++;
    }
    write(2, "\n", 1);
    exit (1);
}

