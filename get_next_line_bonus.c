/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:21:44 by tbourdea          #+#    #+#             */
/*   Updated: 2022/12/01 16:03:12 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_newline(char *arch, int size)
{
	int		i;
	int		j;
	char	*res;

	j = ft_strlen(arch);
	i = 0;
	if (size == 0)
	{
		free(arch);
		return (NULL);
	}
	while (arch[i] != '\n' && arch[i] != '\0')
		i++;
	if (arch[i] == '\n')
		i++;
	res = malloc(sizeof(char) * (j - i + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (arch[i])
		res[j++] = arch[i++];
	res[j] = '\0';
	free(arch);
	return (res);
}

char	*ft_row(char *arch)
{
	char	*res;
	int		len;
	int		i;

	i = -1;
	len = 0;
	while (arch[len] != '\n' && arch[len] != '\0')
		len++;
	if (arch[len] == '\n')
		len++;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	while (++i < len)
		res[i] = arch[i];
	res[i] = '\0';
	if (!len)
	{
		free(res);
		return (NULL);
	}
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	j = -1;
	i = -1;
	if (!s1)
		s1 = ft_empty_str(0);
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[++j])
		s3[j + i] = s2[j];
	s3[j + i] = '\0';
	free(s1);
	free(s2);
	return (s3);
}

char	*get_next_line(int fd)
{
	ssize_t		size;
	static char	*arch[1024];
	char		*buff;

	size = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (size != 0 && (!ft_gotcha(arch[fd])))
	{
		buff = ft_empty_str(BUFFER_SIZE);
		if (!buff)
			return (NULL);
		size = read(fd, buff, BUFFER_SIZE);
		if (size < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[size] = '\0';
		arch[fd] = ft_strjoin(arch[fd], buff);
	}
	buff = ft_row(arch[fd]);
	arch[fd] = ft_newline(arch[fd], size);
	return (buff);
}
