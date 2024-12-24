#include "includes/libftprintf.h"

int main()
{
	ft_printf("%c\n%s\n%i\n%d\n%u\n", 'H', "Hugo", 01234, 56789, 4294967295U);
	printf("%c\n%s\n%i\n%d\n%u\n", 'H', "Hugo", 01234, 56789, 4294967295U);
	return (0);
}