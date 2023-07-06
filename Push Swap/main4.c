/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:33:18 by stemsama          #+#    #+#             */
/*   Updated: 2023/01/29 21:23:15 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_nbr_bit(t_list **a)
{
	t_list	*cur;
	int		nbr_bit;
	int		indice_max;

	cur = (*a);
	indice_max = ft_lstsize(cur) - 1;
	nbr_bit = 0;
	while (indice_max >> nbr_bit)
		nbr_bit++;
	return (nbr_bit);
}

void	sort_par_index(t_list **a)
{
	int		i;
	int		size;
	t_list	*min;
	t_list	*cmp;

	i = 0;
	size = ft_lstsize(*a);
	while (i < size)
	{
		min = (*a);
		while (min->index != -1)
			min = min->next;
		cmp = (*a)->next;
		while (cmp)
		{
			if ((min->content > cmp->content) && (cmp->index == -1))
			{
				min = cmp;
			}
			cmp = cmp->next;
		}
		min->index = i++;
	}
}

void	radix_part(t_list **a, t_list **b, int nbr_chft)
{
	int	size;
	int	i;

	size = ft_lstsize(*a);
	i = 0;
	while (i < size)
	{
		if (((*a)->index >> nbr_chft) & 1)
			rotate_a_v2(a, b);
		else
			push_b_v2(a, b);
		i++;
	}
}
