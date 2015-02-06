/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 00:12:49 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/06 22:43:59 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main...
*/

#include "header.h"

static void		inc_shlvl(t_env *e)
{
	char		*shlvl1;
	char		*shlvl2;
	char		**av;

	shlvl1 = get_env("SHLVL", e);
	shlvl2 = ft_itoa(ft_atoi(shlvl1) + 1);
	av = set_av("SHLVL", shlvl2, e, 0);
	launch_builtin(av, e);
	ft_memdel((void *)&shlvl1);
	ft_memdel((void *)&shlvl2);
	ft_freetab(av);
}

int				main(int ac, char **av, char **ae)
{
	t_env	e;

	init(ac, ae, &e);
	inc_shlvl(&e);
	prompt_loop(av, &e);
	return (0);
}
