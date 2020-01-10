/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 10:27:59 by akelli            #+#    #+#             */
/*   Updated: 2019/09/11 11:07:47 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	tmp;
	size_t	i;

	tmp = (char)c;
	i = ft_strlen(s);
	s += i;
	while (i-- != 0)
	{
		if (*s == tmp)
			return ((char *)s);
		s--;
	}
	if (*s == tmp)
		return ((char *)s);
	return (NULL);
}
