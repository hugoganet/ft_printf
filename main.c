#include "libftprintf.h"

int main()
{
	int ret_ft;
	int ret_ori;

	// Comprehensive test with all formats
	printf(" Return value comparison:\n");
	ret_ft = ft_printf(
		"ft_printf:\n"
		" %c %s %i %d %u %x %X %p %%\n",
		'H', "Hugo", 1234, -5678, 4294967295U, 0xabcdef, 0xABCDEF, NULL);
	ret_ori = printf(
		"   printf:\n"
		" %c %s %i %d %u %x %X %p %%\n",
		'H', "Hugo", 1234, -5678, 4294967295U, 0xabcdef, 0xABCDEF, NULL);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	// TESTING %c Prints a single character.
	ret_ft = ft_printf("ft_printf: %c\n", 'A');
	ret_ori = printf("   printf: %c\n", 'A');
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);
	
	ret_ft = ft_printf("ft_printf: %c\n", '\n');
	ret_ori = printf("   printf: %c\n", '\n');
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("ft_printf: %c\n", '0');
	ret_ori = printf("   printf: %c\n", '0');
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	// TESTING %s Prints a string (as defined by the common C convention).
	ret_ft = ft_printf("ft_printf: %s\n", "Hello, world!");
	ret_ori = printf("   printf: %s\n", "Hello, world!");
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("ft_printf: %s\n", "");
	ret_ori = printf("   printf: %s\n", "");
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("ft_printf: %s\n", (char *)NULL);
	ret_ori = printf("   printf: %s\n", (char *)NULL);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	// TESTING %p The void * pointer argument has to be printed in hexadecimal format.
	ret_ft = ft_printf("ft_printf: %p\n", (void *)0x1234abcd);
	ret_ori = printf("   printf: %p\n", (void *)0x1234abcd);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("ft_printf: %p\n", NULL);
	ret_ori = printf("   printf: %p\n", NULL);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	// TESTING %d Prints a decimal (base 10) number.
	ret_ft = ft_printf("ft_printf: %d\n", 42);
	ret_ori = printf("   printf: %d\n", 42);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("ft_printf: %d\n", -123456);
	ret_ori = printf("   printf: %d\n", -123456);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("ft_printf: %d\n", 0);
	ret_ori = printf("   printf: %d\n", 0);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	// TESTING %i Prints an integer in base 10.
	ret_ft = ft_printf("ft_printf: %i\n", 42);
	ret_ori = printf("   printf: %i\n", 42);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("ft_printf: %i\n", -42);
	ret_ori = printf("   printf: %i\n", -42);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	// TESTING %u Prints an unsigned decimal (base 10) number.
	ret_ft = ft_printf("ft_printf: %u\n", 4294967295U);
	ret_ori = printf("   printf: %u\n", 4294967295U);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("ft_printf: %u\n", 0);
	ret_ori = printf("   printf: %u\n", 0);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	// TESTING %x Prints a number in hexadecimal (base 16) lowercase format.
	ret_ft = ft_printf("ft_printf: %x\n", 0xabcdef);
	ret_ori = printf("   printf: %x\n", 0xabcdef);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("ft_printf: %x\n", 0);
	ret_ori = printf("   printf: %x\n", 0);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	// TESTING %X Prints a number in hexadecimal (base 16) uppercase format.
	ret_ft = ft_printf("ft_printf: %X\n", 0xABCDEF);
	ret_ori = printf("   printf: %X\n", 0xABCDEF);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("ft_printf: %X\n", 0);
	ret_ori = printf("   printf: %X\n", 0);
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);

	// TESTING %% Prints a percent sign.
	ret_ft = ft_printf("ft_printf: %%\n");
	ret_ori = printf("   printf: %%\n");
	printf("Return comparison: ft_printf = %d, printf = %d\n\n", ret_ft, ret_ori);
	
	return (0);
}
