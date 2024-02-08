/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:26:42 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/08 15:27:50 by pbotargu         ###   ########.fr       */
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
	//we have to add more information
}

int main(int argc, char **argv)
{
	t_data	info;

	if (argc != 2)
		ft_error("Wrong number of arguments");
	if (ft_check_extension(argv[1]) == 1)
		ft_error("File's extension is not < .ber >");
	ft_info_to_0(&info);
	ft_open_map(argv, &info);
	return (0);
}