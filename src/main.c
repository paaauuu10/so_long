/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:26:42 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/22 17:58:37 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_check_extension(char *argv)
{
	int	i;

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
	info->collect_coins = 0;
	info->movements = 0;
	info->map = NULL;
}

void	ft_how_to_play(void)
{
	ft_printf("\n              Welcome to my so_long project!");
	ft_printf("\n");
	ft_printf("\nThe purpose of the game is to help Harry catch the snitch");
	ft_printf("\n");
	ft_printf("\nYou need to collect all broomsticks before the snitch");
	ft_printf("\n");
	ft_printf("\nTry doing it in the minimum number of movements");
	ft_printf("\n");
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_data	info;

	if (argc != 2)
		ft_error("Wrong number of arguments");
	if (ft_check_extension(argv[1]) == 1)
		ft_error("File's extension is not < .ber >");
	ft_info_to_0(&info);
	ft_open_map(argv, &info);
	ft_check_map_errors(&info);
	ft_how_to_play();
	ft_collect_info(&info);
	info.mlx = mlx_init();
	info.mlxw = mlx_new_window(info.mlx, (info.n_col * 50), \
	(info.n_row * 50), "so_long");
	init_game(&info);
	mlx_key_hook(info.mlxw, key_hook, &info);
	mlx_hook(info.mlxw, 17, 0, &ft_close, &info);
	mlx_loop(info.mlx);
	return (0);
}
