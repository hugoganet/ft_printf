/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hganet <hganet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:30:33 by hganet            #+#    #+#             */
/*   Updated: 2024/12/03 11:12:36 by hganet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the first occurrence of c
 * 				(converted to a char) in the string s.
 * @param s The string to search.
 * @param c The character to search for.
 * @return A pointer to the located character,
 * 				 or NULL if the character does not appear in the string.
 */
char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		s_len;
	int		i;
	char	c_char;

	str = (char *)s;
	s_len = ft_strlen(s);
	c_char = c;
	i = 0;
	while (i <= s_len)
	{
		if (str[i] == c_char)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
