/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:56:57 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/17 14:57:00 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **lst_a, char c)
{
	t_list	*start;
	t_list	*end;

	if (ft_lstsize(*lst_a) <= 1)
		return ;
	start = *lst_a;
	end = ft_lstlast(*lst_a);
	while ((*lst_a)->next != end)
		*lst_a = (*lst_a)->next;
	(*lst_a)->next = NULL;
	end->next = start;
	*lst_a = end;
	if (c == 'a')
		ft_printf("rra\n");
}

void	ft_rrb(t_list **lst_b, char c)
{
	t_list	*start;
	t_list	*end;

	if (ft_lstsize(*lst_b) <= 1)
		return ;
	start = *lst_b;
	end = ft_lstlast(*lst_b);
	while ((*lst_b)->next != end)
		*lst_b = (*lst_b)->next;
	(*lst_b)->next = NULL;
	end->next = start;
	*lst_b = end;
	if (c == 'b')
		ft_printf("rrb\n");
}

void	ft_rrr(t_list **lst_a, t_list **lst_b, char c)
{
	ft_rra(&(*lst_a), 'r');
	ft_rrb(&(*lst_b), 'r');
	if (c == 'r')
		ft_printf("rrr\n");
}
