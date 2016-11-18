/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 20:43:49 by amarzial          #+#    #+#             */
/*   Updated: 2016/11/18 13:36:55 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr(unsigned long n)
{
	char	digits[10];
	int		count;

	if (n == 0)
		ft_putchar('0');
	count = 0;
	while (n != 0)
	{
		digits[count] = (n % 10) + '0';
		n /= 10;
		count += 1;
	}
	while (count)
		ft_putchar(digits[count-- - 1]);
}
