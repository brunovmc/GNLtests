/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:24:20 by cpereira          #+#    #+#             */
/*   Updated: 2020/02/17 20:24:43 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *frase)
{
	int i;

	i = 0;
	while (frase[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*frase;
	size_t	i;
	size_t	j;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	frase = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char*));
	if (frase == 0)
		return (0);
	j = 0;
	while (s1[i] != '\0')
	{
		frase[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		frase[i] = s2[j];
		j++;
		i++;
	}
	frase[i] = '\0';
	return (frase);
}

int		ft_strpos(const char *palheiro, char agulha)
{
	int i;

	i = 0;
	if (palheiro == 0 || agulha == 0)
		return (0);
	while (palheiro[i] != '\0')
	{
		if (palheiro[i] == agulha)
			return (i);
		i++;
	}
	return (-1);
}

char	ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	s_len;

	if (s == 0)
		return (0);
	s_len = ft_strlen(s);
	i = 0;
	if (!(ret = malloc((len + 1) * sizeof(char))))
		return (0);
	while (i < len && (start + i) < s_len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strdup(const char *source)
{
	unsigned char	*aux;
	int				i;

	i = 0;
	aux = malloc(ft_strlen(source) + 1);
	if (!aux)
		return (NULL);
	while (source[i] != '\0')
	{
		aux[i] = source[i];
		i++;
	}
	aux[i] = '\0';
	return (char *)aux;
}
