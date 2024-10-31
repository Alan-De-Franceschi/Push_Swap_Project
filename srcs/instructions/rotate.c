/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:23:12 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/17 14:23:13 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **lst_a, char c)
{
	t_list	*temp;

	if (ft_lstsize(*lst_a) <= 1)
		return ;
	temp = (*lst_a)->next;
	ft_lstlast(*lst_a)->next = *lst_a;
	(*lst_a)->next = NULL;
	*lst_a = temp;
	if (c == 'a')
		ft_printf("ra\n");
}

void	ft_rb(t_list **lst_b, char c)
{
	t_list	*temp;

	if (ft_lstsize(*lst_b) <= 1)
		return ;
	temp = (*lst_b)->next;
	ft_lstlast(*lst_b)->next = *lst_b;
	(*lst_b)->next = NULL;
	*lst_b = temp;
	if (c == 'b')
		ft_printf("rb\n");
}

void	ft_rr(t_list **lst_a, t_list **lst_b, char c)
{
	ft_ra(&(*lst_a), 'r');
	ft_rb(&(*lst_b), 'r');
	if (c == 'r')
		ft_printf("rr\n");
}
