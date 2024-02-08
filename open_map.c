/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:39:07 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/08 15:39:53 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>

void    ft_rows_and_columns(t_data *info, int fd)
{
    char    *line;

    line = get_next_line(fd);
    if (!line)
        ft_error("Line not found 1");
    while(line[info->n_col])
        info->n_col++;
    info->n_row++;
    while(line)
    {
        free(line);
        line = get_next_line(fd);
        if (!line)
            return ;
        info->n_row++;        
    }   
}

void    ft_open_map(char **argv, t_data *info)
{
    int fd;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        ft_error("Error opening map");
    ft_rows_and_columns(info, fd);
    //printf("%d\n", info->n_row);
    //printf("%d\n", info->n_col);
    /*fins aqui pilla be el tamany de la matriu!*/
    close(fd);
}