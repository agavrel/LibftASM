#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libfts.h"

int main(void)
{
	int tmp;

/*
**************************** is_ascii ******************************************
*/

	dprintf(1, "\x1b[32mft_isdigit:\x1b[0m\n");
	tmp = '0' - 1;
	while (++tmp < 60)
		dprintf(1, "\t%c -> %d\n", tmp, ft_isdigit(tmp));

/*
**************************** is_ascii ******************************************
*/

	dprintf(1, "\n\x1b[32mft_isascii:\x1b[0m\n");
	dprintf(1, "\t%c -> %d\n", '!', ft_isascii('!'));
	dprintf(1, "\t%c -> %d\n", '@', ft_isascii('@'));
	dprintf(1, "\t%c -> %d\n", 'A', ft_isascii('A'));
	dprintf(1, "\t%c -> %d\n", 'F', ft_isascii('F'));
	dprintf(1, "\t%c -> %d\n", 'K', ft_isascii('K'));
	dprintf(1, "\t%c -> %d\n", 'T', ft_isascii('T'));
	dprintf(1, "\t%c -> %d\n", 'Z', ft_isascii('Z'));
	dprintf(1, "\t%c -> %d\n", '[', ft_isascii('['));
	dprintf(1, "\t%c -> %d\n", '`', ft_isascii('`'));
	dprintf(1, "\t%c -> %d\n", 145, ft_isascii(145));
	dprintf(1, "\t%c -> %d\n", 'f', ft_isascii('f'));
	dprintf(1, "\t%c -> %d\n", 'k', ft_isascii('k'));
	dprintf(1, "\t%c -> %d\n", 't', ft_isascii('t'));
	dprintf(1, "\t%c -> %d\n", 224, ft_isascii(224));
	dprintf(1, "\t%c -> %d\n", '{', ft_isascii('{'));
	dprintf(1, "\t%c -> %d\n", '~', ft_isascii('~'));

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
**************************** isalnum *******************************************
*/
	dprintf(1, "\n\x1b[32mft_isalnum:\x1b[0m\n");
	tmp = 32 - 1;
	while (++tmp < 127)
		dprintf(1, "\t%c -> %d\n", tmp, ft_isalnum(tmp));
/*
**************************** isalnum *******************************************
*/
	dprintf(1, "\n\x1b[32mft_isprint:\x1b[0m\n");
	tmp = 32 - 1 - 1;
	while (++tmp < 127 + 1)
		dprintf(1, "\t%c -> %d\n", tmp, ft_isprint(tmp));

	return (0);
}
