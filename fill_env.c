/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 07:46:30 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/06 18:15:47 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** get $PATH from env (**ae);
** get builtin foncions list (cd, setenv, unsetenv, env, exit);
** save them in t_env variable (*e).
*/

#include "header.h"

char	**set_av(char *s1, char *s2, t_env *e, int go)
{
	char		**av;
	struct stat	s;

	av = malloc(sizeof(char *) * 4);
	av[0] = ft_strdup("setenv");
	av[1] = ft_strdup(s1);
	if (!ft_strcmp(s2, "PWD") || !ft_strcmp(s2, "OLDPWD") ||
		!ft_strcmp(s2, "HOME"))
	{
		if (!(s2 = get_env(s2, e)))
			return (NULL);
	}
	av[2] = ft_strdup(s2);
	av[3] = ft_strnew(1);
	av[3] = NULL;
	if (go)
		if (chdir(s2) < 0)
		{
			ft_putstr(stat(s2, &s) ? \
				"cd: no such file or directory: " : "cd: not a directory: ");
			ft_putendl(ft_strrindex(s2, '/') != (int)ft_strlen(s2) - 1 ?
						s2 + ft_strrindex(s2, '/') + 1 : s2);
		}
	return (av);
}

char	**cpy_env(char **ae, char *val)
{
	int		i;
	char	**new_env;

	i = 0;
	while (ae[i])
		i++;
	new_env = malloc((i + (val ? 2 : 1)) * sizeof(char *));
	i = 0;
	while (ae[i])
	{
		new_env[i] = ft_strdup(ae[i]);
		i++;
	}
	if (val)
		new_env[i] = ft_strdup(val);
	new_env[i + (val ? 1 : 0)] = ft_strnew(1);
	new_env[i + (val ? 1 : 0)] = NULL;
	return (new_env);
}

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

void	get_path(t_env *e)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((e->env)[i])
	{
		if ((e->env)[i][0] == 'P' && (e->env)[i][1] == 'A' &&\
			(e->env)[i][2] == 'T' && (e->env)[i][3] == 'H' &&\
			(e->env)[i][4] == '=')
			break ;
		i++;
	}
	if (!(e->env)[i])
		error("path", NULL);
	tmp = ft_strdup((e->env)[i]);
	e->path = ft_strsplit(tmp + 5, ':');
	ft_memdel((void *)&tmp);
}

void	get_builtin(t_env *e)
{
	e->builtin = malloc(7 * sizeof(char *));
	(e->builtin)[0] = ft_strdup("cd");
	(e->builtin)[1] = ft_strdup("setenv");
	(e->builtin)[2] = ft_strdup("unsetenv");
	(e->builtin)[3] = ft_strdup("env");
	(e->builtin)[4] = ft_strdup("exit");
	(e->builtin)[5] = ft_strdup("echo");
	(e->builtin)[6] = ft_strnew(1);
}
