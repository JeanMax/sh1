/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_and_sig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 21:32:33 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/23 23:11:27 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** execute commands and signal handling
** also managing the prompt loop
*/

#include "header.h"

pid_t			g_pid1;
pid_t			g_pid2;

void			call_execve(char *cmd, char **av, char **ae, t_env *e)
{
	int		i;
	char	*join;
	char	*tmp;

	if (!(g_pid2 = fork()))
	{
		if ((execve(cmd, av, ae)) < 0)
		{
			(cmd[0] == '.' && cmd[1] == '/') ? error("exe", cmd) : NULL;
			i = 0;
			while ((e->path)[i])
			{
				tmp = ft_strjoin((e->path)[i++], "/");
				join = ft_strjoin(tmp, cmd);
				ft_memdel((void *)&tmp);
				((execve(join, av, ae)) >= 0) ? ft_memdel((void *)&join) : NULL;
				if ((execve(join, av, ae)) >= 0)
					break ;
				ft_memdel((void *)&join);
			}
			error("cmd", cmd);
		}
	}
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
		if (g_pid1 == g_pid2 || !g_pid1)
			PROMPT;
		g_pid1 = g_pid2;
	}
	else if (sig == 29)
		PROMPT;
}

static	void	init(char **av, char **ae, t_env *e)
{
	signal(SIGINT, sig_handl);
	signal(SIGFPE, sig_handl);
	signal(29, sig_handl);
	signal(SIGSEGV, sig_handl);
	signal(SIGBUS, sig_handl);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	get_path(&ae[0], e);
	get_builtin(e);
	e->env = ae;
	call_execve("clear", av, e->env, e);
}

void		prompt_loop(int ac, char **av, char **ae)
{
	char	*line;
	char	**cmd;
	t_env	e;
	int		i;

	ac > 1 ? error("arg", NULL) : 0;
	init(av, ae, &e);
	while (42)
	{
		PROMPT;
		g_pid1 = g_pid2;
		if (!get_line(0, &line))
			ft_exit(0, av);
		cmd = ft_strsplit(line, ' ');
		i = 0;
		while (i != 7 && cmd[0])
			if (!ft_strcmp((e.builtin)[i++], cmd[0]))
				break ;
		if (i != 7)
			launch_builtin(i, &cmd[0], e.env, &e);
		else if (cmd)
			call_execve(cmd[0], &cmd[0], e.env, &e);
		ft_memdel((void *)&line);
		ft_freetab(cmd);
	}
}
