#include "get_next_line.h"

char    *null_helper(char *str)
{
    if (!str)
        return (NULL);
    return (str);
}

char    *read_helper(char *buf)
{
    free (buf);
    return (NULL);
}

size_t	ft_strlen(const	char *s)
{
    size_t	n;

    n = 0;
    while (s[n])
        n++;
    return (n);
}

char	*ft_strchr(const char *s, int c)
{
    int		n;
    char	j;

    n = 0;
    j = c;
    if (!s)
        return (0);
    while (s[n])
    {
        if (s[n] == j)
            return ((char *)s + n);
        n++;
    }
    if (c == '\0')
        return ((char *)s + n);
    return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
    size_t	i;
    size_t	j;
    char	*res;

    if (!s1)
    {
        s1 = (char *)malloc(1 * sizeof(char));
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
    res = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
    if (res == NULL)
        return (NULL);
    i = -1;
    j = 0;
    while (s1[++i] != '\0')
        res[i] = s1[i];
    while (s2[j] != '\0')
        res[i++] = s2[j++];
    res[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    free(s1);
    return (res);
}
