/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 21:37:53 by akelli            #+#    #+#             */
/*   Updated: 2019/09/18 14:15:32 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lendest;
	size_t	lensrc;

	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	if (lendest > size)
		lendest = size;
	if (lendest == size || size == 0)
		return (size + lensrc);
	if (lensrc < size - lendest)
		ft_memcpy(dest + lendest, src, lensrc + 1);
	else
	{
		ft_memcpy(dest + lendest, src, size - lendest - 1);
		dest[size - 1] = '\0';
	}
	return (lendest + lensrc);
}
