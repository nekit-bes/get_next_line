/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: infiless <infiless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:24:50 by infiless          #+#    #+#             */
/*   Updated: 2021/12/11 16:23:14 by infiless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> // open
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 12

char *get_next_line(int fd)
{
    static char	*buffer;
    int     n;

    buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    n = 1;
    while(n)
    {
        n = read(fd, buffer, BUFFER_SIZE);
        buffer[n] = '\0';
        int t;

        t = 0;
        while (t < n)
        {
            printf("%c", buffer[t]);
            if (buffer[t] == '\n')
            {
//                ft_strjoin()\\ должен вернуть указатель на элементы справа от \n
                return (0);
            }
            t++;
        }
    }
    free(buffer);
}

int	main(void)
{
    int		fd;

    fd = open("1.txt", O_RDONLY);
    get_next_line(fd);
    get_next_line(fd);
    get_next_line(fd);
    return (0);
}
