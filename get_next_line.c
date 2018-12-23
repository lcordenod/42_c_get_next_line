/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:27:55 by lcordeno          #+#    #+#             */
/*   Updated: 2018/12/02 17:56:53 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_buff_cat(char *buff, char **dst, int ret)
{
	char *temp;

	temp = *dst;
	buff[ret] = '\0';
	if ((*dst = ft_strjoin(*dst, buff)) == 0)
		return (-1);
	free(temp);
	return (0);
}

char	*ft_move_cpy(char *cpy)
{
	while (*cpy != '\n')
		cpy++;
	cpy++;
	return (cpy);
}

char	*ft_chrncpy(char *s, char *line, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c)
		i++;
	if (!(line = (char*)malloc(sizeof(char) * i + 1)))
		return (0);
	line = ft_strncpy(line, s, i);
	line[i] = '\0';
	return (line);
}

int		ft_cpy_to_cpy(int fd, char **cpy, char **line)
{
	char		*tempo;

	if ((*line = ft_chrncpy(cpy[fd], *line, '\n')) == 0)
		return (-1);
	tempo = cpy[fd];
	if ((cpy[fd] = ft_strdup(ft_move_cpy(cpy[fd]))) == NULL)
		return (-1);
	free(tempo);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*cpy[4864];

	if (fd < 0 || read(fd, 0, 0) == -1 || !line || !BUFF_SIZE)
		return (-1);
	if (!cpy[fd])
		cpy[fd] = ft_strnew(0);
	while (ft_strchr(cpy[fd], '\n') == 0 && (ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ft_buff_cat(buff, &cpy[fd], ret) == -1 || ret < 0)
			return (-1);
	}
	if (ft_strchr(cpy[fd], '\n') == 0 && ret == 0)
	{
		if (ft_strlen(cpy[fd]))
		{
			if ((*line = ft_chrncpy(cpy[fd], *line, '\0')) == 0)
				return (-1);
			ft_strclr(cpy[fd]);
			return (1);
		}
		return (0);
	}
	return (ft_cpy_to_cpy(fd, cpy, line) != -1) ? 1 : -1;
}
