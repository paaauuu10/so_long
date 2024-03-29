/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:08:10 by polmarti          #+#    #+#             */
/*   Updated: 2024/02/22 18:19:19 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **ptr)
{
	if (ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

char	*ft_read_join(int fd, char *store)
{
	char	*str_buf;
	int		cntrl;

	str_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str_buf)
		return (ft_free(&store));
	str_buf[0] = '\0';
	cntrl = 1;
	while (cntrl > 0 && !ft_strchr(str_buf, '\n'))
	{
		cntrl = read(fd, str_buf, BUFFER_SIZE);
		if (cntrl == -1)
			return (free(str_buf), ft_free(&store));
		str_buf[cntrl] = '\0';
		if (cntrl == 0)
			break ;
		store = ft_strjoin(store, str_buf);
		if (!store)
			return (free(str_buf), ft_free(&store));
	}
	free(str_buf);
	return (store);
}

char	*ft_fill_line(char *store)
{
	char	*rtrn;
	char	*s;

	if (store[0] == '\0')
		return (NULL);
	rtrn = ft_strchr(store, '\n');
	if (!rtrn)
		rtrn = ft_strchr(store, '\0');
	s = ft_substr(store, 0, ((rtrn - store)));
	if (!s)
		return (NULL);
	return (s);
}

char	*ft_clean_store(char *store)
{
	int		start;
	char	*ptraux;
	char	*rtrn;

	ptraux = ft_strchr(store, '\n');
	if (!ptraux)
	{
		rtrn = NULL;
		return (ft_free(&store));
	}
	start = (ptraux - store) + 1;
	if (store[start] == '\0')
		return (ft_free(&store));
	rtrn = ft_substr(store, start, ft_strlen(store) - start);
	ft_free(&store);
	if (!rtrn)
		return (NULL);
	return (rtrn);
}

char	*get_next_line(int fd)
{
	static char	*store = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if ((store && !ft_strchr(store, '\n')) || !store)
	{
		store = ft_read_join(fd, store);
		if (!store)
			return (NULL);
	}
	line = ft_fill_line(store);
	if (!line)
		return (ft_free(&store));
	store = ft_clean_store(store);
	return (line);
}
