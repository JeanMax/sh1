/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrindex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 13:03:59 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/25 13:30:25 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Similaire à ft_strrchr, mais retourne un int (index) indiquant la position du
** dernier caractere recherché et trouvé dans la chaine.
** Retourne -1 en cas d'echec.
*/

#include "libft.h"

int		ft_strrindex(const char *s, int c)
{
	int	ret;
	int	i;

	i = 0;
	ret = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			ret = i;
		i++;
	}
	if (s[i] == (char)c)
		ret = i;
	return (ret);
}
