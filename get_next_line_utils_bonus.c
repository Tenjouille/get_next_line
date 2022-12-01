/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:22:09 by tbourdea          #+#    #+#             */
/*   Updated: 2022/12/01 16:03:39 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_empty_str(int len)
{
	char	*str;

	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (len >= 0)
	{
		str[len] = '\0';
		len--;
	}
	return (str);
}

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
