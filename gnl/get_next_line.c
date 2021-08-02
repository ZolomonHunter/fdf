/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jangelia <jangelia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:15:25 by jangelia          #+#    #+#             */
/*   Updated: 2021/05/17 19:00:16 by jangelia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_remaining(char **line, char *remain, int sizeof_remain)
{
	int	check_read;

	if (ft_strchr(remain, '\n') != 0)
	{
		check_read = ft_strchr(remain, '\n') - remain;
		remain[check_read] = '\0';
		*line = ft_strdup(remain);
		if (*line == 0)
			return (-1);
		ft_strlcpy(remain, remain + check_read + 1, sizeof_remain);
		return (1);
	}
	else
	{
		*line = ft_strdup(remain);
		if (*line == 0)
			return (-1);
	}
	return (0);
}

int	set_remaining(char **line, char *remain, int check_read, int sizeof_remain)
{
	char	*tmp;

	if (check_read == -1)
		return (-1);
	if (remain[0] != '\0')
	{
		check_read = ft_strchr(remain, '\n') - remain;
		if (check_read < 0)
			check_read = 0;
		remain[check_read] = '\0';
		tmp = *line;
		*line = ft_strjoin(*line, remain);
		free(tmp);
		if (*line == 0)
			return (-1);
		ft_strlcpy(remain, remain + check_read + 1, sizeof_remain);
		return (1);
	}
	return (0);
}

int	get_next_line_main(int fd, char **line)
{
	static char	remain[BUFFER_SIZE + 1];
	char		*tmp;
	int			check_read;

	check_read = get_remaining(line, remain, sizeof(remain));
	if (check_read == 1 || check_read == -1)
		return (check_read);
	check_read = read(fd, remain, BUFFER_SIZE);
	if (check_read == -1)
		return (check_read);
	remain[check_read] = '\0';
	while (check_read > 0 && ft_strchr(remain, '\n') == 0)
	{
		tmp = *line;
		*line = ft_strjoin(*line, remain);
		free(tmp);
		if (*line == 0)
			return (-1);
		check_read = read(fd, remain, BUFFER_SIZE);
		if (check_read == -1)
			return (check_read);
		remain[check_read] = '\0';
	}
	return (set_remaining(line, remain, check_read, sizeof(remain)));
}

int	get_next_line(int fd, char **line)
{
	if (read(fd, 0, 0) < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	else
		return (get_next_line_main(fd, line));
}
