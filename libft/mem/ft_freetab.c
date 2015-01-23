/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 03:58:41 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/15 04:06:36 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** free a char * tab
*/

#include "libft.h"

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		ft_memdel((void *)&tab[i++]);
	ft_memdel((void *)&tab);
}
