/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:45:37 by hganet            #+#    #+#             */
/*   Updated: 2024/12/21 19:39:41 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int	count_args(char format, int *i)
{
	if (format == 'c'
		|| format == 's'
		|| format == 'd'
		|| format == 'i'
		|| format == 'p'
		|| format == 'u'
		|| format == 'x'
		|| format == 'X'
		|| format == '%')
	{
		(*i)++;
		return (1);
	}
	else
		return (0);
}
int	get_arg_type(char format)
{
	if (format == 'c')
		printf("char\n");
	else if (format == 's')
		printf("string\n");
	else if ((format == 'i' || format == 'd'))
		printf("int\n");
	else if (format == 'p')
		printf("adress\n");
	else if (format == 'u')
		printf("unsigned int\n");
	else if (format == 'x')
		printf("hexadecimal in lowercase\n");
	else if (format == 'X')
		printf("hexadecimal in uppercase\n");
	else if (format == '%')
		printf("percent sign\n");
	else
		return ;
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	count;

	i = 0;
	while (format[i])
		if (format[i] == '%')
			count += count_args(format[i + 1], &i);
		else
			printf("%c", format[i]);
		i++;
	if (count <= 0)
		return ;
	va_list args;
	va_start(args, format);
	i = 0;
	while (i < count)
		va_arg(args, get_arg_type(format[i + 1]));
	va_end(args);
	return (count);
}

int	main(int ac, char **av)
{
	if (ac > 0)
	{
		printf("count = %i\n", ft_printf("Coucou \n %c %s %i %d %p %u %x %X %%biloute\n"));
	}
	return (0);
}