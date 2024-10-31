/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:36:59 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/17 13:37:02 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **lst_a, char c)
{
	t_list	*temp;

	if (ft_lstsize(*lst_a) <= 1)
		return ;
	temp = *lst_a;
	*lst_a = (*lst_a)->next;
	temp->next = temp->next->next;
	(*lst_a)->next = temp;
	if (c == 'a')
		ft_printf("sa\n");
}

void	ft_sb(t_list **lst_b, char c)
{
	t_list	*temp;

	if (ft_lstsize(*lst_b) <= 1)
		return ;
	temp = *lst_b;
	*lst_b = (*lst_b)->next;
	temp->next = temp->next->next;
	(*lst_b)->next = temp;
	if (c == 'b')
		ft_printf("sb\n");
}

void	ft_ss(t_list **lst_a, t_list **lst_b, char c)
{
	ft_sa(&(*lst_a), 's');
	ft_sb(&(*lst_b), 's');
	if (c == 's')
		ft_printf("ss\n");
}
