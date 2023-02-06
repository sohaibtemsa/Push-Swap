/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:57:36 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/02 19:55:32 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*get_strnbr(int ac, char **av)
{
	char	*lstnbr;
	int		i;

	i = 1;
	lstnbr = NULL;
	lstnbr = ft_strjoin(lstnbr, av[1]);
	check_strnbr(av[1]);
	if (!lstnbr)
	{
		free(lstnbr);
		write(2, "Error\n", 6);
		exit(1);
	}
	i++;
	while (i < ac)
	{
		lstnbr = ft_strjoin(lstnbr, " ");
		check_strnbr(av[i]);
		lstnbr = ft_strjoin(lstnbr, av[i]);
		i++;
	}
	return (lstnbr);
}

int	check_lstnbr_sorted(t_list **a)
{
	t_list	*cur;

	if (ft_lstsize(*a) >= 1)
	{
		cur = (*a);
		while (cur->next)
		{
			if (cur->content > cur->next->content)
				return (0);
			cur = cur->next;
		}
		return (1);
	}
	return (0);
}

void	ft_lstclear_double(char **lstNbr)
{
	int	i;

	i = 0;
	while (lstNbr[i])
		free(lstNbr[i++]);
	free(lstNbr);
}

void	swap_a(t_list **a, int bon_man)
{
	int	cur;

	if (ft_lstsize(*a) > 1)
	{	
		cur = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = cur;
		if (bon_man == 1)
			write(1, "sa\n", 3);
	}
}

void	swap_b(t_list **b, int bon_man)
{
	int	cur;

	if (ft_lstsize(*b) > 1)
	{
		cur = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = cur;
		if (bon_man == 1)
			write(1, "sa\n", 3);
	}
}
