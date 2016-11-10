/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 10:54:18 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/10 16:26:00 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
{
	size_t	index;

	index = ft_strlen(s);
	if (index == 0 && (char)c == 0)
		return (s);
	index++;
	while (index)
	{
		if (s[index - 1] == (char)c)
			return (s + index - 1);
		index--;
	}
	return (0);
}
