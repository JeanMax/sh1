/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 03:03:01 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/14 02:32:59 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** signals handling and execution trough execve
*/

#include "header.h"

pid_t	pid1;
pid_t	pid2;

static void	sig_handl(int sig)
{
	//DEBUG; //debug
	if (sig == SIGBUS)
		error("bus", NULL);
	else if (sig == SIGSEGV)
		error("seg", NULL);
	else if (sig == SIGINT)
	{
		ft_putchar('\n');
		if (pid1 == pid2 || !pid1) //bug if first command is interupted
			PROMPT;
		pid1 = pid2;
	}
	else if (sig == SIGINFO)
		PROMPT;
}

void		start_sig(void)
{
	//DEBUG; //debug
	signal(SIGINT, sig_handl); //ctrl-c - 2
	signal(SIGINFO, sig_handl); //ctrl-t - 29
	signal(SIGSEGV, sig_handl); //segfault - 11
	signal(SIGBUS, sig_handl); //buserror - 10
}


void    call_execve(char *cmd, char **av, char **ae, t_env *e)
{
	//DEBUG; //debug
	int		i;
	char	*join;
	char	*tmp;

	if (!(pid2 = fork()))
	{
		if ((execve(cmd, av, ae)) < 0)
		{
			if (cmd[0] == '.' && cmd[1] == '/')
				error("exe", cmd);
			i = 0;
			while ((e->path)[i])
			{
				tmp = ft_strjoin((e->path)[i++], "/");
				join = ft_strjoin(tmp, cmd);
				ft_memdel((void *)&tmp);
				if ((execve(join, av, ae)) >= 0)
					ft_memdel((void *)&join);
				if ((execve(join, av, ae)) >= 0)
					break;
				ft_memdel((void *)&join);
			}
			error("cmd", cmd);
		}
	}
	else
		wait(NULL);
}
