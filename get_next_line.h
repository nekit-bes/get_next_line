#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
#define GET_NEXT_LINE_GET_NEXT_LINE_H

# include <stdlib.h> //for malloc

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char    *get_next_line(int fd);
char    *before_n(char    *string);
char    *n_after(char    *string);
//char    *ex_helper(char *ex_str);
char	*ft_strchr(const char *s, int c);
//char	*ft_strchr(char *s, int c);
char    *ft_strjoin(char *s1, char *s2);
//char	*ft_strjoin(char *s1, char *s2);
//size_t	ft_strlen(const	char *s);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *src);
char    *null_helper(char *ex_str);
char    *read_helper(char *buf);

#endif //GET_NEXT_LINE_GET_NEXT_LINE_H
