/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:50:06 by akelli            #+#    #+#             */
/*   Updated: 2019/09/11 16:06:59 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*array;

	array = (unsigned char*)malloc(sizeof(array) * size);
	if (!array)
		return (NULL);
	ft_bzero(array, size);
	return ((void*)array);
}
