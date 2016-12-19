/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 12:10:12 by amarzial          #+#    #+#             */
/*   Updated: 2016/12/17 20:54:44 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf_internal.h"

static void		putnwstr(const wchar_t *str, size_t size)
{
	while (size--)
		ft_putwchar(*str++);
}

static int		getwlen(const wchar_t *cur, int *size)
{
	int	idx;
	int	len;
	int	tmp;

	len = 0;
	idx = 0;
	while (cur[idx])
	{
		if (cur[idx] < 0x80)
			tmp = 1;
		else if (cur[idx] < 0x800)
			tmp = 2;
		else if (cur[idx] < 0x10000)
			tmp = 3;
		else if (cur[idx] <= 0x10ffff)
			tmp = 4;
		else
			tmp = 0;
		if ((len + tmp > (*size)) && ((*size = len) + 1))
			return (idx);
		len += tmp;
		idx++;
	}
	return (idx);
}

static void		padding(const wchar_t *out, t_arg *arg, int len)
{
	int		wch;
	char	fill;

	fill = arg->flag_zero ? '0' : ' ';
	if (arg->prec_set)
		len = ft_min(len, arg->precision);
	wch = getwlen(out, &len);
	if (arg->field_width > len)
	{
		if (arg->flag_left)
		{
			putnwstr(out, wch);
			ft_printf_putnchar(fill, arg->field_width - len);
		}
		else
		{
			ft_printf_putnchar(fill, arg->field_width - len);
			putnwstr(out, wch);
		}
	}
	else
		putnwstr(out, wch);
	arg->size = ft_max(len, arg->field_width);
}

int				ft_printf_wstring(t_arg *arg, va_list *lst)
{
	const wchar_t	*str;
	const wchar_t	*cur;
	size_t			len;

	str = va_arg(*lst, wchar_t*);
	len = 0;
	if (str == 0)
		str = L"(null)";
	cur = str;
	while (*cur)
	{
		if (*cur < 0x80)
			len += 1;
		else if (*cur < 0x800)
			len += 2;
		else if (*cur < 0x10000)
			len += 3;
		else if (*cur <= 0x10ffff)
			len += 4;
		else
			len = 0;
		cur++;
	}
	padding(str, arg, len);
	return (len);
}
