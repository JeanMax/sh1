/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_clr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/26 23:12:33 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/09 03:31:46 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Affiche l’entier n sur la sortie standard (coloré).
*/

#include "libft.h"

void	ft_putnbr_clr(int nbr, char *clr)
{
	ft_putstr_clr(ft_itoa(nbr), clr);
}
