/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:27:32 by akelli            #+#    #+#             */
/*   Updated: 2019/09/11 10:29:27 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (len != 0)
	{
		while (len-- != 0)
		{
			if ((*d++ = *s++) == 0)
			{
				while (len-- != 0)
					*d++ = 0;
				break ;
			}
		}
	}
	return (dst);
}
