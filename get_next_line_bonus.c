/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:02:18 by dolvin17          #+#    #+#             */
/*   Updated: 2022/06/10 17:09:58 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_before_jump(const char *str)
{
	char	*res_memory;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	res_memory = ft_calloc(i + 1, sizeof * res_memory);
	if (!res_memory)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		res_memory[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res_memory[i] = str[i];
		i++;
	}
	return (res_memory);
}

char	*get_after_jump(const char *str)
{
	char	*res_memory;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	j = 0;
	while (str && str[j])
		j++;
	res_memory = ft_calloc((j - i) + 1, sizeof * res_memory);
	if (!res_memory)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		res_memory[j] = str[i + j];
		j++;
	}
	return (res_memory);
}

void	read_line(int fd, char **storage, char **tempo)
{
	char	*mem_reserve;
	long	readed;

	mem_reserve = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!mem_reserve)
		return ;
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, mem_reserve, BUFFER_SIZE);
		if (readed < 0)
		{
			ft_free_strs(&mem_reserve, storage, tempo);
			return ;
		}
		mem_reserve[readed] = '\0';
		*tempo = ft_strdup(*storage);
		ft_free_strs(storage, 0, 0);
		*storage = ft_strjoin(*tempo, mem_reserve);
		ft_free_strs(tempo, 0, 0);
		if (ft_strchr(*storage, '\n'))
			break ;
	}
	ft_free_strs(&mem_reserve, 0, 0);
}

char	*split_and_swap(char **storage, char **tempo)
{
	char	*line;

	*tempo = ft_strdup(*storage);
	ft_free_strs(storage, 0, 0);
	*storage = get_after_jump(*tempo);
	line = get_before_jump(*tempo);
	ft_free_strs(tempo, 0, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*tempo;
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	tempo = NULL;
	read_line(fd, &storage[fd], &tempo);
	if (storage[fd] != NULL && *storage[fd] != '\0')
		line = split_and_swap(&storage[fd], &tempo);
	if (!line || *line == '\0')
	{
		ft_free_strs(&storage[fd], &line, &tempo);
		return (NULL);
	}
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;

	fd = 0;
	if (fd == -1)
		return (-1);
	fd = open("test.txt", O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}
*/