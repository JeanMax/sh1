/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 07:41:27 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/30 22:49:56 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** unsetenv builtin
*/

#include "header.h"

void	del_env(char *del, t_env *e)
{
	int	j;

	j = 0;
	while ((e->env)[j] && ft_strncmp((e->env)[j], del,
						(int)ft_strlen(del) > ft_strindex((e->env)[j], '=') ?
						(int)ft_strlen(del) : ft_strindex((e->env)[j], '=')))
		j++;
	while ((e->env)[j + 1])
	{
		(e->env)[j] = ft_strdup((e->env)[j + 1]);
		j++;
	}
	(e->env)[j] = NULL;
}

void	ft_unsetenv(char **av, t_env *e)
{
	int	i;

	if (!av[1])
	{
		ft_putendl("unsetenv: Too few arguments.");
		return ;
	}
	i = 1;
	while (av[i])
		del_env(av[i++], e);
}
