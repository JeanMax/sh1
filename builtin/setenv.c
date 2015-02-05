/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 07:40:39 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/28 17:38:53 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** setenv builtin
*/

#include "header.h"

static int		var_exist(char **ae, char *var, char *val)
{
	int	j;

	j = 0;
	while (ae[j] && ft_strncmp(ae[j], var,
								(int)ft_strlen(var) > ft_strindex(ae[j], '=') ?
								(int)ft_strlen(var) : ft_strindex(ae[j], '=')))
		j++;
	if (ae[j])
	{
		ae[j] = ft_strdup(val);
		return (1);
	}
	return (0);
}

void			ft_setenv(char **av, t_env *e)
{
	char	*to_add;
	char	*tmp;
	int		ac;

	ac = 0;
	while (av[ac])
		ac++;
	ac == 1 ? ft_strcpy(av[0], "env") : NULL;
	ac == 1 ? launch_builtin(av, e) : NULL;
	ac > 3 ? ft_putendl("setenv: Too many arguments.") : NULL;
	if (ac == 1 || ac > 3)
		return ;
	if (ft_strindex(av[1], '=') != -1)
	{
		ft_putendl("setenv: Syntax Error.");
		return ;
	}
	tmp = ft_strjoin(av[1], "=");
	to_add = ft_strjoin(tmp, av[2]);
	if (!var_exist(e->env, av[1], to_add))
		e->env = cpy_env(e->env, to_add);
	ft_memdel((void *)&tmp);
	ft_memdel((void *)&to_add);
}
