/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:04:58 by ghuertas          #+#    #+#             */
/*   Updated: 2022/05/19 05:14:39 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int	read_buffer(int fd, char **storage)
{
	int				bytes;
	char			*temp;
	char			*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE)

	if ((bytes < 0)
		return (NULL);
	buffer[bytes] = '\0';
	temp = ft_strjoin(*storage, buffer);
	free(*storage);
	*storage = temp;
	free(buffer);
	buffer = NULL;
	return (0);
}

