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
	int tmp;
	int check;
	int r; // random number
	char c;
	srand(time(NULL));
/*
**************************** is_ascii ******************************************
*/

dprintf(1, "\n\x1b[32mft_isascii:\x1b[0m\n");
tmp = -1;
while (++tmp < 255)
{
	dprintf(1, "\t%c -> %d", tmp, check = ft_isascii(tmp));
	if ((check && (-1 < tmp && tmp < 128)) || (!check && (0 > tmp || tmp > 127)))
		dprintf(1, "\t\x1b[32mOK\x1b[0m\n");
	else
		dprintf(1, "\t\x1b[31mKO\x1b[0m\n");
}


/*
**************************** is_islower ****************************************
*/

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

/*
**************************** is_alpha ******************************************
*/

	dprintf(1, "\n\x1b[32mft_isalpha:\x1b[0m\n");
	dprintf(1, "\t%c -> %d\n", '!', ft_isalpha('!'));
	dprintf(1, "\t%c -> %d\n", '@', ft_isalpha('@'));
	dprintf(1, "\t%c -> %d\n", 'A', ft_isalpha('A'));
	dprintf(1, "\t%c -> %d\n", 'F', ft_isalpha('F'));
	dprintf(1, "\t%c -> %d\n", 'K', ft_isalpha('K'));
	dprintf(1, "\t%c -> %d\n", 'T', ft_isalpha('T'));
	dprintf(1, "\t%c -> %d\n", 'Z', ft_isalpha('Z'));
	dprintf(1, "\t%c -> %d\n", '[', ft_isalpha('['));
	dprintf(1, "\t%c -> %d\n", '`', ft_isalpha('`'));
	dprintf(1, "\t%c -> %d\n", 'a', ft_isalpha('a'));
	dprintf(1, "\t%c -> %d\n", 'f', ft_isalpha('f'));
	dprintf(1, "\t%c -> %d\n", 'k', ft_isalpha('k'));
	dprintf(1, "\t%c -> %d\n", 't', ft_isalpha('t'));
	dprintf(1, "\t%c -> %d\n", 'z', ft_isalpha('z'));
	dprintf(1, "\t%c -> %d\n", '{', ft_isalpha('{'));
	dprintf(1, "\t%c -> %d\n", '~', ft_isalpha('~'));

/*
**************************** strlen ********************************************
*/
	dprintf(1, "\n\x1b[32mft_strlen:\x1b[0m\n");
	dprintf(1, "\t%s -> %d\n", "hello", ft_strlen("hello"));
	dprintf(1, "\t%s -> %d\n", "{empty}", ft_strlen(""));
	dprintf(1, "\t%s -> %d\n", "9 bytes", ft_strlen("123456789"));

/*
**************************** isdigit *******************************************
*/
	dprintf(1, "\n\x1b[32mft_isdigit:\x1b[0m\n");
	tmp = -1;
	while (++tmp < 127)
	{
		dprintf(1, "\t%c -> %d", tmp, check = ft_isdigit(tmp));
		if ((check && (47 < tmp && tmp < 58)) || (!check && (48 > tmp || tmp > 57)))
			dprintf(1, "\t\x1b[32mOK\x1b[0m\n");
		else
			dprintf(1, "\t\x1b[31mKO\x1b[0m\n");
	}

/*
**************************** isalnum *******************************************
*/
	dprintf(1, "\n\x1b[32mft_isalnum:\x1b[0m\n");
	tmp = 32 - 1;
	while (++tmp < 127)
	{
		dprintf(1, "\t%c -> %d", tmp, check = ft_isalnum(tmp));
		if (!check || (check && (ft_isalpha(tmp) || ft_isdigit(tmp))))
			dprintf(1, "\t\x1b[32mOK\x1b[0m\n");
		else
			dprintf(1, "\t\x1b[31mKO\x1b[0m\n");
	}

