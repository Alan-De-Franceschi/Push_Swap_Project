/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:21:31 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/17 14:21:33 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **lst_a, t_list **lst_b, char c)
{
	t_list	*temp;

	if (!(*lst_b))
		return ;
	temp = (*lst_b)->next;
	(*lst_b)->next = *lst_a;
	*lst_a = *lst_b;
	*lst_b = temp;
	if (c == 'a')
		ft_printf("pa\n");
}

void	ft_pb(t_list **lst_a, t_list **lst_b, char c)
{
	t_list	*temp;

	if (!(*lst_a))
		return ;
	temp = (*lst_a)->next;
	(*lst_a)->next = *lst_b;
	*lst_b = *lst_a;
	*lst_a = temp;
	if (c == 'b')
		ft_printf("pb\n");
}
