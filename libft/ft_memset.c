/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:31:54 by vzohraby          #+#    #+#             */
/*   Updated: 2025/01/13 17:52:30 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_byte;
	unsigned char	c_byte;
	size_t			i;

	s_byte = (unsigned char *)s;
	c_byte = (unsigned char)c;
	i = 0;
	while (i < n)
		s_byte[i++] = c_byte;
	return (s);
}
