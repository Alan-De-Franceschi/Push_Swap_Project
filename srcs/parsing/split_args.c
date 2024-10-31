/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:15:33 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/17 18:15:35 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_nbr(char **args)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (args[i])
	{
		count += ft_count_word(args[i], ' ');
		i++;
	}
	return (count);
}

static int	ft_fill_tab(char ***tab, char ***temp_tab, int *j)
{
	int	k;

	k = 0;
	while ((*temp_tab)[k])
	{
		(*tab)[*j] = ft_strdup((*temp_tab)[k]);
		if (!(*tab)[*j])
			return (ft_free_strtab(*tab), ft_free_strtab(*temp_tab), 0);
		(*j)++;
		k++;
	}
	return (1);
}

char	**ft_split_args(char **args)
{
	int		i;
	int		j;
	int		size;
	char	**nbr_tab;
	char	**temp_tab;

	i = 1;
	j = 0;
	size = ft_count_nbr(args);
	nbr_tab = ft_calloc(size + 1, sizeof(char *));
	if (!nbr_tab)
		return (NULL);
	while (args[i])
	{
		temp_tab = ft_split(args[i], ' ');
		if (!temp_tab)
			return (ft_free_strtab(nbr_tab), NULL);
		if (!(ft_fill_tab(&nbr_tab, &temp_tab, &j)))
			return (NULL);
		i++;
		ft_free_strtab(temp_tab);
	}
	nbr_tab[size] = NULL;
	return (nbr_tab);
}
