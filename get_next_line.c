/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:04:58 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/26 21:40:17 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_buffer(int fd, char *dest)
{
	char	*store;
	int		ptr;
	char	*temp;
	char	*buf;

	store = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	ptr = read(fd, buf, BUFFER_SIZE);
	if (!store)
		return (NULL);
	if (ptr < 1)
		return (-1);
	store[ptr] = '\0';
	temp = ft_strjoin(*dest, buf);
	free(*dest);
	*dest = temp;
	free(buf);
	buf = NULL;
	return (ptr);
}

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("testing.txt", O_RDONLY, 10);
	if (fd == -1)
		return (-1);
	str = read_buffer(fd, str);
	printf("%s\n", *str);
	close(fd);
	return (0);
}
