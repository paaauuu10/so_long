/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:19:57 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/22 14:51:47 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static void	ft_ret_num(const char *s, va_list args, int *ret_num, int i)
{
	while (s[++i] && *ret_num > -1)
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'c')
				ft_printf_char(va_arg(args, int), ret_num);
			else if (s[i] == 's')
				ft_printf_string(va_arg(args, char *), ret_num);
			else if (s[i] == 'i' || s[i] == 'd')
				ft_printf_id(va_arg(args, int), ret_num, "0123456789");
			else if (s[i] == '%')
				ft_printf_char('%', ret_num);
		}	
		else
			ft_printf_char(s[i], ret_num);
	}
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		ret_num;

	ret_num = 0;
	va_start(args, s);
	ft_ret_num(s, args, &ret_num, -1);
	if (ret_num == -1)
		return (-1);
	va_end (args);
	return (ret_num);
}
