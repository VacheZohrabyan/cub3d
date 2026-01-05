/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:07:43 by vzohraby          #+#    #+#             */
/*   Updated: 2026/01/05 16:10:45 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s_len;
	char	*ptr;

	s_len = ft_strlen(s1);
	ptr = (char *)malloc((s_len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, s_len);
	ptr[s_len] = '\0';
	return (ptr);
}
