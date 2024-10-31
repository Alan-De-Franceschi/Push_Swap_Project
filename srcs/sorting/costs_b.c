/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:01:41 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/29 11:01:43 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Calculating costs in B to push to A */

static int	ft_near_start_b(t_list *lst_a, int n, int t)
{
	int	cost;

	cost = 0;
	if (t <= (ft_lstsize(lst_a) - 1) - t)
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
		cost += n + ft_lstsize(lst_a) - t;
	return (cost);
}

static int	ft_near_end_b(t_list *lst_a, t_list *lst_b, int n, int t)
{
	int	cost;

	cost = 0;
	if (t <= (ft_lstsize(lst_a) - 1) - t)
		cost += t + ft_lstsize(lst_b) - n;
	else
	{
		while (n < ft_lstsize(lst_b) && t < ft_lstsize(lst_a))
		{
			cost += 1;
			n++;
			t++;
		}
		cost += ft_lstsize(lst_b) - n + ft_lstsize(lst_a) - t;
	}
	return (cost);
}

int	ft_sort_cost_b(t_list *lst_a, t_list *lst_b, t_list *temp)
{
	int	cost;
	int	n;
	int	t;

	cost = 1;
	n = ft_intindex(lst_b, temp->data);
	t = ft_intindex(lst_a, ft_a_target(lst_a, temp->data));
	if (n <= (ft_lstsize(lst_b) - 1) - n)
		cost += ft_near_start_b(lst_a, n, t);
	else
		cost += ft_near_end_b(lst_a, lst_b, n, t);
	return (cost);
}
