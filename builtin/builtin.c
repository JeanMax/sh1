/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 08:00:25 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/06 19:55:33 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** launch the appropriatte builtin function
*/

#include "header.h"

int			is_builtin(char **cmd, t_env *e)
{
	int		i;

	i = 6;
	while (i && cmd[0] && ft_strcmp((e->builtin)[i - 1], cmd[0]))
		i--;
	return (i ? 1 : 0);
}

void		launch_builtin(char **av, t_env *e)
{
	if (!ft_strcmp(av[0], "exit"))
		ft_exit(0, av);
	else if (!ft_strcmp(av[0], "env"))
		ft_env(av, e);
	else if (!ft_strcmp(av[0], "unsetenv"))
		ft_unsetenv(av, e);
	else if (!ft_strcmp(av[0], "setenv"))
		ft_setenv(av, e);
	else if (!ft_strcmp(av[0], "cd"))
		ft_cd(av, e);
}
