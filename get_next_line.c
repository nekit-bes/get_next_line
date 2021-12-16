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
#include <unistd.h>

//char    *ex_helper(char *ex_str)
//{
//    if (!ex_str)
//        return (NULL);
//    return (ex_str);
//}

//int    ex_readhelper(int ex_r,char *bufer)
//{
//    if (ex_r == -1)
//    {
//        free (bufer);
//        return (NULL);
//    }
//    return (ex_r);
//}

char    *n_after(char    *string)
{
    char    *str_after;
    int         n;
    int         n2;

    n = 0;
    while (string[n] != '\n')
        n++;
    str_after = (char *)malloc(sizeof(char) * (ft_strlen(string) - n + 1));
    //str_after = ex_helper(str_after);
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
    //str_before = ex_helper(str_before);
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
    int         r;

    if (fd <= 0 || BUFFER_SIZE <= 0)
        return (0);
    buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
//    bufer = ex_helper(bufer);
    if (!buf)
        return (NULL);
    r = 1;
    while(!ft_strchr(str, '\n') && r != 0) //если \n то в цикл не входим
    {
        r = read(fd, buf, BUFFER_SIZE);
        if (r == -1)
        {
            free (buf);
            return (NULL);
        }
//        r = *ex_readhelper(r, bufer);
        buf[r] = '\0';
        str = ft_strjoin(str, buf);
    }
    free(buf);
    //str_fine = ex_helper(str_fine = n_before(ft_strdup(str)));
    str_fine = n_before(ft_strdup(str));
    if (!str_fine)
        return (NULL);
    str = n_after(str);
    return (str_fine);
}

int	main(void)
{
    int	fd = open("files/empty", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    return (0);
}
