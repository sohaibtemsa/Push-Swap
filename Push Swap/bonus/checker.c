/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:15:25 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/05 18:37:25 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_strnbr_quatre(char *strnbr)
{
	int	i;

	i = -1;
	while (strnbr[++i])
	{
		if (((strnbr[i] == '+') || (strnbr[i] == '-'))
			&& ((strnbr[i + 1] < '0') || (strnbr[i + 1] > '9')))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
	}
}

void	go_bonus(char **lstNbr)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	remplir_a(&a, lstNbr);
	ft_lstclear_double(lstNbr);
	exec_actions(&a, &b);
	checker_ok_ko(&a, &b);
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
	go_bonus(lstnbr);
}
