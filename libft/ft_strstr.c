/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:41:55 by akelli            #+#    #+#             */
/*   Updated: 2019/09/11 14:32:05 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = (char*)str;
	if (to_find[0] == '\0')
		return (s);
	while (s[i] != '\0')
	{
		if (s[i] == to_find[0])
		{
			while (s[i + j] == to_find[j])
			{
				j++;
				if (to_find[j] == '\0')
					return (&s[i]);
			}
		}
		i++;
	}
	return (0);
}
