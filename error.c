/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:14:05 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/08 16:17:05 by pbotargu         ###   ########.fr       */
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
    i = 0;
    while (message[i] != '\0')
    {
        write(1, &message[i], 1);
        i++;
    }
    write(1, "\n", 1);
    exit (1);
}

void    ft_error(char *message)
{
    int i;

    i = 0;
    while (message[i] != '\0')
    {
        write(1, &message[i], 1);
        i++;
    }
    write(1, "\n", 1);
    exit (1);
}

