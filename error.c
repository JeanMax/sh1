/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 03:39:12 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/12 08:07:39 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** errors handling
*/

#include "header.h"

void	error(char *type, char *msg)
{
	//DEBUG; //debug
	if (type[0] == 'c')
	{
		ft_putstr("sh1: command not found: ");
		ft_putendl(msg);
	}
	else if (type[0] == 'e')
	{
		ft_putstr("sh1: no such file or directory: ");
		ft_putendl(msg);
	}
	else if (type[0] == 'b')
		ft_putendl("Bus error. Try Again...");
	else if (type[0] == 's')
		ft_putendl("Segmentation fault. Try Again...");
	else if (type[0] == 'a')
        ft_putendl("Too many arguments.");
	else if (type[0] == 'p')
        ft_putendl("$PATH missing from env.");
	if (type[0] == 'c' || type[0] == 'e')
		exit(1);
	else
		exit (-1);
}
