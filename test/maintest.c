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

bool	ft_assert(const unsigned long a, const unsigned long b)
{
	if (a == b)
	{
		dprintf(1, OK" \t%lu -> %lu\n", a, b);
		return true;
	}
	dprintf(1, KO" \t%lu -> %lu\n", a, b);
	return false;
}

bool	ft_assert_int(const int i, const int a, const int b, const bool display)
{
	if (a == b)
	{
		if (display)
			dprintf(1, OK" \t[%d] %d -> %d\n", i, a, b);
		return true;
	}
	dprintf(1, KO" \t[%d] %d -> %d\n", i, a, b);
	return false;
}

bool	ft_assert_str(const char *a, const char *b)
{
	if (!strcmp(a, b))
	{
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
		cnt += ft_assert_int(i, isalpha(i), ft_isalpha(i), false);


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}


/*
**************************** isdigit *******************************************
*/
void ft_isdigit_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, isdigit(i), ft_isdigit(i), false);


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}

/*
**************************** isalnum *******************************************
*/

void ft_isalnum_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, isalnum(i), ft_isalnum(i), false);


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

	cnt += ft_assert_int(1, pow(2, 3), ft_pow(2, 3), false);
	cnt += ft_assert_int(2, pow(2, 0), ft_pow(2, 0), false);
	cnt += ft_assert_int(3, pow(2, -1), ft_pow(2, -1), false);

	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 3);
}

/*
**************************** ft_atoi *****************************************
*/

void ft_atoi_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	cnt += ft_assert_int(1, atoi("   -54"), ft_atoi("   -54"), false);
	cnt += ft_assert_int(2, atoi("   -+54"), ft_atoi("   +-54"), false);
	cnt += ft_assert_int(3, atoi("   +-54"), ft_atoi("   -+54"), false);
	cnt += ft_assert_int(4, atoi("   -,54"), ft_atoi("   -,54"), false);
	cnt += ft_assert_int(5, atoi("   -2147483648"), ft_atoi("   -2147483648"), false);
	cnt += ft_assert_int(6, atoi("   +2147483649"), ft_atoi("   +2147483649"), false);
	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 6);
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
		cnt += ft_assert_int(i, isascii(i), ft_isascii(i), false);


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}

/*
**************************** is_isupper ****************************************
*/

void ft_isupper_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, isupper(i), ft_isupper(i), false);


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}


/*
**************************** is_isupper ****************************************
*/

void ft_isprint_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, isprint(i), ft_isprint(i), false);


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}

/*
**************************** strlen ********************************************
*/
void ft_strlen_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;
	char str[4][64] = {"hello", "", "123456789", "congratulation"};
	char	*s = malloc(64 * sizeof(char));;

	for (int i = 0; i < 4; i++)
	{
		strcpy(s, str[i]);
		cnt += ft_assert_int(i, strlen(s), ft_strlen(s), false);
	}
	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 4);
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

		int g; int h;
		dprintf(1, "\tswap g = 50 and h = 30\n");
		g = 30;
		h = 50;
		ft_swap(&g ,&h);
		if (g == 50 && h == 30)
			dprintf(1, "\t\x1b[32mOK\x1b[0m\n");
		else
			dprintf(1, "\t\x1b[31mKO\x1b[0m\n");

		dprintf(1, "\tswap g = 50 and h = 50\n");
		g = 50;
		h = 50;
		ft_swap(&g ,&h);
		if (g == 50 && h == 50)
			dprintf(1, "\t\x1b[32mOK\x1b[0m\n");
		else
			dprintf(1, "\t\x1b[31mKO\x1b[0m\n");

		dprintf(1, "\tswap g = 0 and h = 50\n");
		g = 0;
		h = 50;
		ft_swap(&g ,&h);
		if (g == 50 && h == 0)
			dprintf(1, "\t\x1b[32mOK\x1b[0m\n");
		else
			dprintf(1, "\t\x1b[31mKO\x1b[0m\n");

		dprintf(1, "\tswap g = 0 and h = 0\n");
		g = 0;
		h = 0;
		ft_swap(&g ,&h);
		if (g == 0 && h == 0)
			dprintf(1, "\t\x1b[32mOK\x1b[0m\n");
		else
			dprintf(1, "\t\x1b[31mKO\x1b[0m\n");
}


/*
**************************** toupper *******************************************
*/

void ft_toupper_test(void)	{
	dprintf(1, BOLD CYN"\n~ %s ~\n"NC, __func__);
	int cnt = 0;

	for (int i = 0; i < 256; i++)
		cnt += ft_assert_int(i, toupper(i), ft_toupper(i), false);


	dprintf(1, BOLD MAG"\t\t%.1f%% Tests Passed\n"NC, 100 * (double)cnt / 256);
}

/*
**************************** MAIN ******************************************
*/

