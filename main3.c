/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 21:10:02 by stemsama          #+#    #+#             */
/*   Updated: 2023/01/30 10:49:35 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *a)
{
	int	min;

	min = a->content;
	a = a->next;
	while (a)
	{
		if (min > a->content)
			min = a->content;
		a = a->next;
	}
	return (min);
}

void	ra_while(t_list **a, t_list **b, int nbr_ra)
{
	while (nbr_ra--)
		rotate_a(a, b, 1);
}

void	rra_while(t_list **a, t_list **b, int nbr_ra)
{
	while (nbr_ra--)
		rv_rotate_a(a, b, 1);
}

void	put_min_first(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		cmp;
	int		i;
	int		size;

	tmp = *a;
	i = 0;
	cmp = get_min(*a);
	size = ft_lstsize(*a);
	while (tmp)
	{
		if (cmp == tmp->content)
			break ;
		i++;
		tmp = tmp->next;
	}
	if (i == 0)
		return ;
	if ((size / 2) >= i)
		ra_while(a, b, i);
	else
		rra_while(a, b, size - i);
}
