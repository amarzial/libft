/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzial <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 12:57:11 by amarzial          #+#    #+#             */
/*   Updated: 2018/03/22 13:08:51 by amarzial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

t_vector ft_vecnew(size_t elements, size_t elem_size)
{
    t_vector vec;

    if(vec.data = malloc(elements * elem_size) == NULL) return (vec);
    vec.element_size = elem_size;
    vec.capacity = elements;
    vec.size = 0;
    vec.begin = vec.data;
    vec.end = (char*)vec.begin + (vec.size * vec.element_size); 
    return (vec);
}
