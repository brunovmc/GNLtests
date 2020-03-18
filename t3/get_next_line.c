/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpereira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 21:03:54 by cpereira          #+#    #+#             */
/*   Updated: 2020/02/17 20:15:34 by cpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ret_frase(char **frase, char **line)
{
	int		posic;
	char	*aux;

	aux = (char*)malloc(ft_strlen(*frase) + 1);
	posic = ft_strpos(*frase, '\n');
	if (posic >= 0)
	{
		*line = ft_substr(*frase, 0, posic);
		aux = ft_substr(*frase, posic + 1, ft_strlen(*frase));
		free(*frase);
		*frase = aux;
		aux = NULL;
		return (1);
	}
	else
		return (0);
}

int	get_next_line(int fd, char **line)
{
	static char		*frase;
	char			buff[BUFFER_SIZE + 1];
	ssize_t			ret;

	if (fd < 0 || line == NULL)
		return (-1);
	if (frase[fd] != NULL)
	{
		if (ret_frase(&frase[fd], line))
			return (1);
	}
	else
		frase[fd] = ft_strdup("");
	buffer = (char*)malloc(BUFFER_SIZE + 1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		bf[ret] = '\0';
		frase[fd] = frase[fd] == NULL ? ft_strdup(buff) :
			ft_strjoin(frase[fd], buff);
		if (ret_frase(&frase[fd], line))
			return (1);
	}
	*line = ret < 0 ? NULL : frase[fd];
	frase[fd] = NULL;
	return (ret);
}
