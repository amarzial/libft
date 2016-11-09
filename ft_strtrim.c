/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:28:59 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/09 19:24:24 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	bg;
	size_t	size;
	char	*newstr;

	size = ft_strlen(s);
	bg = size - 1;
	while (bg && (s[bg] == ' ' || s[bg] == '\n' || s[bg] == '\t'))
	{
		bg--;
		size--;
	}
	bg = 0;
	while (s[bg] == ' ' || s[bg] == '\n' || s[bg] == '\t')
	{
		bg++;
		size--;
	}
	if ((newstr = ft_strnew(size)))
	{
		ft_strncpy(newstr, s + bg, size);
	}
	return (newstr);
}
