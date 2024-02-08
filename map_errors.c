/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:57:20 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/08 17:39:03 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int ft_check_walls(t_data *info)
{
    int column;
    int line;
    
    line = 0;
    column = 0;
    while(info->map[line])
    {
        if (info->map[line][0] != '1')
            ft_error_free("First column: Not enough walls", info);
        line++;
    }
    while(info->map[0][column])
    {
        if(info->map[0][column] != '1')
            ft_error_free("First row: Not enough walls", info);
        column++;
    }
    return (0);
}*/

int ft_check_walls(t_data *info)
{
    /*// Verificar la primera fila
    int col = 0;
    while (info->map[0][col])
    {
        if (info->map[0][col] != '1')
            ft_error_free("First row: Not enough walls", info);
        col++;
    }*/

    // Verificar la primera columna
    int row = 0;
    while (info->map[row])
    {
        if (info->map[row][0] != '1')
            ft_error_free("First column: Not enough walls", info);
        row++;
    }

    return (0);
}


/*int ft_check_size(t_data *info)
{

}*/

void    ft_check_map_errors(t_data *info)
{
    /*if (ft_check_size(info) == 1)
        ft_error_free("The map it's not a rectangle", info);*/
    ft_check_walls(info);
}