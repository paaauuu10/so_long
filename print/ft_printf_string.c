/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:20:16 by pbotargu          #+#    #+#             */
/*   Updated: 2023/10/24 12:20:17 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_printf_string(char *str, int *ret_num)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		if (write(1, str++, 1) == -1)
		{
			*ret_num = -1;
			return ;
		}
		(*ret_num)++;
	}
}
