/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akelli <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:29:21 by akelli            #+#    #+#             */
/*   Updated: 2019/09/18 14:12:02 by akelli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int n)
{
	int	sign;

	sign = 0;
	if (n < 0)
		sign = 1;
	return (sign);
}

static int	ft_is_negative(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

char		*ft_itoa(int n)
{
	char	*array;
	int		sign;
	int		len;
	int		tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = ft_sign(n);
	n = ft_is_negative(n);
	tmp = n;
	len = 2 + sign;
	while (tmp /= 10)
		len++;
	array = (char*)malloc(sizeof(char) * len);
	if (!array)
		return (0);
	array[--len] = '\0';
	while (len--)
	{
		array[len] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		array[0] = '-';
	return (array);
}
