/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 13:01:52 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/25 13:08:46 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Similaire à ft_strchr, mais retourne un int (index) indiquant la position du
** premier caractere recherché et trouvé dans la chaine.
** Retourne -1 en cas d'echec.
*/

#include "libft.h"

int		ft_strindex(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (!s[i])
			return (-1);
		i++;
	}
	return (i);
}
