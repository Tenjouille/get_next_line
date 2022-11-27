/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbourdea <tbourdea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:02:58 by tbourdea          #+#    #+#             */
/*   Updated: 2022/11/27 15:07:57 by tbourdea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_newline(char *arch, int size);
char	*ft_row(char *arch);
int		ft_gotcha(char *arch);
int		ft_strlen(char *str);
char	*ft_empty_str(void);
char	*ft_malloc(int size);
char	*ft_strjoin(char *s1, char *s2);


#endif