/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:45:37 by hganet            #+#    #+#             */
/*   Updated: 2025/01/05 18:02:30 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putstr_len_fd(char *str, int fd);
int ft_putnbr_len_fd(int n, int fd);
int ft_putunbr_len_fd(unsigned int n, int fd);
int ft_putnbr_base_len_fd(int n, char *base, int fd);
int handle_pointer_format(uintptr_t ptr, int fd);

	int count_args(const char *format)
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



void	process_arg(char format, va_list args, int *len)
{
	if (format == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		(*len)++;
	}
	if (format == '%')
	{
		ft_putchar_fd('%', 1);
		(*len)++;
	}
	if (format == 's')
		*len += ft_putstr_len_fd(va_arg(args, char *), 1);
	if (format == 'i' || format == 'd')
		*len += ft_putnbr_len_fd(va_arg(args, int), 1);
	if (format == 'u')
		*len += ft_putunbr_len_fd(va_arg(args, unsigned int), 1);
	if (format == 'p')
		*len += handle_pointer_format((uintptr_t)va_arg(args, void *), 1);
	if (format == 'x')
		*len += ft_putnbr_base_len_fd(va_arg(args, int), "0123456789abcdef", 1);
	if (format == 'X')
		*len += ft_putnbr_base_len_fd(va_arg(args, int), "0123456789ABCDEF", 1);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	count;
	int	len;

	count = count_args(format);
	if (count <= 0)
		return (0);
	va_list args;
	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] && (format[i + 1] == 'c'
			|| format[i + 1] == 's' || format[i + 1] == 'd'
			|| format[i + 1] == 'i' || format[i + 1] == 'p'
			|| format[i + 1] == 'u' || format[i + 1] == 'x'
			|| format[i + 1] == 'X' || format[i + 1] == '%'))
				process_arg(format[++i], args, &len);
		else
		{
			write(1, &format[i], 1);
			len++;
		}
		i++;
	}
	if (len < 0)
		return (-1);
	va_end(args);
	return (len);
}
