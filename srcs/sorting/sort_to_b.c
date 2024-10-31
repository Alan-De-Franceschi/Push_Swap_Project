/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:39:37 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/26 18:39:39 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Sort and Push to B*/

static int	ft_mincost_a(t_list *lst_a, t_list *lst_b)
{
	int		min;
	int		n;
	t_list	*temp;

	temp = lst_a;
	min = ft_sort_cost_a(lst_a, lst_b, temp);
	n = temp->data;
	while (temp)
	{
		if (ft_sort_cost_a(lst_a, lst_b, temp) < min)
		{
			min = ft_sort_cost_a(lst_a, lst_b, temp);
			n = temp->data;
		}
		temp = temp->next;
	}
	return (n);
}

static void	ft_close_to_start_a(t_list **lst_a, t_list **lst_b, int n, int t)
{
	int	t_ind;

	t_ind = ft_intindex(*lst_b, t);
	if (t_ind <= (ft_lstsize(*lst_b) - 1) - t_ind)
	{
		while ((*lst_a)->data != n && (*lst_b)->data != t)
			ft_rr(lst_a, lst_b, 'r');
		while ((*lst_a)->data != n)
			ft_ra(lst_a, 'a');
		while ((*lst_b)->data != t)
			ft_rb(lst_b, 'b');
	}
	else
	{
		while ((*lst_a)->data != n)
			ft_ra(lst_a, 'a');
		while ((*lst_b)->data != t)
			ft_rrb(lst_b, 'b');
	}
}

static void	ft_close_to_end_a(t_list **lst_a, t_list **lst_b, int n, int t)
{
	int	t_ind;

	t_ind = ft_intindex(*lst_b, t);
	if (t_ind <= (ft_lstsize(*lst_b) - 1) - t_ind)
	{
		while ((*lst_a)->data != n)
			ft_rra(lst_a, 'a');
		while ((*lst_b)->data != t)
			ft_rb(lst_b, 'b');
	}
	else
	{
		while ((*lst_a)->data != n && (*lst_b)->data != t)
			ft_rrr(lst_a, lst_b, 'r');
		while ((*lst_a)->data != n)
			ft_rra(lst_a, 'a');
		while ((*lst_b)->data != t)
			ft_rrb(lst_b, 'b');
	}
}

void	ft_sort_to_b(t_list **lst_a, t_list **lst_b)
{
	int	n;
	int	t;
	int	ind_n;

	n = ft_mincost_a(*lst_a, *lst_b);
	t = ft_b_target(*lst_b, n);
	ind_n = ft_intindex(*lst_a, n);
	if (ind_n <= (ft_lstsize(*lst_a) - 1) - ind_n)
		ft_close_to_start_a(lst_a, lst_b, n, t);
	else
		ft_close_to_end_a(lst_a, lst_b, n, t);
	ft_pb(lst_a, lst_b, 'b');
}
