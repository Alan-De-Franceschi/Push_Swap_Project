/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:34:55 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/29 11:34:56 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculating costs in A to push to B */

static int	ft_near_start_a(t_list *lst_b, int n, int t)
{
	int	cost;

	cost = 0;
	if (t <= (ft_lstsize(lst_b) - 1) - t)
	{
		while (n && t)
		{
			cost += 1;
			n--;
			t--;
		}
		cost += n + t;
	}
	else
		cost += n + ft_lstsize(lst_b) - t;
	return (cost);
}

static int	ft_near_end_a(t_list *lst_a, t_list *lst_b, int n, int t)
{
	int	cost;

	cost = 0;
	if (t <= (ft_lstsize(lst_b) - 1) - t)
		cost += t + ft_lstsize(lst_a) - n;
	else
	{
		while (n < ft_lstsize(lst_a) && t < ft_lstsize(lst_b))
		{
			cost += 1;
			n++;
			t++;
		}
		cost += ft_lstsize(lst_a) - n + ft_lstsize(lst_b) - t;
	}
	return (cost);
}

int	ft_sort_cost_a(t_list *lst_a, t_list *lst_b, t_list *temp)
{
	int	cost;
	int	n;
	int	t;

	cost = 1;
	n = ft_intindex(lst_a, temp->data);
	t = ft_intindex(lst_b, ft_b_target(lst_b, temp->data));
	if (n <= (ft_lstsize(lst_a) - 1) - n)
		cost += ft_near_start_a(lst_b, n, t);
	else
		cost += ft_near_end_a(lst_a, lst_b, n, t);
	return (cost);
}
