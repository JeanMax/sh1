/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 07:42:30 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/20 13:16:06 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** exit builtin
*/

#include "header.h"

void	ft_exit(int ac, char **av)
{
	while (av[ac])
		ac++;
	ac > 2 ? ft_putendl("exit: Expression Syntax.") : NULL;
	if (ac > 2)
		return ;
	else if (ac == 2)
	{
		ac = 0;
		while (av[1][ac] && ft_isdigit(av[1][ac]))
			ac++;
		if (av[1][ac] && ft_isdigit(av[1][0]))
			ft_putendl("exit: Badly formed number.");
		else if (av[1][ac])
			ft_putendl("exit: Expression Syntax.");
		else
		{
			ft_putendl("exit");
			exit(ft_atoi(av[1]));
		}
	}
	else if (ac == 1)
	{
		ft_putendl("exit");
		exit(0);
	}
}
