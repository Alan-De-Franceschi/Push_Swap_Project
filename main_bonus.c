/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:46:59 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/29 16:47:02 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_check_inst(char *inst, int size)
{
	if (ft_strncmp(inst, "pa\n", size) != 0
		&& ft_strncmp(inst, "pb\n", size) != 0
		&& ft_strncmp(inst, "ra\n", size) != 0
		&& ft_strncmp(inst, "rb\n", size) != 0
		&& ft_strncmp(inst, "rr\n", size) != 0
		&& ft_strncmp(inst, "rra\n", size) != 0
		&& ft_strncmp(inst, "rrb\n", size) != 0
		&& ft_strncmp(inst, "rrr\n", size) != 0
		&& ft_strncmp(inst, "sa\n", size) != 0
		&& ft_strncmp(inst, "sb\n", size) != 0
		&& ft_strncmp(inst, "ss\n", size) != 0)
		return (0);
	return (1);
}

static void	ft_do_inst(t_list **lst_a, t_list **lst_b, char *inst)
{
	int	size;

	size = ft_strlen(inst);
	if (ft_strncmp(inst, "pa\n", size) == 0)
		ft_pa(lst_a, lst_b, 'n');
	if (ft_strncmp(inst, "pb\n", size) == 0)
		ft_pb(lst_a, lst_b, 'n');
	if (ft_strncmp(inst, "ra\n", size) == 0)
		ft_ra(lst_a, 'n');
	if (ft_strncmp(inst, "rb\n", size) == 0)
		ft_rb(lst_b, 'n');
	if (ft_strncmp(inst, "rr\n", size) == 0)
		ft_rr(lst_a, lst_b, 'n');
	if (ft_strncmp(inst, "rra\n", size) == 0)
		ft_rra(lst_a, 'n');
	if (ft_strncmp(inst, "rrb\n", size) == 0)
		ft_rrb(lst_b, 'n');
	if (ft_strncmp(inst, "rrr\n", size) == 0)
		ft_rrr(lst_a, lst_b, 'n');
	if (ft_strncmp(inst, "sa\n", size) == 0)
		ft_sa(lst_a, 'n');
	if (ft_strncmp(inst, "sb\n", size) == 0)
		ft_sb(lst_b, 'n');
	if (ft_strncmp(inst, "ss\n", size) == 0)
		ft_ss(lst_a, lst_b, 'n');
}

static int	ft_read_inst(t_list **lst_a, t_list **lst_b)
{
	char	*inst;

	while (1)
	{
		inst = ft_get_next_line(0);
		if (!inst || !ft_check_inst(inst, ft_strlen(inst)))
		{
			if (!ft_check_inst(inst, ft_strlen(inst)))
				return (free(inst), 0);
			free(inst);
			break ;
		}
		ft_do_inst(lst_a, lst_b, inst);
		free(inst);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;

	if (ac <= 1)
		return (0);
	lst_a = NULL;
	lst_b = NULL;
	lst_a = ft_makelist_a(av);
	if (!lst_a)
		return (1);
	if (!ft_read_inst(&lst_a, &lst_b))
	{
		ft_lstclear(&lst_a);
		ft_lstclear(&lst_b);
		write(2, "Error\n", 6);
		return (1);
	}
	if (ft_check_sorting(lst_a) && ft_lstsize(lst_b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	return (0);
}
