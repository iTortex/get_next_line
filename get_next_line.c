/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcele <amarcele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 22:41:11 by amarcele          #+#    #+#             */
/*   Updated: 2020/06/26 00:13:32 by amarcele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, s1, i + 1);
	ft_strlcat(str, s2, i + 1);
	return (str);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	int			i;
	int			y;
	int			b;

	i = ft_strlen(dst);
	y = ft_strlen(src);
	b = i + y;
	if ((int)size >= i)
	{
		size = size - i;
		while (size > 1 && *src != '\0')
		{
			dst[i++] = *src++;
			size--;
		}
		if (size != 0)
			dst[i] = '\0';
		return (b);
	}
	else
		return (y + size);
}

static char		*chekost(char *ost, char **line)
{
	char		*stop;

	stop = NULL;
	if (!line)
		return (stop);
	if (ost)
	{
		if ((stop = ft_strchr(ost, '\n')))
		{
			*stop = '\0';
			*line = ft_strdup(ost);
			stop++;
			ft_strlcpy(ost, stop, ft_strlen(stop) + 1);
		}
		else
		{
			*line = ft_strdup(ost);
			free(ost);
		}
	}
	else
		*line = ft_calloc(0, 0);
	return (stop);
}

static int		musthavecheck(char *str, int fd, char **line)
{
	if (!str || BUFFER_SIZE < 1 || fd < 0 || read(fd, str, 0) != 0 || !line)
	{
		free(str);
		return (-1);
	}
	else
		return (0);
}

int				get_next_line(int fd, char **line)
{
	char		*str;
	char		*stop;
	ssize_t		chekbytes;
	char		*tofree;
	static char	*ost;

	stop = chekost(ost, line);
	str = malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (musthavecheck(str, fd, line) == -1)
		return (-1);
	while (!stop && (chekbytes = read(fd, str, BUFFER_SIZE)) > 0)
	{
		str[chekbytes] = '\0';
		if ((stop = ft_strchr(str, '\n')))
		{
			*stop = '\0';
			ost = ft_strdup(++stop);
		}
		tofree = *line;
		*line = ft_strjoin(*line, str);
		free(tofree);
	}
	free(str);
	return (stop) ? 1 : 0;
}
