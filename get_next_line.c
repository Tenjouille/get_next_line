/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:02:10 by tbourdea          #+#    #+#             */
/*   Updated: 2022/11/22 12:21:00 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>

char	*get_next_line(int fd)
{
	
}

int	main(void)
{
	int		fd;
	char	*buff;
	size_t	size;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (-1);
	buff = get_next_line(fd);
	printf("%s\n", buff);
	return (0);
}
