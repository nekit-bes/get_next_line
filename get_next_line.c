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
#define BUFFER_SIZE 9999

char    *n_after(char    *string)
{
    char    *str_after;
    int         n;
    int         n2;

    n = 0;
    while (string[n] != '\n')
        n++;
    str_after = (char *)malloc(sizeof(char) * (ft_strlen(string) - n + 1));
    if (!str_after)
        return (NULL);
    n2 = 0;
    while (string[n2])
    {
        str_after[n2] = string[++n];
        n2++;
    }
    str_after[n2] = '\0';
    free(string);
    return (str_after);
}

char    *n_before(char    *string)
{
    char    *str_before;
    int         n;
    int         n2;

    n = 0;
    while (string[n] != '\n')
        n++;
    str_before = (char *)malloc(sizeof(char) * n);
    if (!str_before)
        return (NULL);
    n2 = 0;
    while (string[n2] && string[n2] != '\n')
    {
        str_before[n2] = string[n2];
        n2++;
    }

    str_before[n2] = '\0';
    free(string);
    return (str_before);
}

char *get_next_line(int fd)
{
    static char *str;
    char        *buf;
    char        *str_fine;
    int         n;

    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (NULL);
    n = 1;
    while(!ft_strchr(str, '\n') && n != 0) //если \n то в цикл не входим
    {
        n = read(fd, buf, BUFFER_SIZE);
        buf[n] = '\0';
        str = ft_strjoin(str, buf);
    }
    free(buf);

    str_fine = n_before(ft_strdup(str));
    str = n_after(str);
    return (str_fine);
}

int	main(void)
{
    int	fd = open("1.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
//    printf("%s\n", get_next_line(fd));
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