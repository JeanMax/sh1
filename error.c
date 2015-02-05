/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 03:39:12 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/05 17:41:21 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** errors handling
** type: c = command not found, e = no such file, b = bus error, s = segfault,
**		 f = floating-point excepion, a = too many arg, p = $PATH not found
**		 e = execve error, c = cmd not found, o = open, F = fork fail,
**		 P = pipe fail
*/

#include "header.h"

void		error(char *type, char *msg)
{
	if (type[0] == 'c')
		fail("sh2: command not found: ");
	else if (type[0] == 'e')
		fail("sh2: no such file or directory: ");
	else if (type[0] == 'o')
		fail("sh2: can't make file: ");
	if (type[0] == 'c' || type[0] == 'e' || type[0] == 'o')
		failn(msg);
	else if (type[0] == 'b')
		failn("Bus error. Try Again...");
	else if (type[0] == 'P')
		failn("Pipe failed. Try Again...");
	else if (type[0] == 'F')
		failn("Fork failed. Try Again...");
	else if (type[0] == 's')
		failn("Segmentation fault. Try Again...");
	else if (type[0] == 'f')
		failn("Floating-point exception. Try Again...");
	else if (type[0] == 'a')
		failn("Too many arguments.");
	else if (type[0] == 'p')
		failn("$PATH missing from env.");
	exit((type[0] == 'c' || type[0] == 'e') ? 1 : -1);
}
