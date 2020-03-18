/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminomiy <vminomiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:07:22 by vminomiy          #+#    #+#             */
/*   Updated: 2020/02/10 19:45:10 by vminomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char			*ft_strnew(size_t size)
{
	char			*str;
	size_t			i;

	i = 0;
	str = (char *)malloc(sizeof(*str) * size + 1);
	if (str == NULL)
		return (NULL);
	while (i <= size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*subs;
	size_t			i;

	if (s == NULL)
		return (NULL);
	subs = ft_strnew(len);
	if (subs == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[start + i];
		i++;
	}
	return (subs);
}

static int		ft_pickline(char **s, char **line)
{
	int				len;
	char			*aux;

	len = 0;
	while ((*s)[len] != '\n' && (*s)[len] != '\0')
		len++;
	if ((*s)[len] == '\n')
	{
		*line = ft_substr(*s, 0, len);
		aux = ft_strdup(&((*s)[len + 1]));
		free(*s);
		*s = aux;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		*line = ft_strdup(*s);
		ft_strdel(s);
		return (0);
	}
	return (1);
}

static int		ft_result(char **s, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && s[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	else
		return (ft_pickline(&s[fd], line));
}

int				get_next_line(int fd, char **line)
{
	int				ret;
	static char		*s[5000];
	char			buff[BUFFER_SIZE + 1];
	char			*aux;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buff);
		else
		{
			aux = ft_strjoin(s[fd], buff);
			free(s[fd]);
			s[fd] = aux;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (ft_result(s, line, ret, fd));
}
