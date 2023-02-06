/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:57:26 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/05 18:34:54 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	push_b(t_list **a, t_list **b, int bon_man)
{
	t_list	*cur;
	t_list	*new;

	if (ft_lstsize(*a) == 0)
		return ;
	cur = *a;
	new = ft_lstnew_ind(cur->content, -1);
	if (!new)
	{
		write(2, "Error\n", 6);
		ft_lstclear_a_b(a, b);
	}
	ft_lstadd_front(b, new);
	(*a) = (*a)->next;
	free(cur);
	if (bon_man == 1)
		write(1, "pb\n", 3);
}

void	push_a(t_list **a, t_list **b, int bon_man)
{
	t_list	*cur;
	t_list	*new;

	if (ft_lstsize(*b) == 0)
		return ;
	cur = *b;
	new = ft_lstnew_ind(cur->content, -1);
	if (!new)
	{
		write(2, "Error\n", 6);
		ft_lstclear_a_b(a, b);
	}
	ft_lstadd_front(a, new);
	(*b) = (*b)->next;
	free(cur);
	if (bon_man == 1)
		write(1, "pa\n", 3);
}

void	rotate_a(t_list **a, t_list **b, int bon_man)
{
	t_list	*cur;
	t_list	*r_a;

	cur = *a;
	if (ft_lstsize(*a) > 1)
	{
		r_a = ft_lstnew_ind(cur->content, -1);
		if (!r_a)
		{
			write(2, "Error\n", 6);
			ft_lstclear_a_b(a, b);
		}
		ft_lstadd_back(a, r_a);
		*a = cur->next;
		free(cur);
	}
	if (bon_man == 1)
		write(1, "ra\n", 3);
}

void	check_strnbr(char *strnbr)
{
	int	i;

	i = 0;
	check_strnbr_deux(strnbr);
	check_strnbr_trois(strnbr);
	check_strnbr_quatre(strnbr);
	if (!strnbr[i])
		exit(1);
	while (strnbr[i])
	{
		if (((strnbr[i] < '0') || (strnbr[i] > '9'))
			&& (strnbr[i] != ' ') && (strnbr[i] != '-') && (strnbr[i] != '+'))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	check_strnbr_trois(char *strnbr)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(strnbr);
	if ((strnbr[i] == '-' || strnbr[i] == '+') && strnbr[i + 1] == '\0')
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	while (strnbr[i] == ' ')
		i++;
	if (size == i)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}
