#ifndef _LIBFTS
# define _LIBFTS

#include <stddef.h>

int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isupper(int c);
int			ft_islower(int c);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isprint(int c);
int			ft_strlen(char *str);
void		ft_puts(char *str);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strcat(char *restrict s1, const char *restrict s2);
int			ft_pow(int x, int y);
char		*ft_strdup(const char *s);
int         ft_abs(int x);
void        *ft_memset(void *s, int c, size_t n);
void        ft_bzero(void *s, size_t n);
int         ft_rand(void);
void        ft_swap(int *a, int *b);
unsigned int        ft_collatz(int n);

#endif
