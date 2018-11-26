/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:27:55 by lcordeno          #+#    #+#             */
/*   Updated: 2018/11/26 18:32:56 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

void	ft_buff_cat(char *buff, char **tmp, int ret)
{
	*tmp = ft_strjoin(*tmp, buff);
	buff[ret] = '\0';
}

void	*ft_move_tmp(char *tmp)
{
	while (*tmp != '\n')
		tmp++;
	tmp++;
	return (tmp);
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
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	int ret;
	char buff[BUFF_SIZE + 1];
	static char *tmp;

	ret = 0;
	if (fd < 0 || !line || !BUFF_SIZE)
		return (-1);
	if (!tmp)
		tmp = ft_strnew(0);
	while ((ft_strchr(tmp, '\n') == 0 && (ret = read(fd, buff, BUFF_SIZE)) > 0))
		ft_buff_cat(buff, &tmp, ret);
	if ((ft_strchr(tmp, '\n') == 0 && !(ret)))
	{
		*line = tmp;
		return (0);
	}
	if (ret < 0)
		return (-1);
	*line = ft_chrncpy(tmp, *line, '\n');
	tmp = ft_move_tmp(tmp);
	return (1);
}
