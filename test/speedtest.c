#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include "libfts.h"
#include <math.h>

int main(void)
{
long int tmp = -1;

while (++tmp < 100000000)
{
    ft_islower('%');
    ft_islower('a');
    ft_islower('e');
    ft_islower('B');
    ft_islower('X');
    ft_islower('h');
    ft_islower('y');
    ft_islower('0');
    ft_islower('1');
    ft_islower('%');
    ft_islower('%');
    ft_islower('5');
    ft_islower('%');
    ft_islower('%');
    ft_islower('%');
    ft_islower('%');
    ft_islower('%');
    ft_islower('%');
    ft_islower('%');
    ft_islower('%');
    ft_islower('%');
}


    return (0);
}
