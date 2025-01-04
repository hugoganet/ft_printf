/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_hex_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:20:34 by hganet            #+#    #+#             */
/*   Updated: 2025/01/04 17:20:35 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

void	ft_putunbr_hex_fd(uintptr_t address, int fd)
{
	const char	*hex_chars = "0123456789abcdef";
	char		c;
	
	if (fd < 0)
		return ;
	if (address >= 16)
		ft_putunbr_hex_fd(address / 16, fd);
	c = hex_chars[address % 16];
	write(fd, &c, 1);
}