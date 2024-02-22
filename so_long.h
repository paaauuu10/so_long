/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:24:07 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/22 12:27:12 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
# include "./gnl/get_next_line.h"
#include "./mlx/mlx.h"

/*Struct to handle map distribution*/

/*typedef struct s_img
{
    void    *mlx_window;
    void    *mlx;
    void    *imgP;
    void    *imgG;
    void    *imgW;
    void    *imgC;
    void    *imgE;
    
}               t_img*/

typedef struct s_data
{
    char    **map;
    int n_row;
    int n_col;
    int n_coins;
    int player_row;
    int player_col;
    int correct_exit;
    int n_coins_fill;
    int i;
    int collect_coins;
    int movements;

    void    *mlx_window;
    void    *mlx;
    void    *imgP;
    void    *imgG;
    void    *imgW;
    void    *imgC;
    void    *imgE;
    
    //t_img *map; /*estudiar aquesta opcio */

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



int     ft_check_extension(char *argv);
void	ft_info_to_0(t_data	*info);
void    ft_error(char *message);
void    ft_error_free(char *message, t_data *info);
void    ft_open_map(char **argv, t_data *info);
void    ft_rows_and_columns(t_data *info, int fd);
void    ft_check_map_errors(t_data *info);
void    ft_check_rectangle(t_data *info);
void    ft_check_last_walls(t_data *info);
void    ft_check_1st_walls(t_data *info);
void	ft_check_params(t_data *info);
void    ft_collect_info(t_data *info);
void    init_game(t_data *info);
int     ft_close();
int     key_hook(int keycode, t_data *info);
void    ft_up(t_data *info);
void    ft_down(t_data *info);
void    ft_left(t_data *info);
void    ft_right(t_data *info);
void    ft_map(t_data *info);

#endif