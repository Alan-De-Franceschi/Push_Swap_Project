/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:22:02 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/22 18:22:04 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_short_sort(t_list **lst_a)
{
	int	first;
	int	second;
	int	third;

	if (ft_check_sorting(*lst_a))
		return ;
	if (ft_lstsize(*lst_a) == 2)
		return (ft_sa(lst_a, 'a'));
	first = (*lst_a)->data;
	second = (*lst_a)->next->data;
	third = (*lst_a)->next->next->data;
	if (first > second && second < third && third > first)
		return (ft_sa(lst_a, 'a'));
	if (first < second && second > third && third < first)
		return (ft_rra(lst_a, 'a'));
	if (first < second && second > third && third > first)
		return (ft_rra(lst_a, 'a'), ft_sa(lst_a, 'a'));
	if (first > second && second < third && third < first)
		return (ft_ra(lst_a, 'a'));
	if (first > second && second > third && third < first)
		return (ft_ra(lst_a, 'a'), ft_sa(lst_a, 'a'));
}

void	ft_fifty_shades_of_sort(t_list **lst_a, t_list **lst_b)
{
	int	n;

	if (ft_lstsize(*lst_a) <= 3)
		return (ft_short_sort(lst_a));
	ft_pb(lst_a, lst_b, 'b');
	ft_pb(lst_a, lst_b, 'b');
	while (ft_lstsize(*lst_a) > 3)
		ft_sort_to_b(lst_a, lst_b);
	ft_short_sort(lst_a);
	while (ft_lstsize(*lst_b) > 0)
		ft_sort_to_a(lst_a, lst_b);
	n = ft_intindex(*lst_a, ft_minint(*lst_a));
	if (n != 0)
	{
		if (n <= (ft_lstsize(*lst_a) - 1) - n)
		{
			while (n--)
				ft_ra(lst_a, 'a');
		}
		else
		{
			while (n++ < ft_lstsize(*lst_a))
				ft_rra(lst_a, 'a');
		}
	}
}
