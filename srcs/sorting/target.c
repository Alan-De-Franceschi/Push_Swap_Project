/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:57:37 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/28 21:57:41 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

/* Search B number target in A */

int	ft_a_target(t_list *lst, int n)
{
	int	t;
	int	rest;

	t = 0;
	rest = INT_MAX;
	if (n > ft_maxint(lst))
		return (ft_minint(lst));
	while (lst)
	{
		if (lst->data - n > 0 && lst->data - n < rest)
		{
			rest = lst->data - n;
			t = lst->data;
		}
		lst = lst->next;
	}
	return (t);
}

/* Search A number target in B */

int	ft_b_target(t_list *lst, int n)
{
	int	t;
	int	rest;

	t = 0;
	rest = INT_MAX;
	if (n > ft_maxint(lst) || n < ft_minint(lst))
		return (ft_maxint(lst));
	while (lst)
	{
		if (lst->data - n < 0 && ft_abs(lst->data - n) < rest)
		{
			rest = ft_abs(lst->data - n);
			t = lst->data;
		}
		lst = lst->next;
	}
	return (t);
}
