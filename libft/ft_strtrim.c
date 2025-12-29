/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzohraby <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:33:24 by vzohraby          #+#    #+#             */
/*   Updated: 2025/01/14 19:54:00 by vzohraby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	check(char const *s1, char s)
{
	while (*s1)
	{
		if (*s1 == s)
			return (1);
		++s1;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		start;
	int		end;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && check(set, s1[start]))
		++start;
	end = ft_strlen(s1) - 1;
	while (check(set, s1[end]) && start <= end)
		--end;
	ptr = (char *)malloc((end - start + 2) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (start + i <= end)
	{
		ptr[i] = s1[start + i];
		++i;
	}
	ptr[i] = '\0';
	return (ptr);
}
