/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 07:40:00 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/28 17:30:32 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** cd builtin
*/

#include "header.h"

static char	**set_av(char *s1, char *s2, t_env *e, int go)
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

static void	go_home(t_env *e)
{
	char	**av;
	char	*home;
	char	*pwd;

	home = get_env("HOME", e);
	pwd = get_env("PWD", e);
	if (!(av = set_av("OLDPWD", pwd, e, 0)))
		return ;
	launch_builtin(av, e);
	ft_freetab(av);
	if (!ft_strcmp(pwd, home))
	{
		ft_memdel((void *)&home);
		ft_memdel((void *)&pwd);
		return ;
	}
	if (!(av = set_av("PWD", home, e, 1)))
		return ;
	ft_memdel((void *)&home);
	ft_memdel((void *)&pwd);
	ft_freetab(av);
}

static void go_previous(t_env *e)
{
	char	**av1;
	char	**av2;
	char	*oldpwd;
	char	*home;
	char	*to_free;

	oldpwd = get_env("OLDPWD", e);
	to_free = oldpwd;
	home = get_env("HOME", e);
	if (ft_strstr(oldpwd, home))
	{
		oldpwd += ft_strlen(home) - 1;
		oldpwd[0] = '~';
	}
	oldpwd += ft_strnstr(oldpwd, "/private/", 9) ? 8 : 0;
	ft_putendl(oldpwd);
	if (!(av1 = set_av("OLDPWD", "PWD", e, 0)))
		return ;
	if (!(av2 = set_av("PWD", "OLDPWD", e, 1)))
		return ;
	launch_builtin(av1, e);
	ft_memdel((void *)&home);
	ft_memdel((void *)&to_free);
	ft_freetab(av1);
	ft_freetab(av2);
}

static void	go_to(char *path, t_env *e)
{
	char	**av;
	char	*pwd;
	char	*tmp;
	char	free_it;

	free_it = '\0';
	pwd = get_env("PWD", e);
	if (path[0] != '/' && path[0] != '~')
	{
		tmp = ft_strjoin(pwd, "/");
		path = ft_strjoin(tmp, path);
		ft_memdel((void *)&tmp);
		free_it = 'f';
	}
	if (!(av = set_av("OLDPWD", pwd, e, 0)))
		return ;
	ft_memdel((void *)&pwd);
	launch_builtin(av, e);
	ft_freetab(av);
	if (!(av = set_av("PWD", path, e, 1)))
		return ;
	ft_freetab(av);
	if (free_it)
		ft_memdel((void *)&path);
}

void		ft_cd(char **av, t_env *e)
{
	int			ac;
	char		buf[PATH_SIZE];
	char		*pwd;

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
	if (!(av = set_av("PWD", ft_strncmp(pwd, "/Volumes/Data", 13) ?
						pwd : pwd + 13, e, 1)))
		return ;
	launch_builtin(av, e);
	ft_memdel((void *)&pwd);
	ft_freetab(av);
}
