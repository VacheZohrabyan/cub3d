/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:24:00 by vzohraby          #+#    #+#             */
/*   Updated: 2025/01/29 15:01:15 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count(int m)
{
	int	size;

	size = 0;
	if (m < 0)
	{
		++size;
		m *= -1;
	}
	while (m)
	{
		++size;
		m /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		m;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = count(n);
	ptr = (char *)malloc((size + 1) * (sizeof(char)));
	if (!ptr)
		return (NULL);
	m = size - 1;
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	while (n)
	{
		ptr[m--] = n % 10 + 48;
		n /= 10;
	}
	ptr[size] = '\0';
	return (ptr);
}
