/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhoorntj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 18:45:35 by rhoorntj          #+#    #+#             */
/*   Updated: 2019/05/02 18:00:50 by rhoorntj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Alloue (avec malloc(3)) et retourne la copie “fraiche” d’un
tronçon de la chaîne de caractères passée en paramètre. Le
tronçon commence à l’index start et a pour longueur len. Si
start et len ne désignent pas un tronçon de chaîne valide,
le comportement est indéterminé. Si l’allocation échoue, la
fonction renvoie NULL. */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
