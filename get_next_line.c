/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:04:58 by ghuertas          #+#    #+#             */
/*   Updated: 2022/06/03 19:06:41 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	void	*buffer;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		return (-1);
	read(fd, buffer, 100);
	while (buffer)
	{
		write(1, buffer, 1);
		i++;
	}
	close(fd);
	return (0);
}
