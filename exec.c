/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 16:22:42 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/28 19:14:41 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handle the execution of a command trough execv
*/

#include "header.h"

void	call_execve(char **cmd, t_env *e)
{
	int		i;
	char	*join;
	char	*tmp;

	if ((execve(cmd[0], cmd, e->env)) < 0)
	{
		(cmd[0][0] == '.' && cmd[0][1] == '/') ? error("exe", cmd[0]) : 0;
		i = 0;
		while ((e->path)[i])
		{
			tmp = ft_strjoin((e->path)[i++], "/");
			join = ft_strjoin(tmp, cmd[0]);
			ft_memdel((void *)&tmp);
			execve(join, cmd, e->env) >= 0 ? ft_memdel((void *)&join) : 0;
			if ((execve(join, cmd, e->env)) >= 0)
				break ;
			ft_memdel((void *)&join);
		}
		error("cmd", cmd[0]);
	}
}
