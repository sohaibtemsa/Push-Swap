/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_tools1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:33:18 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/02 19:47:25 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	les_actions(t_list **a, t_list **b, char *action)
{
	if (ft_strcmp(action, "ra\n") == 0)
		rotate_a(a, b, 0);
	else if (ft_strcmp(action, "rb\n") == 0)
		rotate_b(a, b, 0);
	else if (ft_strcmp(action, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(action, "rra\n") == 0)
		rv_rotate_a(a, b, 0);
	else if (ft_strcmp(action, "rrb\n") == 0)
		rv_rotate_b(a, b, 0);
	else if (ft_strcmp(action, "rrr\n") == 0)
		rrr(a, b, 0);
	else if (ft_strcmp(action, "pa\n") == 0)
		push_a(a, b, 0);
	else if (ft_strcmp(action, "pb\n") == 0)
		push_b(a, b, 0);
	else if (ft_strcmp(action, "sa\n") == 0)
		swap_a(a, 0);
	else if (ft_strcmp(action, "sb\n") == 0)
		swap_b(b, 0);
	else if (ft_strcmp(action, "ss\n") == 0)
		ss(a, b, 0);
	else
		put_error();
}

void	put_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	checker_ok_ko(t_list **a, t_list **b)
{
	if ((check_lstnbr_sorted(a) == 1) && (*b == NULL))
	{
		write(1, "OK\n", 3);
		exit(0);
	}
	else
	{
		write(1, "KO\n", 3);
		exit(1);
	}
}

void	exec_actions(t_list **a, t_list**b)
{
	char	*action;

	action = get_next_line(0);
	while (action)
	{
		if (ft_strcmp(action, "rrb\n") != 0 && ft_strcmp(action, "rb\n") != 0
			&& ft_strcmp(action, "sb\n") != 0)
			les_actions(a, b, action);
		else if (*b != NULL)
			les_actions(a, b, action);
		free(action);
		action = get_next_line(0);
	}
}
