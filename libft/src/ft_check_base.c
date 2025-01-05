/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:52:04 by hganet            #+#    #+#             */
/*   Updated: 2025/01/05 15:53:25 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Check if the numerical base is valid
 * @return 0 if the base is invalid, the length of the base otherwise
 */
int ft_check_base(char *base)
{
	int len;
	int i;
	int j;

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