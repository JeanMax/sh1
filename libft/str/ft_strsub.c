/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:43:10 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/14 19:43:26 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	 Alloue (avec malloc(3)) et retourne la copie “fraiche” d’un tronçon de la
**   chaine de caractères passée en paramètre. Le tronçon commence à l’index
**   start et à pour longueur len. Si start et len ne désignent pas un tronçon
**   de chaine valide, le comportement est indéterminé. Si l’allocation échoue,
**   la fonction renvoie NULL.
*/

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s)
		return (NULL);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (start + len > ft_strlen(s))
		if (start <= ft_strlen(s))
			len = ft_strlen(s) - start;
	str = ft_strncpy(str, s + start, len);
	return (str);
}
