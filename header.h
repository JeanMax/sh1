/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/23 21:32:03 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H
# define PROMPT { ft_putstr_clr("$MinniChelHein> ", "white"); }
# define PATH_SIZE 128

/*
** include
*/
# include "libft/inc/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <signal.h>

/*
** struct def
*/
typedef struct s_env	t_env;
struct	s_env
{
	t_lst	*first_l;
	char	**env;
	char	**path;
	char	**builtin;
};

/*
** prototypes
*/
void	error(char *type, char *msg);
void	call_execve(char *cmd, char **av, char **ae, t_env *e);
void	get_path(char **ae, t_env *e);
void	get_builtin(t_env *e);
char	*get_env(char *var, t_env *e);
void	launch_builtin(int b, char **av, char **ae, t_env *e);
void	prompt_loop(int ac, char **av, char **ae);
void	ft_exit(int ac, char **av);
void	ft_env(char **av, char **ae, t_env *e);
void	ft_cd(char **av, t_env *e);
void	ft_setenv(char **ac, char **ae, t_env *e);
void	ft_unsetenv(char **ac, char **ae, t_env *e);

#endif
