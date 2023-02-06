/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:34:37 by stemsama          #+#    #+#             */
/*   Updated: 2023/01/30 10:42:49 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_b(t_list **a, t_list **b, int bon_man)
{
	t_list	*cur;
	t_list	*r_b;

	cur = *b;
	r_b = ft_lstnew_ind(cur->content, -1);
	if (!r_b)
	{
		write(2, "Error\n", 6);
		ft_lstclear_a_b(a, b);
	}
	ft_lstadd_back(b, r_b);
	*b = cur->next;
	free(cur);
	if (bon_man == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, int bon_man)
{
	t_list	*cur;
	t_list	*r_b;

	cur = *b;
	r_b = ft_lstnew_ind(cur->content, -1);
	if (ft_lstsize(*b) > 1)
	{
		ft_lstadd_back(b, r_b);
		*b = cur->next;
	}
	cur = *a;
	r_b = ft_lstnew_ind(cur->content, -1);
	if (ft_lstsize(*a) > 1)
	{
		ft_lstadd_back(a, r_b);
		*a = cur->next;
	}
	if (bon_man == 1)
		write(1, "rr\n", 3);
}

void	rv_rotate_b(t_list **a, t_list **b, int bon_man)
{
	t_list	*cur;
	t_list	*rv_b;

	cur = *b;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	rv_b = cur->next;
	if (!rv_b)
	{
		write(2, "Error\n", 6);
		ft_lstclear_a_b(a, b);
	}
	ft_lstadd_front(b, rv_b);
	cur->next = NULL;
	if (bon_man == 1)
		write(1, "rrb\n", 4);
}

void	rv_rotate_a(t_list **a, t_list **b, int bon_man)
{
	t_list	*cur;
	t_list	*rv_a;

	cur = *a;
	while (cur->next->next != NULL)
	{
		cur = cur->next;
	}
	rv_a = cur->next;
	if (!rv_a)
	{
		write(2, "Error\n", 6);
		ft_lstclear_a_b(a, b);
	}
	ft_lstadd_front(a, rv_a);
	cur->next = NULL;
	if (bon_man == 1)
		write(1, "rra\n", 4);
}

void	rrr(t_list **a, t_list **b, int bon_man)
{
	t_list	*cur;

	if (ft_lstsize(*a) > 1)
	{
		cur = *a;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		ft_lstadd_front(a, cur->next);
		cur->next = NULL;
	}
	if (ft_lstsize(*b) > 1)
	{
		cur = *b;
		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		ft_lstadd_front(b, cur->next);
		cur->next = NULL;
	}
	if (bon_man == 1)
		write(1, "rrr\n", 4);
}
