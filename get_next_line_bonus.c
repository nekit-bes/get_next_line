/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbellero <rbellero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 16:20:02 by rbellero          #+#    #+#             */
/*   Updated: 2021/12/20 09:51:17 by rbellero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h> // open
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 21
#endif // BUFFER_SIZE

char	*n_after(char	*str)
{
	char	*str_after;
	int		n;
	int		n2;

	n = 0;
	while (str[n] && str[n] != '\n')
		n++;
	if (!str[n])
	{
		free(str);
		return (NULL);
	}
	str_after = (char *)malloc(sizeof(char) * (ft_strlen(str) - n + 1));
	str_after = null_helper(str_after);
	n2 = 0;
	n++;
	while (str[n])
		str_after[n2++] = str[n++];
	str_after[n2] = '\0';
	free(str);
	return (str_after);
}

char	*before_n(char	*str)
{
	char	*before_str;
	int		n;

	n = 0;
	if (!str[n])
		return (NULL);
	while (str[n] && str[n] != '\n')
		n++;
	before_str = (char *)malloc(sizeof(char) * (n + 2));
	before_str = null_helper(before_str);
	n = 0;
	while (str[n] && str[n] != '\n')
	{
		before_str[n] = str[n];
		n++;
	}
	if (str[n] == '\n')
	{
		before_str[n] = str[n];
		n++;
	}
	before_str[n] = '\0';
	return (before_str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*buf;
	char		*str_fine;
	int			r;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	buf = null_helper(buf);
	r = 1;
	while (!ft_strchr(str[fd], '\n') && r != 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (read_helper(buf));
		buf[r] = '\0';
		str[fd] = ft_strjoin(str[fd], buf);
	}
	free(buf);
	str[fd] = null_helper(str[fd]);
	str_fine = before_n(str[fd]);
	str[fd] = n_after(str[fd]);
	return (str_fine);
}

int main(void)
{
	int	fd1;
	int fd2;

	fd1 = open("1.txt", O_RDONLY);
	fd2 = open("2.txt", O_RDONLY);
	printf("%s", get_next_line(fd1));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd2));
	printf("%s", get_next_line(fd1));
	return (0);
}
