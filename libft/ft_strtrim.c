/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:43:29 by akelli            #+#    #+#             */
/*   Updated: 2019/09/18 14:15:08 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	left_calc(char const *s)
{
	int		start;

	start = 0;
	while ((s[start] == '\n' || s[start] == '\t' ||
				s[start] == ' ') && s[start] != '\0')
		start++;
	return (start);
}

static int	right_calc(char const *s)
{
	int		end;

	end = ft_strlen(s) - 1;
	while (end > 0 && (s[end] == '\n' || s[end] == '\t' ||
				s[end] == ' ' || s[end] == '\0'))
		end--;
	return (ft_strlen(s) - 1 - end);
}

char		*ft_strtrim(char const *s)
{
	char	*array;
	int		size;
	int		i;
	int		j;

	if (!s)
		return (0);
	i = 0;
	size = ft_strlen(s) - left_calc(s) - right_calc(s);
	if (size < 0)
		return (ft_strnew(1));
	array = (char*)malloc(sizeof(char) * (size + 1));
	if (!array)
		return (0);
	j = left_calc(s);
	while (j < left_calc(s) + size)
		array[i++] = s[j++];
	array[i] = '\0';
	return (array);
}
