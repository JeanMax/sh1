/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 16:33:03 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/09 21:19:29 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Applique la fonction f à chaque caractère de la chaine de caractères
** passée en paramètre. Chaque caractère est passé par adresse à la
** fonction f afin de pouvoir être modifié si nécéssaire.
*/

#include "libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	if (!s || !f)
		return ;
	while (*s)
		f(s++);
}
