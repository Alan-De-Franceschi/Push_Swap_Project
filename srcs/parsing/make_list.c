/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_lists.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:48:18 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/19 16:48:20 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_clean_all(char **tab, t_list **lst)
{
	ft_lstclear(lst);
	ft_free_strtab(tab);
	write(2, "Error\n", 6);
	return (NULL);
}

static int	ft_make_new_node(char *str, t_list	**lst)
{
	t_list	*new_node;
	int		error;

	error = 0;
	new_node = ft_lstnew(ft_atoi(str, &error));
	if (error || !new_node)
		return (free(new_node), 0);
	ft_lstadd_back(lst, new_node);
	return (1);
}

static int	ft_check_doubles(t_list *lst, int n)
{
	t_list	*last_node;

	last_node = ft_lstlast(lst);
	while (lst != last_node)
	{
		if (lst->data == n)
			return (1);
		lst = lst->next;
	}
	return (0);
}

t_list	*ft_makelist_a(char **args_tab)
{
	t_list	*lst_a;
	char	**tab;
	int		i;

	lst_a = NULL;
	i = 0;
	tab = ft_split_args(args_tab);
	if (!tab)
		return (write(2, "Error\n", 6), NULL);
	while (tab[i])
	{
		if (!ft_make_new_node(tab[i++], &lst_a))
			return (ft_clean_all(tab, &lst_a));
		if (ft_check_doubles(lst_a, ft_lstlast(lst_a)->data))
			return (ft_clean_all(tab, &lst_a));
	}
	return (ft_free_strtab(tab), lst_a);
}
