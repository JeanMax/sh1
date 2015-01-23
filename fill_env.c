/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 07:46:30 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/20 16:05:13 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** get $PATH from env (**ae);
** get builtin foncions list (cd, setenv, unsetenv, env, exit);
** save them in t_env variable (*e).
*/

#include "header.h"
#include <stdlib.h>

char	*get_env(char *var, t_env *e)
{
	char	**ae;
	int		i;
	int		len;
	char	*ret;

	ae = e->env;
	i = 0;
	len = ft_strlen(var);
	while (ae[i] && ft_strncmp(ae[i], var,
								(int)ft_strlen(var) > ft_strindex(ae[i], '=') ?
								(int)ft_strlen(var) : ft_strindex(ae[i], '=')))
		i++;
	if (!ae[i])
		return (ft_strnew(1));
	ret = ft_strdup(ae[i] + len + 1);
	return (ret);
}

void	get_path(char **ae, t_env *e)
{
	char	*tmp;
	int		i;

	i = 0;
	while (ae[i])
	{
		if (ae[i][0] == 'P' && ae[i][1] == 'A' && ae[i][2] == 'T' && \
				ae[i][3] == 'H' && ae[i][4] == '=')
			break ;
		i++;
	}
	if (!ae[i])
		error("path", NULL);
	tmp = ft_strdup(ae[i]);
	tmp += 5;
	e->path = ft_strsplit(tmp, ':');
	tmp -= 5;
	ft_memdel((void *)&tmp);
}

void	get_builtin(t_env *e)
{
	e->builtin = malloc(6 * sizeof(char *));
	(e->builtin)[0] = ft_strdup("cd");
	(e->builtin)[1] = ft_strdup("setenv");
	(e->builtin)[2] = ft_strdup("unsetenv");
	(e->builtin)[3] = ft_strdup("env");
	(e->builtin)[4] = ft_strdup("exit");
	(e->builtin)[5] = ft_strnew(1);
}
