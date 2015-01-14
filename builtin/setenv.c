/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 07:40:39 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/14 03:45:19 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** setenv builtin
*/

#include "header.h"

static char     **cpy_env(char **ae, char *val)
{
	//DEBUG; //debug
    int     i;
    char    **new_env;

    i = 0;
    while (ae[i])
        i++;
    new_env = malloc((i + 2) * sizeof(char *));
    i = 0;
    while (ae[i])
    {
        new_env[i] = ft_strdup(ae[i]);
        i++;
    }
	new_env[i] = ft_strdup(val);
    new_env[i + 1] = ft_strnew(1);
    new_env[i + 1] = NULL;
    return (new_env);
}

static int		var_exist(char **ae, char *var, char *val)
{
	//DEBUG; //debug
	int	j;

	j = 0;
	while (ae[j] && ft_strncmp(ae[j], var, ft_strlen(var)))
		j++;
	if (ae[j])
	{
		ae[j] = ft_strdup(val);
		return (1);
	}
	return (0);
}

void			ft_setenv(char **av, char **ae, t_env *e)
{
	//DEBUG; //debug
	char	*to_add;
	char	*tmp;
	int ac;

    ac = 0;
    while (av[ac])
        ac++;
	if (ac == 1)
	{
		launch_builtin(4, av, ae, e);
		return ;
	}
	else if (ac > 3)
	{
		ft_putendl("setenv: Too many arguments.");
		return ;
	}
	tmp = ft_strjoin(av[1], "=");
	to_add = ft_strjoin(tmp, av[2]);
	if (!var_exist(ae, av[1], to_add))
		e->env = cpy_env(ae, to_add);
	ft_memdel((void *)&tmp);
	ft_memdel((void *)&to_add);
}
