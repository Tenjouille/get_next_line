/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:02:10 by tbourdea          #+#    #+#             */
/*   Updated: 2022/11/27 17:55:17 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_newline(char *arch, int size)
{
	int	len;

	len = 0;
	if (size == 0)
	{
		free(arch);
		return (NULL);
	}
	while (arch[len] != '\n' && arch[len] != '\0')
		len++;
	if (arch[len] == '\n')
		len++;
	return (&arch[len]);
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
		res = ft_malloc(len + 2);
	else if (arch[len] == '\0')
		res = ft_malloc(len + 1);
	while (++i < len)
		res[i] = arch[i];
	if (arch[len] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s3;

	j = -1;
	i = -1;
	if (!s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while (&s1[++i])
		s3[i] = s1[i];
	while (s2[++j])
		s3[j + i] = s2[j];
	s3[j + i] = '\0';
	free(s2);
	return (s3);
}

char	*get_next_line(int fd)
{
	ssize_t		size;
	static char	*arch;
	char		*buff;

	size = 1;
	while (size != 0 && (!ft_gotcha(arch)))
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		size = read(fd, buff, BUFFER_SIZE);
		if (size < 0)
			return (NULL);
		buff[size] = '\0';
		arch = ft_strjoin(arch, buff);
	}
	buff = ft_row(arch);
	arch = ft_newline(arch, size);
	return (buff);
}

int	main(void)
{
	int		fd;
	char	*buff;

	// fd = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	buff = get_next_line(fd);
	printf("1 : %s", buff);
	free(buff);
	buff = get_next_line(fd);
	printf("2 : %s", buff);
	free(buff);
	buff = get_next_line(fd);
	printf("3 : %s", buff);
	free(buff);
	buff = get_next_line(fd);
	printf("4 : %s", buff);
	free(buff);
	buff = get_next_line(fd);
	printf("5 : %s", buff);
	free(buff);
	return (0);
}
