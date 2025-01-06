/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:16:58 by hganet            #+#    #+#             */
/*   Updated: 2025/01/06 11:33:30 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the number 'n' in the given base to the given file descriptor.
 * @param n The number to output.
 * @param base The base in which to output the number.
 * @param fd The file descriptor on which to write.
 */
void	ft_putnbr_base_fd(int n, char *base, int fd)
{
	int		base_len;
	char	c;

	if (fd < 0)
		return ;
	base_len = ft_check_base(base);
	if (!base_len)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		ft_putnbr_base_fd(-(n / base_len), base, fd);
		c = base[-(n % base_len)];
		write(fd, &c, 1);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= base_len)
		ft_putnbr_base_fd(n / base_len, base, fd);
	c = base[n % base_len];
	write(fd, &c, 1);
}
