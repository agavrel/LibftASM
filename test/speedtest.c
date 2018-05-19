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

while (++tmp < 1000000)
{
    ft_collatz(tmp);
    ft_collatz(tmp);
    ft_collatz(tmp);
    ft_collatz(tmp);
    ft_collatz(tmp);
    ft_collatz(tmp);
    ft_collatz(tmp);
    ft_collatz(tmp);
    ft_collatz(tmp);
    ft_collatz(tmp);

}


    return (0);
}
