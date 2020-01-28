/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 17:21:59 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/05/07 15:23:44 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strchr() function locates the first occurrence of c (converted to a 
char) in the string pointed to by s.  The terminating null character is 
consideredto be part of the string; therefore if c is `\0', the functions locate 
the terminating `\0'. The functions strchr() return a pointer 
to the located character, or NULL if the character does not appear in the 
string. */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}
