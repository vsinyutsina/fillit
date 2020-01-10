/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 10:25:00 by akelli            #+#    #+#             */
/*   Updated: 2019/09/18 13:32:05 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	size_t len;

	len = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			len++;
		while (*s != c && *s)
			s++;
	}
	return (len);
}

static int	ft_new(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static void	*ft_free(char **array)
{
	size_t	i;

	i = 0;
	while (**array)
	{
		ft_memdel((void*)array[i]);
		i++;
	}
	return (NULL);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**array;
	size_t	len;

	if (!s)
		return (0);
	len = word_count(s, c);
	i = 0;
	if (!(array = (char**)malloc(sizeof(char*) * (len + 1))))
		return (0);
	while (i < len)
	{
		j = 0;
		while (*s == c && *s)
			s++;
		if (!(array[i] = (char*)malloc(sizeof(char) * (ft_new(s, c) + 1))))
			return (ft_free(array));
		while (*s != c && *s)
			array[i][j++] = *s++;
		array[i][j] = '\0';
		i++;
	}
	array[i] = NULL;
	return (array);
}