/*
**************************** isprint *******************************************
*/
	dprintf(1, "\n\x1b[32mft_isprint:\x1b[0m\n");
	tmp = -1;
	while (++tmp < 128)
	{
		dprintf(1, "\t%c -> %d", tmp, check = ft_isprint(tmp));
		if ((check && (31 < tmp && tmp < 127)) || (!check && (32 > tmp || tmp > 126)))
			dprintf(1, "\t\x1b[32mOK\x1b[0m\n");
		else
			dprintf(1, "\t\x1b[31mKO\x1b[0m\n");
	}

/*
**************************** isalnum *******************************************
*/
	dprintf(1, "\n\x1b[32mft_isprint:\x1b[0m\n");
	tmp = 10;
	while (tmp--)
	{
		r = rand() % 128;
		dprintf(1, "\t%c -> %d", r, check = ft_isprint(r));
		if ((check && (31 < r && r < 127)) || (!check && (32 > r || r > 126)))
			dprintf(1, "\t\x1b[32mOK\x1b[0m\n");
		else
			dprintf(1, "\t\x1b[31mKO\x1b[0m\n");
	}

/*
**************************** putstr ********************************************
*/
	dprintf(1, "\n\x1b[32mft_isprint:\x1b[0m\n");
	tmp = 5;
	const char *mystring[] = {"Hello", "world", "42", "rocks", "omg"};
	while (tmp--)
	{
		ft_puts((char *)mystring[rand() % 5]);
	}

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
**************************** tolower *******************************************
*/
dprintf(1, "\n\x1b[32mft_tolower:\x1b[0m\n");
	c = ft_tolower('B');

	dprintf(1, "\t'%c' <- ft_tolower(\"B\")", c);
	if (c == 'B' + 32)
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
**************************** ft_strcat *****************************************
*/
dprintf(1, "\n\x1b[32mft_strcat:\x1b[0m\n");
	char	mycat[64] = "a";

	ft_strcat(mycat, " hello");
	dprintf(1, "\t%s -> a hello\n", mycat);

	ft_strcat(mycat, "!");
	dprintf(1, "\t%s -> a hello!\n", mycat);

	ft_strcat(mycat, "");
	dprintf(1, "\t%s -> a hello!\n", mycat);

	ft_strcat(mycat, " world..");
	dprintf(1, "\t%s -> a hello! world.\n", mycat);

/*
**************************** ft_strcat *****************************************
*/
dprintf(1, "\n\x1b[32mft_pow:\x1b[0m\n");

	t = pow(2, 3);
	dprintf(1, "\t%d -> %d\n", ft_pow(2, 3), t);
	t = pow(2, 0);
	dprintf(1, "\t%d -> %d\n", ft_pow(2, 0), t);
	t = pow(2, -1);
	dprintf(1, "\t%d -> %d\n", ft_pow(2, -1), t);


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
**************************** toupper *******************************************
*/

dprintf(1, "\n\x1b[32mft_toupper:\x1b[0m\n");

tmp = 31;
while (++tmp < 127)
{
	dprintf(1, "\t%c -> %c", tmp, check = ft_toupper(tmp));
	if ((!ft_isalpha(tmp) && (check == tmp)) || (ft_isalpha(tmp) && ft_isupper(check)))
		dprintf(1, "\t\x1b[32mOK\x1b[0m\n");
	else
		dprintf(1, "\t\x1b[31mKO\x1b[0m\n");
}

/*
**************************** is_isupper ****************************************
*/

	dprintf(1, "\n\x1b[32mft_isupper:\x1b[0m\n");

	tmp = 31;
	while (++tmp < 127)
	{
		dprintf(1, "\t%c -> %d", tmp, check = ft_isupper(tmp));
		if ((check && (64 < tmp && tmp < 91)) || (!check && (65 > tmp || tmp > 90)))
			dprintf(1, "\t\x1b[32mOK\x1b[0m\n");
		else
			dprintf(1, "\t\x1b[31mKO\x1b[0m\n");
	}

/*
**************************** ft_swap ****************************************
*/

dprintf(1, "\n\x1b[32mft_swap:\x1b[0m\n");

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

/*
**************************** ft_collatz ****************************************
*/
	dprintf(1, "\tft_collatz %u\n", ft_collatz(16));

	return (0);
}
