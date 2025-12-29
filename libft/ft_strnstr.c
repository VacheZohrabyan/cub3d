/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:34:42 by vzohraby          #+#    #+#             */
/*   Updated: 2025/01/13 17:39:27 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *erkar, const char *karch, size_t len)
{
	size_t	i;
	size_t	e_len;
	size_t	k_len;

	k_len = ft_strlen(karch);
	if (k_len == 0)
		return ((char *)erkar);
	if (len == 0)
		return (NULL);
	e_len = ft_strlen(erkar);
	i = 0;
	while ((i + k_len) <= len && i < e_len)
	{
		if (ft_strncmp(erkar + i, karch, k_len) == 0)
		{
			return ((char *)(erkar + i));
		}
		++i;
	}
	return (NULL);
}
