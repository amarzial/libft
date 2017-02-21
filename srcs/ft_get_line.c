/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 20:10:49 by amarzial          #+#    #+#             */
/*   Updated: 2017/02/21 08:55:20 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static t_reader	*get_file_handler(int fd, t_list **multilist)
{
	t_reader		*tmp;
	t_list			*cur;

	cur = *multilist;
	while (cur)
	{
		tmp = (t_reader*)cur->content;
		if (tmp->fd == fd)
			return (tmp);
		cur = cur->next;
	}
	if (!(tmp = (t_reader*)ft_memalloc(sizeof(t_reader))))
		return (0);
	tmp->fd = fd;
	if (!(cur = ft_lstnew(tmp, sizeof(t_reader))))
		return (0);
	free(tmp);
	ft_lstadd(multilist, cur);
	return ((t_reader*)cur->content);
}

static void		addtoline(char **line, t_reader *rdr)
{
	size_t	size;
	size_t	frombuffer;
	char	*tmp;

	frombuffer = rdr->el ? rdr->el - rdr->buffer : rdr->r_size;
	size = frombuffer;
	if (*line)
		size += ft_strlen(*line);
	tmp = ft_strnew(size);
	if (*line)
	{
		ft_strcpy(tmp, *line);
		free(*line);
	}
	ft_strncat(tmp, rdr->buffer, frombuffer);
	if (rdr->el)
	{
		frombuffer++;
		ft_memmove(rdr->buffer, rdr->buffer + frombuffer + 1, \
		GET_LINE_BUFF_SIZE - frombuffer - 1);
	}
	rdr->r_size = GET_LINE_BUFF_SIZE - frombuffer;
	*line = tmp;
}

int				ft_getline(const int fd, char **line)
{
	static t_list	*multilist;
	t_reader		*rdr;
	int				out;

	*line = 0;
	if (fd < 0 || !line || !(rdr = get_file_handler(fd, &multilist)))
		return (-1);
	while (!rdr->stop)
	{
		rdr->el = ft_memchr(rdr->buffer, '\n', rdr->r_size);
		addtoline(line, rdr);
		if (rdr->el)
			break ;
		out = read(fd, rdr->buffer + rdr->r_size, GET_LINE_BUFF_SIZE - rdr->r_size);
		if (rdr->r_size == -1)
			return (-1);
		rdr->r_size += out;
		if (rdr->r_size == 0 && (rdr->stop = 1))
			return (0);
	}
	return (1);
}
