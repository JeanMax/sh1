/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 03:39:14 by mcanal            #+#    #+#             */
/*   Updated: 2015/01/13 04:33:22 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDIT_H

# define EDIT_H

/*
** lst2 struct
*/
typedef struct s_lst	t_lst;
struct	s_lst
{
	char	*env;
	t_lst	*next;
	t_lst	*prev;
};

/*
** lst2
*/
t_lst	*ft_lnew(char *env_var);
t_lst	*ft_lfind(t_lst **alst, char *data);
void	ft_lfree(t_lst **lst);

#endif
