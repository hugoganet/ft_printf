#include "libftprintf.h"

int main()
{
	/*
	// TESTINT %c Prints a single character.
	ft_printf();
	printf();
	// TESTING %s Prints a string(as defined by the common C convention).
	ft_printf();
	printf();
	// TESTING %p The void *pointer argument has to be printed in hexadecimal format.
	ft_printf();
	printf();
	// TESTING %d Prints a decimal(base 10) number.
	ft_printf();
	printf();
	// TESTING %i Prints an integer in base 10.
	ft_printf();
	printf();
	// TESTING %u Prints an unsigned decimal(base 10) number.
	ft_printf();
	printf();
	// TESTING %x Prints a number in hexadecimal(base 16) lowercase format.
	ft_printf();
	printf();
	// TESTING %X Prints a number in hexadecimal(base 16) uppercase format.
	ft_printf();
	printf();
	// TESTING %% Prints a percent sign.
	ft_printf();
	printf();
	*/
	printf(" Return value             : %i\n\n",
		   ft_printf(
			   "Print a single character  : %c\n"
			   "Print a string            : %s\n"
			   "Print an int              : %i\n"
			   "Print an int              : %d\n"
			   "Print an unsigned int     : %u\n"
			   "Print a hex in lowercase  : %x\n"
			   "Print a hex in uppercase  : %X\n"
			   "Print an address in hex   : %p\n",
			   'H',
			   "Hugo",
			   01234,
			   56789,
			   4294967295U,
			   123456789,
			   123456789,
			   NULL));
	printf(" Return value             : %i\n",
		   printf(
			   "Print a single character  : %c\n"
			   "Print a string            : %s\n"
			   "Print an int              : %i\n"
			   "Print an int              : %d\n"
			   "Print an unsigned int     : %u\n"
			   "Print a hex in lowercase  : %x\n"
			   "Print a hex in uppercase  : %X\n"
			   "Print an address in hex   : %p\n",
			   'H',
			   "Hugo",
			   01234,
			   56789,
			   4294967295U,
			   123456789,
			   123456789,
			   NULL));
	return (0);
}