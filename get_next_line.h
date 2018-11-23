/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcordeno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:53:20 by lcordeno          #+#    #+#             */
/*   Updated: 2018/11/23 17:59:59 by lcordeno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define BUFF_SIZE 100000
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include "libft/libft.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>


/*typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
*/
int		get_next_line(const int fd, char **line);

#endif
