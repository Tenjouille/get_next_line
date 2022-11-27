/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:14:57 by tbourdea          #+#    #+#             */
/*   Updated: 2022/11/27 17:48:52 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_malloc(int size)
{
	char	*res;

	res = malloc(sizeof(char) * size);
	if (!res)
		return (NULL);
	return (res);
}

// char	*ft_empty_str(void)
// {
// 	char	*str;

// 	str = malloc(sizeof(char));
// 	if (!str)
// 		return (NULL);
// 	str[0] = '\0';
// 	return (str);
// }

int	ft_strlen(char *str)
{
	int	j;

	j = 0;
	while (str[j])
		j++;
	return (j);
}

int	ft_gotcha(char *arch)
{
	int	i;

	i = 0;
	if (!arch)
		return (0);
	while (arch[i])
	{
		if (arch[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
