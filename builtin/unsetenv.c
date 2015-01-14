/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 07:41:27 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/13 08:06:27 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** unsetenv builtin
*/

#include "header.h"

void	del_env(char *to_del, char **ae, t_env *e)
{
	//DEBUG; //debug
	int	j;

	j = 0;
	while (ae[j] && ft_strncmp(ae[j], to_del, ft_strlen(to_del)))
        j++;
	while (ae[j + 1])
	{
		ae[j] = ft_strdup(ae[j + 1]);
		j++;
	}
	ae[j] = NULL;
	e->env = ae;
}

void    ft_unsetenv(char **av, char **ae, t_env *e)
{
	//DEBUG; //debug
	int	i;

	if (!av[1])
	{
		ft_putendl("unsetenv: Too few arguments.");
		return ;
	}
	i = 1;
	while (av[i])
		del_env(av[i++], ae, e);
}
