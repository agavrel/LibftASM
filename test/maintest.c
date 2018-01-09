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
**************************** is_isupper ****************************************
*/

	dprintf(1, "\n\x1b[32mft_isupper:\x1b[0m\n");
	dprintf(1, "\t%c -> %d\n", '!', ft_isupper('!'));
	dprintf(1, "\t%c -> %d\n", '@', ft_isupper('@'));
	dprintf(1, "\t%c -> %d\n", 'A', ft_isupper('A'));
	dprintf(1, "\t%c -> %d\n", 'F', ft_isupper('F'));
	dprintf(1, "\t%c -> %d\n", 'K', ft_isupper('K'));
	dprintf(1, "\t%c -> %d\n", 'T', ft_isupper('T'));
	dprintf(1, "\t%c -> %d\n", 'Z', ft_isupper('Z'));
	dprintf(1, "\t%c -> %d\n", '[', ft_isupper('['));
	dprintf(1, "\t%c -> %d\n", '`', ft_isupper('`'));
	dprintf(1, "\t%c -> %d\n", 'a', ft_isupper('a'));
	dprintf(1, "\t%c -> %d\n", 'f', ft_isupper('f'));
	dprintf(1, "\t%c -> %d\n", 'k', ft_isupper('k'));
	dprintf(1, "\t%c -> %d\n", 't', ft_isupper('t'));
	dprintf(1, "\t%c -> %d\n", 'z', ft_isupper('z'));
	dprintf(1, "\t%c -> %d\n", '{', ft_isupper('{'));
	dprintf(1, "\t%c -> %d\n", '~', ft_isupper('~'));

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
		if (check)// && (ft_isalpha(tmp) || ft_isdigit(tmp)))
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
**************************** toupper *******************************************
*/
dprintf(1, "\n\x1b[32mft_toupper:\x1b[0m\n");
	char c = ft_toupper('a');

	dprintf(1, "\t'%c' <- ft_toupper(\"a\")", c);
	if (c == 'a' - 32)
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
	int t;

	t = pow(2, 3);
	dprintf(1, "\t%d -> %d\n", ft_pow(2, 3), t);
	t = pow(2, 0);
	dprintf(1, "\t%d -> %d\n", ft_pow(2, 0), t);
	t = pow(2, -1);
	dprintf(1, "\t%d -> %d\n", ft_pow(2, -1), t);

	char k = 'd';
	dprintf(1, "\t%c -> %d\n", k, 0xffffff80 & 128);




/*
**************************** ft_strdup *****************************************
*/
dprintf(1, "\n\x1b[32mft_strdup:\x1b[0m\n");
//	char	*mydup;
//	mydup = ft_strdup("hello");
//	dprintf(1, "\t'%s' <- ft_strdup('hello')\n", mydup);

	return (0);
}
