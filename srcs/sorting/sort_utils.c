/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:55:26 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/24 15:55:28 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_sorting(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	ft_maxint(t_list *lst)
{
	int	max;

	max = lst->data;
	while (lst)
	{
		if (lst->data > max)
			max = lst->data;
		lst = lst->next;
	}
	return (max);
}

int	ft_minint(t_list *lst)
{
	int	min;

	min = lst->data;
	while (lst)
	{
		if (lst->data < min)
			min = lst->data;
		lst = lst->next;
	}
	return (min);
}

int	ft_intindex(t_list *lst, int n)
{
	int	i;

	i = 0;
	while (lst && n != lst->data)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
