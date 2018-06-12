/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 20:19:55 by amarzial          #+#    #+#             */
/*   Updated: 2018/06/12 22:50:57 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_vecat(t_vector *vec, size_t position)
{
    if (position < vec->size)
    {
        return ((char *) vec->data + (position * vec->element_size));
    }
    return (NULL);
}
