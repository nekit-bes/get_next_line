#ifndef GET_NEXT_LINE_BONUS_H
#define GET_NEXT_LINE_BONUS_H

# include <stdlib.h> //for malloc

char    *get_next_line(int fd);
char    *before_n(char  *string);
char    *n_after(char   *string);
char	*ft_strchr(const char   *s, int   c);
char    *ft_strjoin(char    *s1, char  *s2);
size_t	ft_strlen(const char *s);
char    *null_helper(char *ex_str);
char    *read_helper(char *buf);

#endif //GET_NEXT_LINE_BONUS_H
