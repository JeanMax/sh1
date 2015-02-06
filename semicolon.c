/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semicolon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 22:47:57 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/06 16:42:23 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** handle splitting commands around ";" semicolon
*/

#include "header.h"

void	semicolon(char *line, t_env *e)
{
	char	**sc_tab;
	char	**cmd;
	int		i;

	sc_tab = ft_strsplit(line, ';');
	i = 0;
	while (sc_tab[i])
	{
		cmd = split_it(sc_tab[i]);
		launch_cmd(cmd, e);
		ft_freetab(cmd);
		i++;
	}
	ft_freetab(sc_tab);
	ft_memdel((void *)&line);
}
