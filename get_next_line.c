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
#define BUFFER_SIZE 7

char    *new_line_separator(char    *string)
{
    char    *saved_new_line;
    int         n;
    int         n2;

    n = 0;
    while (string[n] != '\n')
        n++;
    saved_new_line = (char *)malloc(sizeof(char) * (ft_strlen(string) - n));
    if (!saved_new_line)
        return (NULL);
    n2 = 0;
    while (string[n2])
        saved_new_line[n2++] = string[++n];
    saved_new_line[n2] = '\0';
    free(string);
    printf("%s", saved_new_line);
    return (saved_new_line);
}

char *get_next_line(int fd)
{
    char            *string;
    static char     *buffer;
    int     n;
    static char    *saved_new_line;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
            return (NULL);
    n = 1;
    while(!ft_strchr(string, '\n') && n) //если \n то в цикл не входим
    {
        n = read(fd, buffer, BUFFER_SIZE);
        buffer[n] = '\0';
        string = ft_strjoin(string, buffer);
    }
    free(buffer);
    printf("%s\n", string);
    saved_new_line = new_line_separator(string);

    printf("%s\n", saved_new_line);
    return (string);
}

int	main(void)
{
    int	fd = open("1.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
//    printf("%s", get_next_line(fd));
//    printf("%s", get_next_line(fd));
    return (0);
}


//        int t;
//
//        t = 0;
//        while (t < n)
//        {
//            printf("%c", buffer[t]);
//            if (buffer[t] == '\n')
//            {
//                ft_strjoin() //
//                return (0);
//            }
//            t++;
//        }

//    get_next_line(fd);
//    get_next_line(fd);