/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:37:41 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:13:14 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Alloue (avec malloc(3)) et retourne une chaine de caractère “fraiche”
** terminée par un ’\0’. Chaque caractère de la chaine est initialisé à ’\0’.
** Si l’allocation echoue, la fonction renvoie NULL.
*/

#include "libft.h"

char	*ft_strnew(size_t size)
{
	return ((char*)ft_memalloc(size + 1));
}
