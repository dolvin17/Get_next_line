/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolvin17 <grks_17@hotmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 03:17:21 by ghuertas          #+#    #+#             */
/*   Updated: 2022/06/10 16:32:53 by dolvin17         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s;
	int		len_s1;
	int		len_s2;

	len_s1 = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[len_s1])
		len_s1++;
	len_s2 = 0;
	while (s2 && s2[len_s2])
		len_s2++;
	s = ft_calloc(len_s1 + len_s2 + 1, sizeof * s);
	if (!s)
		return (NULL);
	len_s1 = -1;
	while (s1 && s1[++len_s1])
		s[len_s1] = s1[len_s1];
	len_s2 = -1;
	while (s2 && s2[++len_s2])
		s[len_s1 + len_s2] = s2[len_s2];
	return (s);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		size;

	if (!s1)
		return (ft_strdup(""));
	size = 0;
	while (s1[size])
		size++;
	s2 = ft_calloc(size + 1, sizeof * s2);
	if (!s2)
		return (NULL);
	size = 0;
	while (s1[size])
	{
		s2[size] = s1[size];
		size++;
	}
	return (s2);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			i;

	p = NULL;
	if (!count || (count && SIZE_MAX / count > size))
	{
		p = malloc(count * size);
		if (p != NULL)
		{
			i = 0;
			while (i < count * size)
				*(p + i++) = '\0';
		}
	}
	return (p);
}

void	ft_free_strs(char **str, char **str1, char **str2)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (str1 && *str1)
	{
		free(*str1);
		*str1 = NULL;
	}
	if (str2 && *str2)
	{
		free(*str2);
		*str2 = NULL;
	}
}
