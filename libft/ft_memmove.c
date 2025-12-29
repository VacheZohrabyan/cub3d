/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 21:53:49 by vzohraby          #+#    #+#             */
/*   Updated: 2025/01/13 17:54:13 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_ptr;
	unsigned char	*src_ptr;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (unsigned char *)src;
	if (!dest_ptr && !src_ptr)
		return (NULL);
	if (dest_ptr > src_ptr)
	{
		while (n--)
		{
			dest_ptr[n] = src_ptr[n];
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest_ptr);
}
