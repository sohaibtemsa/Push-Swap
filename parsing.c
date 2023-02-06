/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:04:34 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/05 18:28:31 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_strnbr(char *strnbr)
{
	int	i;

	i = -1;
	check_strnbr_deux(strnbr);
	check_strnbr_trois(strnbr);
	check_strnbr_quatre(strnbr);
	if (!strnbr[0])
		exit(1);
	while (strnbr[++i])
	{
		if (((strnbr[i] < '0') || (strnbr[i] > '9'))
			&& (strnbr[i] != ' ') && (strnbr[i] != '-') && (strnbr[i] != '+'))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
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
