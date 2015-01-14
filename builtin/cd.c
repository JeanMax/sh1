/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 07:40:00 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/14 05:27:42 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** cd builtin
*/

#include "header.h"

static char	**set_av(char *s1, char *s2, t_env *e, int go)
{
	//DEBUG; //debug
	char	**av;
	char	*var;

	av = malloc(sizeof(char *) * 4);
	av[0] = ft_strdup("setenv");
	av[1] = ft_strdup(s1);
	if (!ft_strcmp(s2, "PWD") || !ft_strcmp(s2, "OLDPWD") || !ft_strcmp(s2, "HOME"))
	{
		if (!(var = get_env(s2, e)))
			return (NULL);
	}
	else
		var = s2;
	av[2] = ft_strdup(var);
	av[3] = ft_strnew(1);
	av[3] = NULL;
	if (go)
		if (chdir(var) < 0)
		{
			ft_putstr("cd: no such file or directory: ");
			ft_putendl(var); //todo : show compressed (zboub instead of /rgdrg/eg/zboub)
		}
	return (av);
}

static void	go_home(t_env *e)
{
	//DEBUG; //debug
	char	**av;

	if (!(av = set_av("OLDPWD", "PWD", e, 0)))
		return ;
	launch_builtin(2, av, e->env, e);
	free_tab(av);
	if (!ft_strcmp(get_env("PWD", e), get_env("HOME", e)))
		return ;
	if (!(av = set_av("PWD", "HOME", e, 1)))
		return ;
	free_tab(av);
}

static void go_previous(t_env *e)
{
	//DEBUG; //debug
	char	**av1;
	char	**av2;

	ft_putendl(get_env("OLDPWD", e)); //todo : show compressed (~/zboub)
	if (!ft_strcmp(get_env("PWD", e), get_env("OLDPWD", e)))
		return ;
	if (!(av1 = set_av("OLDPWD", "PWD", e, 0)))
		return ;
	if (!(av2 = set_av("PWD", "OLDPWD", e, 1)))
		return ;
	launch_builtin(2, av1, e->env, e);
	free_tab(av1);
	free_tab(av2);
}

static void go_to(char *path, t_env *e)
{
	//DEBUG; //debug
	char	**av;
	char	*pwd;
	char	*tmp;

	pwd = get_env("PWD", e);
	if (path[0] != '/' && path[0] != '~')
	{
		tmp = ft_strjoin(pwd, "/");
		path = ft_strjoin(tmp, path);
		ft_memdel((void *)&tmp);
	}
	if (!ft_strcmp(pwd, path))
		return ;
	if (!(av = set_av("OLDPWD", "PWD", e, 0)))
		return ;
	launch_builtin(2, av, e->env, e);
	free_tab(av);
	if (!(av = set_av("PWD", path, e, 1)))
		return ;
	free_tab(av);
	ft_memdel((void *)&path);
}

void	ft_cd(char **av, t_env *e)
{
	//DEBUG; //debug
	int		ac;
	char	buf[PATH_SIZE];
	char	*pwd;

	ac = 0;
	while (av[ac])
		ac++;
	if (ac > 2)
	{
		ft_putendl("cd: Too many arguments.");
		return ;
	}
	else if (ac == 1 || !ft_strcmp(av[1], "~"))
		go_home(e);
	else if (!ft_strcmp(av[1], "-"))
		go_previous(e);
	else
		go_to(av[1], e);
	pwd = ft_strdup(getcwd(buf, PATH_SIZE));
	if (!strncmp(pwd, "/Volumes/Data", 13))
		pwd += 13;
	if (!(av = set_av("PWD", pwd, e, 1)))
		return ;
	launch_builtin(2, av, e->env, e);
	free_tab(av);
}
