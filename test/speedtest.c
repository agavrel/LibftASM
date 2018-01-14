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
    unsigned cycles_high = 0, cycles_low = 0;
    unsigned cycles_high1 = 0, cycles_low1 = 0;
    unsigned start = 0, end = 0;
    int tmp = 0;
    unsigned count = 0;
    char a;

while (++tmp < 1000000)
{
    asm volatile ("CPUID\n\t"
    "RDTSC\n\t"
    "mov %%edx, %0\n\t"
    "mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low)::
    "%rax", "%rbx", "%rcx", "%rdx");

    a = ft_toupper('%');

    asm volatile("RDTSCP\n\t"
    "mov %%edx, %0\n\t"
    "mov %%eax, %1\n\t"
    "CPUID\n\t": "=r" (cycles_high1), "=r" (cycles_low1)::
    "%rax", "%rbx", "%rcx", "%rdx");

    start = ( ((uint64_t)cycles_high << 32) | cycles_low );
    end = ( ((uint64_t)cycles_high1 << 32) | cycles_low1 );
    count += (end - start);

    ++tmp;
}

tmp = 0;
printf("%d\n", count);
count = 0;

while (++tmp < 1000000)
{
    asm volatile ("CPUID\n\t"
    "RDTSC\n\t"
    "mov %%edx, %0\n\t"
    "mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low)::
    "%rax", "%rbx", "%rcx", "%rdx");

    a = ft_toupper_iburel('%');

    asm volatile("RDTSCP\n\t"
    "mov %%edx, %0\n\t"
    "mov %%eax, %1\n\t"
    "CPUID\n\t": "=r" (cycles_high1), "=r" (cycles_low1)::
    "%rax", "%rbx", "%rcx", "%rdx");

    start = ( ((uint64_t)cycles_high << 32) | cycles_low );
    end = ( ((uint64_t)cycles_high1 << 32) | cycles_low1 );
    count += (end - start);

    ++tmp;
}

printf("%d\n", count);

    a = a - 5;
    return (0);
}
