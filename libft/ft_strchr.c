/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:05:15 by akelli            #+#    #+#             */
/*   Updated: 2019/10/09 16:14:59 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = ft_strlen(s);
	j = 0;
	str = (char*)s;
	while (j <= i)
	{
		if (str[j] == c)
			return (&str[j]);
		j++;
	}
	return (0);
}
