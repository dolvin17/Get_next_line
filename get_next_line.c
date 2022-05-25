/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:04:58 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/25 21:32:09 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_buffer(int fd, void *size)
{
	char	*store;
	char	*ptr;

	ptr = read(int fd, char *size);
	store = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!store)
		return (NULL);
	else ()
}
int	main(void)
{
	int		fd;
	char	*str;

	fd = open("testing.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	return (0);
}
