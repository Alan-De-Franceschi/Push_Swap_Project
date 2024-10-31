/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:36:57 by ade-fran          #+#    #+#             */
/*   Updated: 2023/12/27 17:37:01 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

void	ft_sa(t_list **lst_a, char c);
void	ft_sb(t_list **lst_b, char c);
void	ft_ss(t_list **lst_a, t_list **lst_b, char c);
void	ft_pa(t_list **lst_a, t_list **lst_b, char c);
void	ft_pb(t_list **lst_a, t_list **lst_b, char c);
void	ft_ra(t_list **lst_a, char c);
void	ft_rb(t_list **lst_b, char c);
void	ft_rr(t_list **lst_a, t_list **lst_b, char c);
void	ft_rra(t_list **lst_a, char c);
void	ft_rrb(t_list **lst_b, char c);
void	ft_rrr(t_list **lst_a, t_list **lst_b, char c);

char	**ft_split_args(char **args);
t_list	*ft_makelist_a(char **args_tab);

int		ft_check_sorting(t_list *lst);
void	ft_fifty_shades_of_sort(t_list **lst_a, t_list **lst_b);
int		ft_maxint(t_list *lst);
int		ft_minint(t_list *lst);
int		ft_intindex(t_list *lst, int n);
int		ft_a_target(t_list *lst, int n);
int		ft_b_target(t_list *lst, int n);
int		ft_sort_cost_b(t_list *lst_a, t_list *lst_b, t_list *temp);
int		ft_sort_cost_a(t_list *lst_a, t_list *lst_b, t_list *temp);
void	ft_sort_to_a(t_list **lst_a, t_list **lst_b);
void	ft_sort_to_b(t_list **lst_a, t_list **lst_b);

#endif
