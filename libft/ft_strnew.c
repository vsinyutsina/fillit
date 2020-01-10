/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:10:26 by akelli            #+#    #+#             */
/*   Updated: 2019/09/18 13:36:30 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *array;

	if (!(size + 1))
		return (NULL);
	array = (char*)malloc(size + 1);
	if (!array)
		return (NULL);
	ft_bzero(array, size + 1);
	return (array);
}
