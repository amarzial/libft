/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:00:36 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/10 18:31:38 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur;
	t_list	*next_ptr;

	next_ptr = *alst;
	while (next_ptr)
	{
		cur = next_ptr;
		next_ptr = cur->next;
		del(cur->content, cur->content_size);
		free(cur);
	}
	*alst = 0;
}
