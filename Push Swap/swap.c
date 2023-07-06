/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 22:55:07 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/01 21:21:11 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "push_swap.h"

void	swap_a(t_list **a, int bon_man)
{
	int	cur;

	cur = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = cur;
	if (bon_man == 1)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **b, int bon_man)
{
	int	cur;

	cur = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = cur;
	if (bon_man == 1)
		write(1, "sa\n", 3);
}

void	ss(t_list **a, t_list **b, int bon_man)
{
	int	cur;

	if (ft_lstsize(*a) > 1)
	{
		cur = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = cur;
	}
	if (ft_lstsize(*b) > 1)
	{
		cur = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = cur;
	}
	if (bon_man == 1)
		write(1, "ss\n", 3);
}

void	ft_lstclear_a_b(t_list **a, t_list **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
}

void	ft_lstclear_double(char **lstNbr)
{
	int	i;

	i = 0;
	while (lstNbr[i])
		free(lstNbr[i++]);
	free(lstNbr);
}
