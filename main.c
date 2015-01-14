/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 00:12:49 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/13 07:42:41 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main...
*/

#include "header.h"

int		get_line(int const fd, char **a) //libft?
{
	//DEBUG; //debug
    int     i;
	int		stop;
    char    buf[BUFF_SIZE];

    if (!a || fd < 0)
        return (0);
    *a = ft_strnew(1);
    while ((i = read(fd, buf, BUFF_SIZE)) > 0)
    {
        buf[i] = '\0';
        *a = (char *)ft_realloc((void *)*a, ft_strlen(*a), ft_strlen(*a) + i);
        ft_strcat(*a, buf);
		if ((stop = ft_strindex(*a, '\n')) != -1)
			break ;
    }
	*a = ft_realloc((void *)*a, ft_strlen(*a), stop);
    if (!*a || i < 0)
        return (0);
    return (1);
}

void	free_tab(char **tab) //libft?
{
	//DEBUG; //debug
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int		main(int ac, char **av, char **ae)
{
	//DEBUG; //debug
	char	*line;
	char	**cmd;
	t_env	e;
	int		i;

	if (ac > 1)
		error("arg", NULL);
	start_sig();
	get_path(&ae[0], &e);
	get_builtin(&e);
	e.env = ae;
	call_execve("clear", av, e.env, &e);
	while (42)
	{
		PROMPT;
		get_line(0, &line);
		cmd = ft_strsplit(line, ' ');
		i = 0;
		while (i != 6 && cmd[0])
			if (!ft_strcmp((e.builtin)[i++], cmd[0]))
				break;
		if (i != 6)
			launch_builtin(i, &cmd[0], e.env, &e);
		else if (cmd)
			call_execve(cmd[0], &cmd[0], e.env, &e);
		ft_memdel((void *)&line);
		free_tab(cmd);
	}
	return (0);
}
