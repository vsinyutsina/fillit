/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:49:40 by akelli            #+#    #+#             */
/*   Updated: 2019/09/11 16:12:42 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*array;
	char	*str;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (0);
	i = 0;
	len = ft_strlen(s);
	str = (char*)s;
	array = (char*)malloc(sizeof(char) * (len + 1));
	if (!array)
		return (0);
	ft_bzero(array, len + 1);
	while (i < len)
	{
		array[i] = f(i, str[i]);
		i++;
	}
	return (array);
}
