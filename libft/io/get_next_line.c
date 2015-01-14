/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 17:07:11 by mcanal            #+#    #+#             */
/*   Updated: 2014/11/28 19:58:15 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Retourne une ligne lue dans un descripteur de fichier.
** Le premier paramètre est le descripteur de fichier depuis lequel lire L
** second paramètre est l’adresse d’un pointeur sur caractère i servira
** stocker la ligne lue sur le descripteur de fichier. La valeur de retour peut
** être 1, 0 ou -1 selon qu’une ligne a été lue, que la lecture est term
** ou bien qu’une erreur est survenue respectivement.
*/

#include "libft.h"
#include <unistd.h>

int		is_there_line(char *left, char **line)
{
	char	*end;

	if (!left)
		return (0);
	if ((end = ft_strchr(left, '\n')))
	{
		*line = ft_strsub(left, 0, ft_strlen(left) - ft_strlen(end));
		return (1);
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static char		*left;

	if (fd < 0 || !line)
		return (-1);
	if (is_there_line(left, line))
	{
		left = ft_strchr(left, '\n') + 1;
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		left = ft_strjoin(left, buf);
		if (is_there_line(left, line))
		{
			left = ft_strchr(left, '\n') + 1;
			return (1);
		}
	}
	if (!left)
		left = ft_strnew(1);
	*line = ft_strdup(left);
	return (0);
}
