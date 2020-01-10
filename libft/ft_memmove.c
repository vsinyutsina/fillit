/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:37:39 by akelli            #+#    #+#             */
/*   Updated: 2019/09/11 13:44:23 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*str;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str = dest;
	str2 = (unsigned char*)src;
	if (dest == src)
		return (dest);
	if (str2 < str)
		while (len-- > 0)
			*(str + len) = *(str2 + len);
	else
		while (i < len)
		{
			*(str + i) = *(str2 + i);
			i++;
		}
	return (dest);
}
