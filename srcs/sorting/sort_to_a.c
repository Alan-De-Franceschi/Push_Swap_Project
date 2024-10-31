/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:36:19 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/25 13:36:21 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sort and Push to A */

static int	ft_mincost_b(t_list *lst_a, t_list *lst_b)
{
	int		min;
	int		n;
	t_list	*temp;

	temp = lst_b;
	min = ft_sort_cost_b(lst_a, lst_b, temp);
	n = temp->data;
	while (temp)
	{
		if (ft_sort_cost_b(lst_a, lst_b, temp) < min)
		{
			min = ft_sort_cost_b(lst_a, lst_b, temp);
			n = temp->data;
		}
		temp = temp->next;
	}
	return (n);
}

static void	ft_close_to_start_b(t_list **lst_a, t_list **lst_b, int n, int t)
{
	int	t_ind;

	t_ind = ft_intindex(*lst_a, t);
	if (t_ind <= (ft_lstsize(*lst_a) - 1) - t_ind)
	{
		while ((*lst_b)->data != n && (*lst_a)->data != t)
			ft_rr(lst_a, lst_b, 'r');
		while ((*lst_b)->data != n)
			ft_rb(lst_b, 'b');
		while ((*lst_a)->data != t)
			ft_ra(lst_a, 'a');
	}
	else
	{
		while ((*lst_b)->data != n)
			ft_rb(lst_b, 'b');
		while ((*lst_a)->data != t)
			ft_rra(lst_a, 'a');
	}
}

static void	ft_close_to_end_b(t_list **lst_a, t_list **lst_b, int n, int t)
{
	int	t_ind;

	t_ind = ft_intindex(*lst_a, t);
	if (t_ind <= (ft_lstsize(*lst_a) - 1) - t_ind)
	{
		while ((*lst_b)->data != n)
			ft_rrb(lst_b, 'b');
		while ((*lst_a)->data != t)
			ft_ra(lst_a, 'a');
	}
	else
	{
		while ((*lst_b)->data != n && (*lst_a)->data != t)
			ft_rrr(lst_a, lst_b, 'r');
		while ((*lst_b)->data != n)
			ft_rrb(lst_b, 'b');
		while ((*lst_a)->data != t)
			ft_rra(lst_a, 'a');
	}
}

void	ft_sort_to_a(t_list **lst_a, t_list **lst_b)
{
	int	n;
	int	t;
	int	ind_n;

	n = ft_mincost_b(*lst_a, *lst_b);
	t = ft_a_target(*lst_a, n);
	ind_n = ft_intindex(*lst_a, n);
	if (ind_n <= (ft_lstsize(*lst_b) - 1) - ind_n)
		ft_close_to_start_b(lst_a, lst_b, n, t);
	else
		ft_close_to_end_b(lst_a, lst_b, n, t);
	ft_pa(lst_a, lst_b, 'a');
}
