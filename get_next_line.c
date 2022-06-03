/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghuertas <ghuertas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:04:58 by ghuertas          #+#    #+#             */
/*   Updated: 2022/06/03 17:33:36 by ghuertas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_buffer(int fd, char **storage)
{
	char	*aux;
	char	*buffer;
	int		bytes;

	if (BUFFER_SIZE > 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
	}
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes < 0 || buffer == NULL)
		return (-1);
	buffer[bytes] = '\0';
	aux = ft_strjoin(*storage, buffer);
	free(*storage);
	*storage = aux;
	free(buffer);
	buffer = NULL;
	return (bytes);
}
/*
void	split_storage(char **storage, char **line)
{
	size_t	len;
	char	*aux;

	len = ft_strchr(*storage, '\n') - *storage;
	*line = ft_substr(*storage, 0, len);
	aux = ft_substr(*storage, len + 1, ft_strlen(*storage) - len);
	free(*storage);
	*storage = aux;
}*/

int	main(void)
{
	FILE	*fp;
	char	*line;
	int		fd;
	int		n_linea;

	n_linea = 0;
	fp = fopen("test.txt", "r");
	fd = fileno(fp);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("La linea es %d: %s", n_linea, line);
		free(line);
		n_linea++;
	}
	return (0);
}