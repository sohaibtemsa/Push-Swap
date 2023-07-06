/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 19:49:09 by stemsama          #+#    #+#             */
/*   Updated: 2023/01/31 20:00:09 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_strnbr_deux(char *strnbr)
{
	int	i;

	i = 0;
	while (strnbr[i])
	{
		if (((strnbr[i] == '-') || (strnbr[i] == '+'))
			&& ((strnbr[i + 1] == '-') || (strnbr[i + 1] == '+')))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		if (((strnbr[i] >= '0') && (strnbr[i] <= '9'))
			&& ((strnbr[i + 1] == '-') || (strnbr[i + 1] == '+')))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}

void	check_lstnbr_dup(char **lstNbr)
{
	int	i;
	int	j;

	i = 0;
	while (lstNbr[i])
	{
		j = 1;
		while (lstNbr[i + j])
		{
			if (ft_atoi(lstNbr[i]) == ft_atoi(lstNbr[i + j]))
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	remplir_a(t_list **a, char **lstNbr)
{
	int		i;
	t_list	*a_tmp;

	i = 0;
	while (lstNbr[i] != NULL)
	{
		a_tmp = ft_lstnew_ind(ft_atoi(lstNbr[i]), -1);
		if (!a_tmp)
		{
			ft_lstclear_double(lstNbr);
			ft_lstclear(a);
			exit(1);
		}
		ft_lstadd_back(a, a_tmp);
		i++;
	}
}

void	ft_lstclear_a_b(t_list **a, t_list **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
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
