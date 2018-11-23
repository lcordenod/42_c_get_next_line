/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:27:55 by lcordeno          #+#    #+#             */
/*   Updated: 2018/11/23 18:00:44 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

void	ft_buff_cat(char *buff, char **fullcpy, int ret)
{
	*fullcpy = ft_strjoin(*fullcpy, buff);
	buff[ret] = '\0';
}

char	*ft_chrncpy(const char *s, char c)
{
	char *str;
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != c)
		i++;
	if (!(str = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	while (j < i)
	{
		str[j] = s[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	int ret;
	char buff[BUFF_SIZE + 1];
	static char *fullcpy;

	ret = 0;
	if (fd < 0 || !line || !BUFF_SIZE)
		return (-1);
	if (!fullcpy)
		fullcpy = ft_strnew(0);
	while ((ft_strchr(fullcpy, '\n') == 0 && (ret = read(fd, buff, BUFF_SIZE)) > 0))
		ft_buff_cat(buff, &fullcpy, ret);
	if ((ft_strchr(fullcpy, '\n') == 0 && !(ret)))
	{
		*line = fullcpy;
		return (0);
	}
	*line = ft_chrncpy(fullcpy, '\n');
	fullcpy = NULL;
	printf("line: %s\n", *line);
	if (ret < 0)
		return (-1);
	return (1);
}

int		main()
{
	int fd;
	char **test;

	fd = open("test_gnl", O_RDONLY);
	printf("res: %d\n", get_next_line(fd, test));
	printf("res: %d\n", get_next_line(fd, test));
	printf("res: %d\n", get_next_line(fd, test));
	printf("res: %d\n", get_next_line(fd, test));
	printf("res: %d\n", get_next_line(fd, test));
	printf("res: %d\n", get_next_line(fd, test));
	close(fd);
	return (0);
}
