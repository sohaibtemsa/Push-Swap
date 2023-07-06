/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:32:55 by stemsama          #+#    #+#             */
/*   Updated: 2023/01/31 20:02:35 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_2(t_list **a)
{
	if ((*a)->content > (*a)->next->content)
		swap_a(a, 1);
	else
		return ;
}

void	push_swap_3(t_list **a, t_list **b)
{
	if ((*a)->content < (*a)->next->content)
	{
		if ((*a)->next->content < (*a)->next->next->content)
			return ;
		else if ((*a)->content < (*a)->next->next->content)
		{
			swap_a(a, 1);
			rotate_a(a, b, 1);
		}
		else
			rv_rotate_a(a, b, 1);
	}
	if ((*a)->content > (*a)->next->content)
	{
		if ((*a)->next->content < (*a)->next->next->content
			&& (*a)->content > (*a)->next->next->content)
			rotate_a(a, b, 1);
		else if ((*a)->next->content > (*a)->next->next->content)
		{
			swap_a(a, 1);
			rv_rotate_a(a, b, 1);
		}
		else
			swap_a(a, 1);
	}
}

void	push_swap_4(t_list **a, t_list **b)
{
	put_min_first(a, b);
	if (check_lstnbr_sorted(a))
	{
		ft_lstclear(a);
		exit(0);
	}
	push_b(a, b, 1);
	push_swap_3(a, b);
	push_a(a, b, 1);
}

void	push_swap_5(t_list **a, t_list **b)
{
	put_min_first(a, b);
	if (check_lstnbr_sorted(a))
	{
		ft_lstclear(a);
		exit(0);
	}
	push_b(a, b, 1);
	put_min_first(a, b);
	if (check_lstnbr_sorted(a))
	{
		push_a(a, b, 1);
		ft_lstclear(a);
		exit(0);
	}
	push_b(a, b, 1);
	push_swap_3(a, b);
	push_a(a, b, 1);
	push_a(a, b, 1);
}

void	push_swap_500(t_list **a, t_list **b)
{
	int	nbr_of_bits;
	int	i;
	int	j;
	int	size;

	i = 0;
	sort_par_index(a);
	nbr_of_bits = max_nbr_bit(a);
	while (i < nbr_of_bits)
	{
		j = 0;
		radix_part(a, b, i);
		size = ft_lstsize(*b);
		while (j < size)
		{
			if ((((*b)->index >> (i + 1)) & 1) == 0 && i != nbr_of_bits - 1)
				rotate_b_v2(a, b);
			else
				push_a_v2(a, b);
			j++;
		}
		i++;
	}
}
