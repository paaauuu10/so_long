/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:26:42 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/21 11:58:20 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_extension(char *argv)
{
	int i;

	i = ft_strlen(argv);
	if (i > 2 && argv[i - 4] == '.' && argv[i - 3] == 'b' && \
		argv[i - 2] == 'e' && argv[i - 1] == 'r')
		return (0);
	return (1);
}

void	ft_info_to_0(t_data	*info)
{
	info->n_col = 0;
	info->n_row = 0;
	info->n_coins = 0;
	info->correct_exit = 0;
	info->player_col = 0;
	info->player_row = 0;
	info->n_coins_fill = 0;
	info->map = NULL;

	
	//we have to add more information
}

int main(int argc, char **argv)
{
	t_data	info;
	t_img	map;

	if (argc != 2)
		ft_error("Wrong number of arguments");
	if (ft_check_extension(argv[1]) == 1)
		ft_error("File's extension is not < .ber >");
	ft_info_to_0(&info);
	ft_open_map(argv, &info);
	ft_check_map_errors(&info);
	ft_collect_info(&info);
	map.mlx = mlx_init();
	map.mlx_window = mlx_new_window(map.mlx, (info.n_col * 50), \
	(info.n_row * 50), "so_long");
	init_game(&info, &map);
	mlx_key_hook(map.mlx_window, key_hook, &map);
	mlx_hook(map.mlx_window, 17, 0, &ft_close, &map);
	mlx_loop(map.mlx);
	
	
	return (0);
}
