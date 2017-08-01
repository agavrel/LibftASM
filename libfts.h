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

#endif
