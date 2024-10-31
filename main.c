/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:14:13 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/10 15:14:14 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (ac > 1)
	{
		lst_a = NULL;
		lst_b = NULL;
		lst_a = ft_makelist_a(av);
		if (!lst_a)
			return (1);
		if (ft_check_sorting(lst_a))
			return (ft_lstclear(&lst_a), 0);
		ft_fifty_shades_of_sort(&lst_a, &lst_b);
		ft_lstclear(&lst_a);
		ft_lstclear(&lst_b);
	}
	return (0);
}
