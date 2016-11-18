/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:52:20 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/16 15:56:23 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(void ***tab)
{
	int		cnt;

	cnt = 0;
	while ((*tab)[cnt])
		free((*tab)[cnt]);
	free(*tab);
	*tab = 0;
}