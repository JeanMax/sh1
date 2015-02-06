/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_and_sig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 21:32:33 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/06 19:57:00 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** execute commands and signal handling
** also managing the prompt loop
*/

#include "header.h"

pid_t			g_pid1;
pid_t			g_pid2;
t_env			*g_env;

void			fork_it(char **cmd, t_env *e)
{
	if ((g_pid2 = fork()) < 0)
		error("Fork", NULL);
	else if (!g_pid2)
		call_execve(cmd, e);
	else
		wait(NULL);
}

static void		sig_handl(int sig)
{
	if (sig == SIGBUS)
		error("bus", NULL);
	else if (sig == SIGSEGV)
		error("seg", NULL);
	else if (sig == SIGFPE)
		error ("fpe", NULL);
	else if (sig == SIGINT)
	{
		ft_putstr("\b \b\b \b\n");
		if (g_pid1 == g_pid2 || (!g_pid1 && !g_pid2))
			prompt(g_env);
		g_pid1 = g_pid2;
	}
	else if (sig == 29)
		prompt(g_env);
}

void			init(int ac, char **ae, t_env *e)
{
	ac > 1 ? error("arg", NULL) : 0;
	signal(SIGINT, sig_handl);
	signal(SIGFPE, sig_handl);
	signal(29, sig_handl);
	signal(SIGSEGV, sig_handl);
	signal(SIGBUS, sig_handl);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	e->env = ae;
	get_path(e);
	get_builtin(e);
	g_env = e;
	ft_putstr("\033[2J\033[1;1H");
}

void			launch_cmd(char **cmd, t_env *e)
{
	int	i;

	i = -1;
	if (!cmd[0])
		return ;
	while (cmd[++i])
		if (cmd[i][0] == '$')
			cmd[i] = get_env(cmd[i] + 1, e);
		else if (!ft_strcmp(cmd[i], "~"))
			cmd[i] = get_env("HOME", e);
	i = 0;
	while (cmd[i])
		if (ft_strchr(cmd[i], '>') || ft_strchr(cmd[i], '<')\
			|| ft_strchr(cmd[i++], '|'))
			return ;
	is_builtin(cmd, e) ? launch_builtin(cmd, e) : fork_it(cmd, e);
}

void			prompt_loop(char **av, t_env *e)
{
	char	*line;
	char	**cmd;

	while (42)
	{
		prompt(e);
		g_pid1 = g_pid2;
		get_line(0, &line) ? NULL : ft_exit(0, av);
		if (ft_strindex(line, ';') != -1)
		{
			semicolon(line, e);
			continue ;
		}
		cmd = split_it(line);
		launch_cmd(cmd, e);
		ft_memdel((void *)&line);
		cmd[0] ? ft_freetab(cmd) : NULL;
	}
}
