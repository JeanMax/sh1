/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 17:02:18 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/06 18:12:11 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** print a pretty prompt
*/

#include "header.h"

void	prompt(t_env *e)
{
	char	*user;
	char	*pwd;
	char	*home;
	int		i;

	i = 0;
	user = get_env("USER", e);
	pwd = get_env("PWD", e);
	home = get_env("HOME", e);
	if (ft_strnstr(pwd, home, ft_strlen(home)))
	{
		i += ft_strlen(home) - 1;
		pwd[ft_strlen(home) - 1] = '~';
	}
	ft_putstr_clr(user, "green");
	ft_putstr_clr("@sh1", "yellow");
	ft_putchar_clr(':', "white");
	ft_putendl_clr(pwd + i, "red");
	ft_putstr_clr("> ", "red");
	ft_memdel((void *)&user);
	ft_memdel((void *)&pwd);
	ft_memdel((void *)&home);
}
