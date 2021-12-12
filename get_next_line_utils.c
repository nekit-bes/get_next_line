#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
    int		n;
    char	j;

    n = 0;
    j = c;
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

char	*ft_strjoin(char const *s1, char const *s2)
{
    char	*res;
    int		w1;
    int		w2;

    if (!(s1 && s2))
        return (NULL);
    res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if (!res)
        return (0);
    w1 = 0;
    while (s1[w1])
    {
        res[w1] = s1[w1];
        w1++;
    }
    w2 = 0;
    while (s2[w2])
        res[w1++] = s2[w2++];
    res[w1] = '\0';
    return (res);
}

size_t	ft_strlen(const	char *s)
{
    size_t	n;

    n = 0;
    while (s[n])
        n++;
    return (n);
}