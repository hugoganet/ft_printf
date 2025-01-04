/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 14:37:16 by hganet            #+#    #+#             */
/*   Updated: 2025/01/04 14:56:21 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	char	c;

	if (fd < 0)
		return ;
	if (n > 9)
		ft_putnbr_unsigned_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);	
}