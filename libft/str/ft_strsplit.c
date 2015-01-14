/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 15:10:14 by mcanal            #+#    #+#             */
/*   Updated: 2014/12/14 19:33:25 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Alloue (avec malloc(3)) et retourne un tableau de chaines de caractères
** “fraiches” (toutes terminées par un ’\0’, le tableau également donc)
** résultant de la découpe de s selon le caractère c. Si l’allocation echoue,
** la fonction retourne NULL.
** Exemple : ft_strsplit("*salut*les***etudiants*", ’*’) renvoie le tableau
** ["salut", "les", "etudiants"].
*/

#include "libft.h"
#include <stdlib.h>

static size_t	ft_word_nb(char const *s, char c)
{
	size_t	word_nb;

	word_nb = ((*s == c) ? (0) : (1));
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
			word_nb++;
		s++;
	}
	return (word_nb);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	word_len;

	word_len = 0;
	while (*s != c && *s)
	{
		s++;
		word_len++;
	}
	return (word_len);
}

static void		ft_free_tab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(tab = malloc(ft_word_nb(s, c) * sizeof(char *) + 1)))
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!(tab[i] = ft_strsub(s, 0, ft_word_len(s, c))))
			{
				ft_free_tab(tab, i);
				return (NULL);
			}
			s += ft_word_len(s, c);
			i++;
		}
	}
	tab[i] = '\0';
	return (tab);
}
