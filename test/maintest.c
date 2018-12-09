#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include "libfts.h"
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

#define BOLD	"\x1B[1m"
#define BLINK	"\x1B[5m"
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define NC		"\x1B[0m"
#define KO		RED BOLD BLINK "KO" NC
#define OK		GRN BOLD "OK" NC



typedef struct
{
	bool display;
}	Config;

Config g_Config = {false};

bool	ft_assert(const unsigned long a, const unsigned long b)
{
	if (a == b)
	{
		if (g_Config.display)
			dprintf(1, OK" \t%lu -> %lu\n", a, b);
		return true;
	}
	dprintf(1, KO" \t%lu -> %lu\n", a, b);
	return false;
}

bool	ft_assert_int(const int i, const int a, const int b)
{
	if (a == b)
	{
		if (g_Config.display)
			dprintf(1, OK" \t[%d] %d -> %d\n", i, a, b);
		return true;
	}
	dprintf(1, KO" \t[%d] %d -> %d\n", i, a, b);
	return false;
}

bool	ft_assert_long(const long i, const long a, const long b)
{
	if (a == b)
	{
		if (g_Config.display)
			dprintf(1, OK" \t[%ld] %ld -> %ld\n", i, a, b);
		return true;
	}
	dprintf(1, KO" \t[%ld] %ld -> %ld\n", i, a, b);
	return false;
}

bool	ft_assert_str(const char *a, const char *b)
{
	if (!strcmp(a, b))
	{
		if (g_Config.display)
			dprintf(1, OK" \t%s -> %s\n", a, b);
		return true;
	}
	dprintf(1, KO" \t%s -> %s\n", a, b);
	return false;
}

/*
**************************** is_alpha ******************************************
*/

void ft_isalpha_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, isalpha(i), ft_isalpha(i));


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}


/*
**************************** isdigit *******************************************
*/
void ft_isdigit_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, isdigit(i), ft_isdigit(i));


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}

/*
**************************** isalnum *******************************************
*/

void ft_isalnum_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, isalnum(i), ft_isalnum(i));


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}

/*
**************************** ft_strncmp *****************************************
*/

void ft_strncmp_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	cnt += ft_assert(strncmp("hello", "hella", 5), ft_strncmp("hello", "hella", 5));
	cnt += ft_assert(strncmp("hella", "hello", 5), ft_strncmp("hella", "hello", 5));
	cnt += ft_assert(strncmp("hello", "hello", 5), ft_strncmp("hello", "hello", 5));
	cnt += ft_assert(strncmp("hello", "hello", 0), ft_strncmp("hello", "hello", 0));
	cnt += ft_assert(strncmp("hello", "", 5), ft_strncmp("hello", "", 5));
	cnt += ft_assert(strncmp("", "", 1), ft_strncmp("", "", 1));
	cnt += ft_assert(strncmp("helloa", "hello", 6), ft_strncmp("helloa", "hello", 6));
	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 7);
}

/*
**************************** ft_strcat *****************************************
*/
void ft_strcat_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;
	char	mycat[64] = "a";
	char	*str = malloc(64 * sizeof(char));;

	ft_strcat(mycat, " hello");
	strcpy(str, mycat);
	cnt += ft_assert_str("a hello", str);

	ft_strcat(mycat, "!");
	strcpy(str, mycat);
	cnt += ft_assert_str("a hello!", str);

	ft_strcat(mycat, "");
	strcpy(str, mycat);
	cnt += ft_assert_str("a hello!", str);

	ft_strcat(mycat, " world..");
	strcpy(str, mycat);
	cnt += ft_assert_str("a hello! world..", str);

	free(str);
	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 4);
}

/*
**************************** ft_pow *****************************************
*/

void ft_pow_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	cnt += ft_assert_int(1, pow(2, 3), ft_pow(2, 3));
	cnt += ft_assert_int(2, pow(2, 0), ft_pow(2, 0));
	cnt += ft_assert_int(3, pow(2, -1), ft_pow(2, -1));

	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 3);
}

/*
**************************** ft_atoi *****************************************
*/

void ft_atoi_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	cnt += ft_assert_int(1, atoi("   -54"), ft_atoi("   -54"));
	cnt += ft_assert_int(2, atoi("   -+54"), ft_atoi("   +-54"));
	cnt += ft_assert_int(3, atoi("   +-54"), ft_atoi("   -+54"));
	cnt += ft_assert_int(4, atoi("   -,54"), ft_atoi("   -,54"));
	cnt += ft_assert_int(5, atoi("   -2147483648"), ft_atoi("   -2147483648"));
	//cnt += ft_assert_int(6, atoi("   +2147483649"), ft_atoi("   +2147483649"));
	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 5);
}
/*
**************************** ft_align *****************************************
*/
void ft_align_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	cnt += ft_assert(32, ft_align(27, 31));
	cnt += ft_assert(0, ft_align(0, 31));
	cnt += ft_assert(32, ft_align(31, 31));
	cnt += ft_assert(32, ft_align(32, 31));
	cnt += ft_assert(64, ft_align(33, 31));
	cnt += ft_assert(0xFFF + 1, ft_align(0x463, 0xFFF));
	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 6);
}

/*
**************************** is_ascii ******************************************
*/

void ft_isascii_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, isascii(i), ft_isascii(i));


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}

/*
**************************** is_upper ****************************************
*/

void ft_isupper_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, isupper(i), ft_isupper(i));


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}

/*
**************************** is_lower ****************************************
*/

void ft_islower_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, islower(i), ft_islower(i));


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}


/*
**************************** is_print ****************************************
*/

void ft_isprint_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, isprint(i), ft_isprint(i));


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}

