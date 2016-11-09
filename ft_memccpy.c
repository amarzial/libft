/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:49:46 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/09 22:25:31 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*from;
	unsigned char	*to;

	from = (unsigned char*)src;
	to = (unsigned char*)dest;
	while (n--)
	{
		if ((*to++ = *from++) == (unsigned char)c)
			return (to);
	}
	return (0);
}
