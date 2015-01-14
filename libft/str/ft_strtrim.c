/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:44:56 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/10 17:27:09 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**   Alloue (avec malloc(3)) et retourne une copie de la chaine passée en
**   paramètre sans les espaces blancs au debut et à la fin de cette chaine.
**   On considère comme espaces blancs les caractères ’ ’, ’\n’ et ’\t’.
**   Si s ne contient pas d’espaces blancs au début ou à la fin, la fonction
**   renvoie une copie de s. Si l’allocation echoue, la fonction renvoie NULL.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	len;
	char	*swap;

	if (!s)
		return (0);
	while (*s && (ft_isblank(*s) || *s == '\n'))
		s++;
	if (!*s)
		return (ft_strnew(1));
	len = ft_strlen(s) - 1;
	while (*s && (ft_isblank(s[len]) || s[len] == '\n'))
		len--;
	swap = ft_strnew(len);
	if (!swap)
		return (0);
	swap = ft_strncpy(swap, s, len + 1);
	swap[len + 1] = '\0';
	return (swap);
}
