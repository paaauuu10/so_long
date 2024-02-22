/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 11:39:07 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/22 17:12:27 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_rows_and_columns(t_data *info, int fd)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		ft_error("Line not found 1");
	while (line[info->n_col])
		info->n_col++;
	info->n_row++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			return ;
		info->n_row++;
	}
}

void	ft_create_matrix(t_data *info, int fd)
{
	int	i;

	i = 0;
	info->map = malloc(sizeof(char *) * info->n_row + 1);
	if (!info->map)
		ft_error_free("Error generating memory", info);
	while (info->n_row - i)
	{
		info->map[i] = get_next_line(fd);
		if (!info->map[i])
			ft_error_free("Error getting the line to create the map", info);
		i++;
	}
	info->map[i] = NULL;
}

void	ft_open_map(char **argv, t_data *info)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Error opening map");
	ft_rows_and_columns(info, fd);
	if (info->n_col > 56 || info->n_row > 26)
		ft_error_free("The map is to big to be used in this screen", info);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Error opening map");
	ft_create_matrix(info, fd);
	close(fd);
}
