/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:18:30 by amarcele          #+#    #+#             */
/*   Updated: 2020/06/09 12:12:45 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int i;

	if (dst == src)
		return (0);
	i = ft_strlen(src);
	while (size > 1 && *src != '\0')
	{
		*dst++ = *src++;
		size--;
	}
	if (size != 0)
		*dst = '\0';
	return (i);
}

char	*ft_strchr(const char *str, int ch)
{
	int i;

	i = 0;
	while (str[i] != ch && str[i] != '\0')
		i++;
	if (str[i] == ch)
		return (&((char *)str)[i]);
	else
		return (NULL);
}

char		*ft_strdup(const char *s)
{
	char *const	copy = (char *const)malloc(ft_strlen(s) + 1);

	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s, ft_strlen(s) + 1);
	return (copy);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char *mem;
	int i;
	
	i = 0;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	mem = malloc(size * nmemb);
	if (mem == NULL)
		return (NULL);
	while (nmemb != 0)
	{
		mem[i] = '\0';
		i++;
		nmemb--;
	}
	return (mem);
}
