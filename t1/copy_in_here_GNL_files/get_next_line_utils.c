/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:32:40 by anolivei          #+#    #+#             */
/*   Updated: 2020/02/19 00:25:15 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	long int size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*substring;

	i = 0;
	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	if ((substring = malloc((len + 1) * sizeof(char))) == 0)
		return (0);
	while (i < len && (start + i) < s_len)
	{
		substring[i] = s[i + start];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	if ((string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
					* sizeof(*string))) == 0)
		return (0);
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	free((char *)s1);
	string[i] = '\0';
	return (string);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		len;

	len = ft_strlen(s1) + 1;
	if ((cpy = ((char *)malloc(sizeof(char) * len))) != 0)
	{
		ft_strlcpy(cpy, s1, len);
		return (cpy);
	}
	else
		return (0);
}

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (src == 0)
		return (0);
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
