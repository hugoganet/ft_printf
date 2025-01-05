/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 17:01:48 by hganet            #+#    #+#             */
/*   Updated: 2025/01/05 13:32:35 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Outputs the unsigned number to the given file descriptor.
 * @param n The unsigned number to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putunbr_fd(unsigned int n, int fd)
{
	char	c;

	if (fd < 0)
		return ;
	if (n > 9)
		ft_putunbr_fd(n / 10, fd);
	c = n % 10 + '0';
	write(fd, &c, 1);	
}
