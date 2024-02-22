/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:51:40 by pbotargu          #+#    #+#             */
/*   Updated: 2024/02/22 14:51:14 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *s, ...);
void	ft_printf_char(char c, int *ret_num);
void	ft_printf_string(char *str, int *ret_num);
void	ft_printf_id(long long int num, int *ret_num, char *base);

#endif
