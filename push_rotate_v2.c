/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_rotate_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:35:37 by stemsama          #+#    #+#             */
/*   Updated: 2023/01/30 18:47:38 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a_v2(t_list **a, t_list **b)
{
	t_list	*cur;
	t_list	*r_a;

	cur = *a;
	r_a = ft_lstnew_ind(cur->content, cur->index);
	if (!r_a)
	{
		write(2, "Error\n", 6);
		ft_lstclear_a_b(a, b);
	}
	ft_lstadd_back(a, r_a);
	*a = cur->next;
	free(cur);
	write(1, "ra\n", 3);
}

void	rotate_b_v2(t_list **a, t_list **b)
{
	t_list	*cur;
	t_list	*r_b;

	cur = *b;
	r_b = ft_lstnew_ind(cur->content, cur->index);
	if (!r_b)
	{
		write(2, "Error\n", 6);
		ft_lstclear_a_b(a, b);
	}
	ft_lstadd_back(b, r_b);
	*b = cur->next;
	free(cur);
	write(1, "rb\n", 3);
}

void	push_a_v2(t_list **a, t_list **b)
{
	t_list	*cur;
	t_list	*new;

	if (ft_lstsize(*b) == 0)
		return ;
	cur = *b;
	new = ft_lstnew_ind(cur->content, cur->index);
	if (!new)
	{
		write(2, "Error\n", 6);
		ft_lstclear_a_b(a, b);
	}
	ft_lstadd_front(a, new);
	(*b) = (*b)->next;
	free(cur);
	write(1, "pa\n", 3);
}

void	push_b_v2(t_list **a, t_list **b)
{
	t_list	*cur;
	t_list	*new;

	if (ft_lstsize(*a) == 0)
		return ;
	cur = *a;
	new = ft_lstnew_ind(cur->content, cur->index);
	if (!new)
	{
		write(2, "Error\n", 6);
		ft_lstclear_a_b(a, b);
	}
	ft_lstadd_front(b, new);
	(*a) = (*a)->next;
	free(cur);
	write(1, "pb\n", 3);
}
