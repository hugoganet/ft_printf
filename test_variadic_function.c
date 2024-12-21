#include <stdarg.h>
#include <stdio.h>

int	sum(int count, ...)
{
	int	i = 0;
	int	nb_char = 0;
	va_list args;

	va_start(args, count);
	while (i < count)
	{
		nb_char += va_arg(args, int);
		i++;
	}
	va_end(args);
	return nb_char;
}

int	main(int ac, char **av)
{

	if (ac > 0)
	{
		printf("%i\n", sum(4, 10, 20, 30, 40));
	}
	return (0);
}
