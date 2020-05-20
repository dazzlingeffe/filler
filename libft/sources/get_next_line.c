/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmeowth <cmeowth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 22:03:06 by cmeowth           #+#    #+#             */
/*   Updated: 2019/12/28 23:43:46 by cmeowth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				ft_next_line(char **files, int fd, char **line)
{
	char		*temp;
	int			len;

	len = 0;
	while (files[fd][len] != '\n' && files[fd][len] != '\0')
		len++;
	if (files[fd][len] == '\n')
	{
		*line = ft_strsub(files[fd], 0, len);
		temp = ft_strdup(files[fd] + len + 1);
		free(files[fd]);
		files[fd] = temp;
		if (files[fd][0] == '\0')
			ft_strdel(&files[fd]);
	}
	else if (files[fd][len] == '\0')
	{
		*line = ft_strdup(files[fd]);
		ft_strdel(&files[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char *files[10240];
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	int			r;

	if (fd < 0 || !line || (read(fd, NULL, 0) < 0) || fd > 10240)
		return (-1);
	while (!ft_strchr(files[fd], '\n'))
	{
		if (!(r = read(fd, buffer, BUFF_SIZE)))
		{
			if (!(*line = files[fd]))
				return (0);
			files[fd] = NULL;
			return (1);
		}
		buffer[r] = '\0';
		temp = files[fd];
		files[fd] = ft_strjoin(files[fd], buffer);
		free(temp);
		if (!files[fd])
			return (-1);
	}
	return (ft_next_line(files, fd, line));
}
