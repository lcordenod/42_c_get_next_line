/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:27:55 by lcordeno          #+#    #+#             */
/*   Updated: 2018/11/21 17:40:05 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int ret;
	char *relay;
	char *temp;
	char *dst;
	int i;

	i = 0;
	if (fd < 0 || !line)
		return (-1);
	dst = ft_strnew(1);
	while ((relay = ft_strchr(dst, '\n')) == 0)
	{
		if ((ret = read(fd, line, BUFF_SIZE)) > 0)
		{
			temp = dst;
			i = i + ret;
			dst = ft_strjoin(dst, *line);
			dst[i] = '\0';
			free(temp);
		}
	}
	return (0);
}

int		main()
{
	int fd;
	char **test;

	fd = open("test_gnl", O_RDONLY);
	get_next_line(fd, test);
	return (0);
}
