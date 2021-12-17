#include "get_next_line.h"

//char	*ft_strchr(const char *s, int c)
//{
//    int		n;
//    char	j;
//
//    n = 0;
//    j = c;
//    if (!s)
//        return (0);
//    while (s[n])
//    {
//        if (s[n] == j)
//            return ((char *)s + n);
//        n++;
//    }
//    if (c == '\0')
//        return ((char *)s + n);
//    return (0);
//}

char	*ft_strchr(char *s, int c)
{
    int	i;

    i = 0;
    if (!s)
        return (0);
    if (c == '\0')
        return ((char *)&s[ft_strlen(s)]);
    while (s[i] != '\0')
    {
        if (s[i] == (char) c)
            return ((char *)&s[i]);
        i++;
    }
    return (0);
}

//char	*ft_strjoin(char const *s1, char const *s2)
//{
//    char	*res;
//    int		w1;
//    int		w2;
//
//    if (!(s1 && s2))
//        return (NULL);
//    res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
//    if (!res)
//        return (0);
//    w1 = 0;
//    while (s1[w1])
//    {
//        res[w1] = s1[w1];
//        w1++;
//    }
//    w2 = 0;
//    while (s2[w2])
//        res[w1++] = s2[w2++];
//    res[w1] = '\0';
//    return (res);
//}

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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(const char *s)
{
    size_t	i;

    i = 0;
    if (!s)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}

//size_t	ft_strlen(const	char *s)
//{
//    size_t	n;
//
//    n = 0;
//    while (s[n])
//        n++;
//    return (n);
//}

char	*ft_strdup(char *src)
{
    int		i;
    int		len;
    char	*str;

    len = 0;
    while (src[len])
        len++;
    str = (char*)malloc(sizeof(*str) * (len + 1));
    i = 0;
    while (i < len)
    {
        str[i] = src[i];
        i++;
    }
    return (str);
}