/*
**************************** strlen ********************************************
*/
void ft_strlen_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;
	char str[5][256] = {"hello", "", "123456789", "congratulation", "gsrgrgsrgrsgrsggsrgrgsrgrsgrsggsrgrgsrgrsgrsggsrgrgsrgrsgrsggsrgrgsrgrsgrsggsrgrgsrgrsgrsggsrgrgsrgrsgrsggsrgrgsrgrsgrsggsrgrgsrgrsgrsg"};
	char	*s = malloc(256 * sizeof(char));;

	for (int i = 0; i < 5; i++)
	{
		strcpy(s, str[i]);
		cnt += ft_assert_int(i, strlen(s), ft_strlen(s));
	}
	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 5);
	free(s);
}


/*
**************************** putstr ********************************************
*/

void ft_putstr_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 5;
	char str[5][64] = {"Hello", "world", "42", "rocks", "omg"};

	for (int i = 0; i < 5; i++)
	{
		ft_puts(str[i]);
	}
	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 5);
}


/*
**************************** ft_swap ****************************************
*/

void ft_swap_test(void) {
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;
	int g, h;
	g = 30;
	h = 50;
	ft_swap(&g ,&h);
	cnt += ft_assert_int(0, g, 50);
	cnt += ft_assert_int(1, h, 30);

	g = 50;
	h = 50;
	ft_swap(&g ,&h);
	cnt += ft_assert_int(0, g, 50);
	cnt += ft_assert_int(1, h, 50);

	g = 0;
	h = 50;
	ft_swap(&g ,&h);
	cnt += ft_assert_int(0, g, 50);
	cnt += ft_assert_int(1, h, 0);

	g = 0;
	h = 0;
	ft_swap(&g ,&h);
	cnt += ft_assert_int(0, g, 0);
	cnt += ft_assert_int(1, h, 0);
	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 8);
}


/*
**************************** toupper *******************************************
*/

void ft_toupper_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, toupper(i), ft_toupper(i));


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}

/*
**************************** tolower *******************************************
*/

void ft_tolower_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, tolower(i), ft_tolower(i));


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}

/*
**************************** ft_abs ********************************************
*/

void ft_abs_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	cnt += ft_assert_int(-2147483647, abs(-2147483647), ft_abs(-2147483647));
	cnt += ft_assert_int(-1, abs(-1), ft_abs(-1));


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 2);
}

/*
**************************** ft_rand *******************************************
*/

void ft_rand_test(void) {
		dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);

		int	rng[100];
		ft_bzero(rng, 100 * sizeof(int));
		for (int i = 0; i < 100; i++)
		{
			int b = ft_rand();
			rng[b] += 1;
		}
		for (int i = 0; i < 100; i++)
			dprintf(1, "\t[%d] %d x\n", i, rng[i]);
}

/*
**************************** memcpy ********************************************
*/

void ft_memcpy_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;
	const char	src[5][64] = {"hello world", "hello world1", "hello world2","hello",""};
	char		dst[64];

	for (int i = 0; i < 5; i++)
	{
		ft_memcpy(dst, src[i], 42);
		cnt += ft_assert_str(src[i], dst);
	}
	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 5);
}

/*
**************************** ft_bzero *****************************************
*/

void ft_bzero_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;
	char		src[5][64] = {"hello world", "hello world1", "hello world2","hello",""};

	for (int i = 0; i < 5; i++)
	{
		ft_bzero(src[i], 64);
		cnt += ft_assert_str(src[i], "");
	}
	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 5);
}

/*
**************************** ft_bzero *****************************************
*/

void ft_memset_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;
	char		src[5][64] = {"hello world", "hello world1", "hello world2","hello",""};
	char		src2[64] = "";

	for (int i = 0; i < 5; i++)
	{
		ft_memset(src[i], 'h' + i, 63);
		memset(src2, 'h' + i, 63);
		cnt += ft_assert_str(src[i], src2);
	}
	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 5);
}

/*
**************************** ft_strdup *****************************************
*/

void ft_strdup_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;
	char		src[5][64] = {"hello world", "hello world1", "hello world2","hello",""};
	char		*str2[2];

	for (int i = 0; i < 5; i++)
	{
		str2[0] = ft_strdup(src[i]);
		str2[1] = ft_strdup(src[i]);
		cnt += ft_assert_str(str2[0], str2[1]);
		free(str2[0]);
		free(str2[1]);
	}
	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 5);
}

static int	ft_collatz_c(int n)
{
	int count = 1;

	while (n > 1)
	{
		if (!(n % 2)) // if n is even
			n >>= 1;		// divide by 2
		else					// if n is odd
			n = 3 * n + 1; // multiply by 3 and add 1 to make it even
		++count;
	}
	return count;
}

/*
**************************** ft_collatz ****************************************
*/

void ft_collatz_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, ft_collatz_c(i), ft_collatz(i));


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}

/*
**************************** MAIN ******************************************
*/


int main(void)
{
//	g_Config.display = true;

// 1st mandatory part
	ft_bzero_test();
	ft_strcat_test();
	ft_isalpha_test();
	ft_isdigit_test();
	ft_isalnum_test();
	ft_isascii_test();
	ft_isprint_test();
	ft_toupper_test();
	ft_tolower_test();
	ft_putstr_test();

// optional functions
	ft_isupper_test();
	ft_islower_test();
	ft_swap_test();
	ft_strncmp_test();
	ft_atoi_test();
	ft_abs_test();
	ft_align_test();
	ft_pow_test();
	ft_collatz_test();

// 2nd mandatory part
	ft_strlen_test();
	ft_memset_test();
	ft_memcpy_test();
	ft_strdup_test();

// final mandatory function
	//ft_cat(0);

	dprintf(1, "\n");
	return (0);
}
