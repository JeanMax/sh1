/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 08:00:25 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/14 04:04:48 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** launch the appropriatte builtin function
** b: cd = 1, setenv = 2, unsetenv = 3, env = 4, exit = 5;
*/

#include "header.h"

void	launch_builtin(int b, char **av, char **ae, t_env *e)
{
	//DEBUG; //debug
	if (b == 5)
		ft_exit();
	else if (b == 4)
		ft_env(av, ae, e);
	else if (b == 3)
		ft_unsetenv(av, ae, e);
	else if (b == 2)
		ft_setenv(av, ae, e);
	else if (b == 1)
		ft_cd(av, e);
}
