/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:04:17 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/21 15:37:05 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_collect_images(t_img *map)
{
    int w = 50;
    int h = 50;
    map->imgP = mlx_xpm_file_to_image(map->mlx, "./images/hp.xpm", &w, &h);
    map->imgG = mlx_xpm_file_to_image(map->mlx, "./images/g.xpm", &w, &h);
    map->imgW = mlx_xpm_file_to_image(map->mlx, "./images/w.xpm", &w, &h);
    map->imgE = mlx_xpm_file_to_image(map->mlx, "./images/e.xpm", &w, &h);
    map->imgC = mlx_xpm_file_to_image(map->mlx, "./images/c.xpm", &w, &h);
}

void    ft_print_image(t_data *info, t_img *map, int w, int h, int row, int col)
{
    if (info->map[row][col] == '1')
    {
        mlx_put_image_to_window(map->mlx, map->mlx_window, map->imgG, w, h);
        mlx_put_image_to_window(map->mlx, map->mlx_window, map->imgW, w, h);
    }
    else if (info->map[row][col] == 'p')
    {
        mlx_put_image_to_window(map->mlx, map->mlx_window, map->imgG, w, h);
        mlx_put_image_to_window(map->mlx, map->mlx_window, map->imgP, w, h);
    }
    else if (info->map[row][col] == 'e')
    {
        mlx_put_image_to_window(map->mlx, map->mlx_window, map->imgG, w, h);
        mlx_put_image_to_window(map->mlx, map->mlx_window, map->imgE, w, h);
    }
    else if (info->map[row][col] == 'c') 
    {    
        mlx_put_image_to_window(map->mlx, map->mlx_window, map->imgG, w, h);
        mlx_put_image_to_window(map->mlx, map->mlx_window, map->imgC, w, h); 
    }
    else
        mlx_put_image_to_window(map->mlx, map->mlx_window, map->imgG, w, h);
}

void    ft_map(t_data *info, t_img *map)
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
            ft_print_image(info, map, width, height, row, col);
            col++;
            width += 50;
        }
        row++;
        height += 50;
    }
    printf("n_row: %d\n", info->n_row);
    printf("row: %d\n", row);

}
void    init_game(t_data *info, t_img *map)
{
    ft_collect_images(map);
    ft_map(info, map);
}
int	key_hook(int keycode)
{
	if (keycode == 53)   // Código de tecla 'Esc'
		ft_close();
    else if (keycode == 124 || keycode == 2)
        printf("Nos hemos movido a la derecha\n");
    else if (keycode == 126 || keycode == 13)
        printf("Nos hemos movido hacia arriba\n");
    else if (keycode == 123 || keycode == 0)
        printf("Nos hemos movido a la izquierda\n");
    else if (keycode == 125 || keycode == 1)
        printf("Nos hemos movido hacia abajo\n");
	/*else
		printf("Has presionado una tecla con código: %d\n", keycode);*/
	return (0);
}