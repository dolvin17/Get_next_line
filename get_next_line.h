/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 03:17:27 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/26 21:34:20 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include <stdlib.h>	/* Malloc, free functions */
# include <unistd.h> 	/* Write function */
# include <stdio.h>
# include <fcntl.h> 	/* Read function */
# include <limits.h>	/* Macro defined OPEN_MAX */

/* libft functions */
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int __c);

/* new functions */
char	*get_next_line(int fd);
int		read_buffer(int fd, char *dest);
#endif
