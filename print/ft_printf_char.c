/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:20:01 by pbotargu          #+#    #+#             */
/*   Updated: 2023/10/24 12:22:52 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_printf_char(char c, int *ret_num)
{
	if (write(1, &c, 1) == -1)
	{
		(*ret_num) = -1;
		return ;
	}
	(*ret_num)++;
}
