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
	printf("return value = %i\n", ft_printf("%c\n%s\n%i\n%d\n%u\n", 'H', "Hugo", 01234, 56789, 4294967295U));
	printf("return value = %i\n", printf("%c\n%s\n%i\n%d\n%u\n", 'H', "Hugo", 01234, 56789, 4294967295U));
	return (0);
}