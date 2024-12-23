/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:45:37 by hganet            #+#    #+#             */
/*   Updated: 2024/12/23 15:48:50 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	count_args(const char *format)
{
	int	i;
	int	count;
	
	if (!format)
		return (0);
	count = 0;
	i = 0;
	while (format[i] && format[i + 1])
	{
		if (format[i] == '%'
			&& (format[i + 1] == 'c' || format[i + 1] == 's'
			|| format[i + 1] == 'd' || format[i + 1] == 'i'
			|| format[i + 1] == 'p' || format[i + 1] == 'u'
			|| format[i + 1] == 'x' || format[i + 1] == 'X'
			|| format[i + 1] == '%'))
			{
				count++;
				i++;
			}
		i++;
	}
	return (count);
}
void	get_arg_type(char format)
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
}

void	print_char(int arg)
{
	char	c;

	c = (char)arg;
	write(1, &c, 1);
}

void	process_arg(char format, va_list args)
{
	if (format == 'c')
		print_char(va_arg(args, int));
	// if (format == 's')
	// 	print_string(va_arg(args, char *));
	
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	count;

	count = count_args(format);
	if (count <= 0)
		return (0);
	va_list args;
	va_start(args, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] && (format[i + 1] == 'c'
			|| format[i + 1] == 's' || format[i + 1] == 'd'
			|| format[i + 1] == 'i' || format[i + 1] == 'p'
			|| format[i + 1] == 'u' || format[i + 1] == 'x'
			|| format[i + 1] == 'X' || format[i + 1] == '%'))
			{
				process_arg(format[i + 1], args);
				i++;
			}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

int	main()
{
		// printf("count = %i\n", ft_printf("%c", 'H'));
		ft_printf("Coucou %c", 'A');
		return (0);
}