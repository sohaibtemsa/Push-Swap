/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:21:24 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/02 22:37:04 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	go_to_sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (size == 2)
		push_swap_2(a);
	else if (size == 3)
		push_swap_3(a, b);
	else if (size == 4)
		push_swap_4(a, b);
	else if (size == 5)
		push_swap_5(a, b);
	else if (size <= 500)
		push_swap_500(a, b);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

int	check_lstnbr_sorted(t_list **a)
{
	t_list	*cur;

	cur = (*a);
	while (cur->next)
	{
		if (cur->content > cur->next->content)
			return (0);
		cur = cur->next;
	}
	return (1);
}

void	go(char **lstNbr)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	remplir_a(&a, lstNbr);
	ft_lstclear_double(lstNbr);
	if (check_lstnbr_sorted(&a))
	{
		ft_lstclear(&a);
		exit(0);
	}
	go_to_sort(&a, &b);
	ft_lstclear_a_b(&a, &b);
}

int	main(int ac, char **av)
{
	char	*strnbr;
	char	**lstnbr;

	strnbr = NULL;
	if (ac > 1)
		strnbr = get_strnbr(ac, av);
	else
		exit(1);
	check_strnbr(strnbr);
	lstnbr = ft_split(strnbr, ' ');
	free(strnbr);
	if (!lstnbr)
	{
		write(2, "Error\n", 6);
		ft_lstclear_double(lstnbr);
		exit(1);
	}
	check_lstnbr_dup(lstnbr);
	go(lstnbr);
}
