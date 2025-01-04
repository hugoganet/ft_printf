/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:16:58 by hganet            #+#    #+#             */
/*   Updated: 2025/01/04 15:59:09 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_base(char *base)
{
	int	len;
	int	i;
	int	j;
	
	len = ft_strlen(base);
	if (len <= 1)
		return (0);
	if (ft_strchr(base, '-') || ft_strchr(base, '+'))
		return (0);
	i = 0;
	while (base[i])
	{
		if (!ft_isprint(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (len);
}

void	ft_putnbr_base_fd(int n, char *base, int fd)
{
	int		base_len;
	char	c;

	if (fd < 0)
		return ;
	base_len = check_base(base);
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
