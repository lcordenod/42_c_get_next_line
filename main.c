/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 09:23:55 by lcordeno          #+#    #+#             */
/*   Updated: 2018/11/28 17:56:18 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdlib.h>

int	ret;

int		main(int ac, char **av)
{
	int		fd;
	char	*test;

	if (ac < 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &test)))
	{
		printf("line = %s \n ret = %d\n", test, ret);
		free(test);
	}
	ret = get_next_line(fd, &test);
	printf("line = %s \n ret = %d\n", test, ret);
	close(fd);
	return (0);
}
