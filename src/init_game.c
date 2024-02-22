/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:04:17 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/22 15:18:36 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    ft_collect_images(t_data *map)
{
    int w = 50;
    int h = 50;
    map->imgP = mlx_xpm_file_to_image(map->mlx, "./images/hp.xpm", &w, &h);
    map->imgG = mlx_xpm_file_to_image(map->mlx, "./images/g.xpm", &w, &h);
    map->imgW = mlx_xpm_file_to_image(map->mlx, "./images/w.xpm", &w, &h);
    map->imgE = mlx_xpm_file_to_image(map->mlx, "./images/e.xpm", &w, &h);
    map->imgC = mlx_xpm_file_to_image(map->mlx, "./images/c.xpm", &w, &h);
}

void    ft_print_image(t_data *info, int w, int h, int row, int col)
{
    if (info->map[row][col] == '1')
    {
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgG, w, h);
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgW, w, h);
    }
    else if (info->map[row][col] == 'p')
    {
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgG, w, h);
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgP, w, h);
    }
    else if (info->map[row][col] == 'e')
    {
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgG, w, h);
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgE, w, h);
    }
    else if (info->map[row][col] == 'c') 
    {    
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgG, w, h);
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgC, w, h); 
    }
    else
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgG, w, h);
}

void    ft_map(t_data *info)
{
    int row;
    int col;
    int width;
    int height;

    row = 0;
    width = 0;
    height = 0;
    while (row < info->n_row)
    {
        col = 0;
        width = 0;
        while (col < info->n_col)
        {
            ft_print_image(info, width, height, row, col);
            col++;
            width += 50;
        }
        row++;
        height += 50;
    }
    ft_printf("Number of movements: %d\n", info->movements);
}

void    init_game(t_data *info)
{
    ft_collect_images(info);
    ft_map(info);
}
int	key_hook(int keycode, t_data *info)
{
	if (keycode == 53)
		ft_close(info, 0);
    else if (keycode == 124 || keycode == 2)
        ft_right(info);
    else if (keycode == 126 || keycode == 13)
        ft_up(info);
    else if (keycode == 123 || keycode == 0) 
        ft_left(info);
    else if (keycode == 125 || keycode == 1)
        ft_down(info);
	return (0);
}
