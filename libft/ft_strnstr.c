/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:12:40 by akelli            #+#    #+#             */
/*   Updated: 2019/09/18 13:49:38 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char*)big;
	if (little[0] == '\0')
		return (str);
	while (str[i] && (i + j < len))
	{
		if (str[i] == little[0])
		{
			while (str[i + j] == little[j] && (i + j < len))
			{
				j++;
				if (little[j] == '\0')
					return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}
