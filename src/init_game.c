/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:04:17 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/22 16:58:50 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void    ft_collect_images(t_data *map)
{
    int w = 50;
    int h = 50;
    map->imgp = mlx_xpm_file_to_image(map->mlx, "./images/hp.xpm", &w, &h);
    if (map->imgp == NULL)
        ft_error("Not found the image.xpm");
    map->imgg = mlx_xpm_file_to_image(map->mlx, "./images/g.xpm", &w, &h);
    if (map->imgg == NULL)
        ft_error("Not found the image.xpm");
    map->imgw = mlx_xpm_file_to_image(map->mlx, "./images/w.xpm", &w, &h);
    if (map->imgw == NULL)
        ft_error("Not found the image.xpm");
    map->imge = mlx_xpm_file_to_image(map->mlx, "./images/e.xpm", &w, &h);
    if (map->imge == NULL)
        ft_error("Not found the image.xpm");
    map->imgc = mlx_xpm_file_to_image(map->mlx, "./images/c.xpm", &w, &h);
    if (map->imgc == NULL)
        ft_error("Not found the image.xpm");
}

void    ft_print_image(t_data *info, int w, int h, int row, int col)
{
    if (info->map[row][col] == '1')
    {
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgg, w, h);
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgw, w, h);
    }
    else if (info->map[row][col] == 'p')
    {
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgg, w, h);
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgp, w, h);
    }
    else if (info->map[row][col] == 'e')
    {
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgg, w, h);
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imge, w, h);
    }
    else if (info->map[row][col] == 'c') 
    {    
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgg, w, h);
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgc, w, h); 
    }
    else
        mlx_put_image_to_window(info->mlx, info->mlx_window, info->imgg, w, h);
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
}

void    init_game(t_data *info)
{
    ft_collect_images(info);
    ft_map(info);
}
int	key_hook(int keycode, t_data *info)
{
	int flag;

    flag = info->movements;
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
    if (flag != info->movements)
        ft_printf("Number of movements: %d\n", info->movements);
	return (0);
}
