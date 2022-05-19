/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 03:17:27 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/19 05:14:38 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>	/* Malloc, free functions */
# include <unistd.h> 	/* Write function */
# include <fcntl.h> 	/* Read function */
# include <limits.h>	/* Macro defined OPEN_MAX */

/* libft functions */
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);

/* new functions */
char	*get_next_line(int fd);
int		read_buffer(int fd, char **storage);
#endif