int main(void)
{
	int tmp;

	ft_isascii_test();
	ft_isprint_test();
	ft_isupper_test();
	ft_strlen_test();
	ft_swap_test();
	ft_putstr_test();
	ft_toupper_test();

/*
**************************** memcpy ********************************************
*/
	const char	src[64] = "hello world";
	char		dst[64];
	dprintf(1, "\n\x1b[32mft_memcpy:\x1b[0m\n");

//	memset(dst, 0, sizeof(dst));
//	dprintf(1, "\t'%s' <- buf\n", dst);
	ft_memcpy(dst, src, 42);
	dprintf(1, "\t'%s' <- ft_memcpy(NULL, buf, 42)", dst);
	if (!strcmp(dst, "hello world"))
		dprintf(1, "\t\x1b[32mOK\x1b[0m\n");
	else
		dprintf(1, "\t\x1b[31mKO\x1b[0m\n");



/*
**************************** ft_abs ********************************************
*/
dprintf(1, "\n\x1b[32mft_abs:\x1b[0m\n");
	int t = -2147483647;
	dprintf(1, "\t%d -> %d\n", t, ft_abs(t));





/*
**************************** ft_bzero *****************************************
*/

dprintf(1, "\n\x1b[32mTest for memset and bzero:\x1b[0m\n");
	char str[5] = "hello";
	dprintf(1, "\tstr -> %s\n", str);

dprintf(1, "\n\x1b[32mft_bzero:\x1b[0m\n");
	ft_bzero(str, 5);
	dprintf(1, "\tft_bzero(str, 5) -> %s\n", str);

dprintf(1, "\n\x1b[32mft_memset:\x1b[0m\n");
	ft_memset(str, 'h', 5);
	dprintf(1, "\tft_memset(str, 'h', 5) -> %s\n", str);


dprintf(1, "\n\x1b[32mft_strdup:\x1b[0m\n");
	char	*str2;
	str2 = ft_strdup(str);
	dprintf(1, "\t'%s' <- str2 = ft_strdup(str)\n", str2);



/*
**************************** ft_rand *******************************************
*/

	int	rng[100];
	ft_bzero(rng, 100);
	tmp = 0;
	while (tmp < 100)
	{
		int b = ft_rand();
		rng[b] += 1;
		++tmp;
	}
	tmp = -1;
	while (++tmp < 100)
	{
		dprintf(1, "\t[%d] %d x\n", tmp, rng[tmp]);
	}

//	dprintf(1, "\tft_rand() -> %d", ft_rand());



/*
**************************** ft_collatz ****************************************
*/
	dprintf(1, "\tft_collatz %u\n", ft_collatz(16));


	/*
	**************************** is_islower ****************************************


		dprintf(1, "\n\x1b[32mft_islower:\x1b[0m\n");
		dprintf(1, "\t%c -> %d\n", '!', ft_islower('!'));
		dprintf(1, "\t%c -> %d\n", '@', ft_islower('@'));
		dprintf(1, "\t%c -> %d\n", 'A', ft_islower('A'));
		dprintf(1, "\t%c -> %d\n", 'F', ft_islower('F'));
		dprintf(1, "\t%c -> %d\n", 'K', ft_islower('K'));
		dprintf(1, "\t%c -> %d\n", 'T', ft_islower('T'));
		dprintf(1, "\t%c -> %d\n", 'Z', ft_islower('Z'));
		dprintf(1, "\t%c -> %d\n", '[', ft_islower('['));
		dprintf(1, "\t%c -> %d\n", '`', ft_islower('`'));
		dprintf(1, "\t%c -> %d\n", 'a', ft_islower('a'));
		dprintf(1, "\t%c -> %d\n", 'f', ft_islower('f'));
		dprintf(1, "\t%c -> %d\n", 'k', ft_islower('k'));
		dprintf(1, "\t%c -> %d\n", 't', ft_islower('t'));
		dprintf(1, "\t%c -> %d\n", 'z', ft_islower('z'));
		dprintf(1, "\t%c -> %d\n", '{', ft_islower('{'));
		dprintf(1, "\t%c -> %d\n", '~', ft_islower('~'));


	**************************** tolower *******************************************

	dprintf(1, "\n\x1b[32mft_tolower:\x1b[0m\n");

	tmp = 31;
	while (++tmp < 127)
	{
		dprintf(1, "\t%c -> %c", tmp, check = ft_tolower(tmp));
		if (tolower(tmp) == check)
			dprintf(1, "\t\x1b[32mOK\x1b[0m\n");
		else
			dprintf(1, "\t\x1b[31mKO\x1b[0m\n");
	}
*/
ft_strncmp_test();

	ft_isalnum_test();
	ft_isdigit_test();
	ft_isalpha_test();
	ft_strcat_test();
	ft_atoi_test();
	ft_align_test();
	ft_pow_test();
	dprintf(1, "\n");
	return (0);
}
