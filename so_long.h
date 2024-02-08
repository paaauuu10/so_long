/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:24:07 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/08 15:27:46 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
# include "./gnl/get_next_line.h"

/*Struct to handle map distribution*/

typedef struct s_data
{
    char    **map;
    int n_row;
    int n_col;

    /*
    void   "x8" 
    char    **map;
    int   y_npc;
    int     x_npc;
    int     row_;
    int     col_;
    int     coins;
    int     read_coins;
    int     read_coins_flood;
    int     flood_fill_check;*/
}                       t_data;

int	ft_check_extension(char *argv);
void	ft_info_to_0(t_data	*info);
void    ft_error(char *message);
void    ft_error_free(char *message, t_data *info);
void    ft_open_map(char **argv, t_data *info);
void    ft_rows_and_columns(t_data *info, int fd);

#endif