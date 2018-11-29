/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:27:55 by lcordeno          #+#    #+#             */
/*   Updated: 2018/11/28 18:53:34 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

void	ft_buff_cat(char *buff, char **dst, int ret)
{
	char *temp;

	temp = *dst;
	buff[ret] = '\0';
	*dst = ft_strjoin(*dst, buff);
	free(temp);
}

void	*ft_move_cpy(char *cpy)
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

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	static char	*cpy;
	char		*tempo;

	ret = 0;
	if (fd < 0 || read(fd, 0, 0) == -1 || !line)
		return (-1);
	if (!cpy)
		cpy = ft_strnew(0);
	while ((ft_strchr(cpy, '\n') == 0 && (ret = read(fd, buff, BUFF_SIZE)) > 0))
		ft_buff_cat(buff, &cpy, ret);
	if (ret < 0)
		return (-1);
	if (ft_strchr(cpy, '\n') == 0 && ret == 0)
	{
		if (ft_strlen(cpy))
		{
			*line = ft_chrncpy(cpy, *line, '\0');
			ft_strclr(cpy);
			return (1);
		}
		return (0);
	}
	*line = ft_chrncpy(cpy, *line, '\n');
	tempo = cpy;
	cpy = ft_strdup(ft_move_cpy(cpy));
	free(tempo);
	return (1);
}
