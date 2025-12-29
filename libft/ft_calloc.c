/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:59:43 by vzohraby          #+#    #+#             */
/*   Updated: 2025/01/13 18:02:50 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	size_t			i;

	if ((count != 0 && size > 65536) || (size != 0 && count > 65536))
		return (NULL);
	mem = (unsigned char *)malloc (size * count);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < count * size)
		mem[i++] = 0;
	return (mem);
}
