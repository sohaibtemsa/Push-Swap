/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:30:39 by stemsama          #+#    #+#             */
/*   Updated: 2023/02/05 18:29:22 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

//------------------------------------------------------------tools
void	ft_lstclear_a_b(t_list **a, t_list **b);
void	ft_lstclear_double(char **lstNbr);

//------------------------------------------------------------actions
void	rotate_a(t_list **a, t_list **b, int bon_man);
void	rotate_b(t_list **a, t_list **b, int bon_man);
void	rr(t_list **a, t_list **b, int bon_man);
void	rv_rotate_a(t_list **a, t_list **b, int bon_man);
void	rv_rotate_b(t_list **a, t_list **b, int bon_man);
void	rrr(t_list **a, t_list **b, int bon_man);

void	swap_a(t_list **a, int bon_man);
void	swap_b(t_list **b, int bon_man);
void	ss(t_list **a, t_list **b, int bon_man);

void	push_a(t_list **a, t_list **b, int bon_man);
void	push_b(t_list **a, t_list **b, int bon_man);

//----v2(probleme d'index > 5)
void	rotate_a_v2(t_list **a, t_list **b);
void	rotate_b_v2(t_list **a, t_list **b);
void	push_a_v2(t_list **a, t_list **b);
void	push_b_v2(t_list **a, t_list **b);

//------------------------------------------------------------algo
void	go_to_sort(t_list **a, t_list **b);

void	push_swap_2(t_list **a);
void	push_swap_3(t_list **a, t_list **b);
void	push_swap_4(t_list **a, t_list **b);
void	push_swap_5(t_list **a, t_list **b);
//-----
int		get_min(t_list *a);
void	ra_while(t_list **a, t_list **b, int nbr_ra);
void	rra_while(t_list **a, t_list **b, int nbr_ra);
void	put_min_first(t_list **a, t_list **b);

//------------------------------------------------------------main
char	*get_strnbr(int ac, char **av);
void	go_to_sort(t_list **a, t_list **b);
int		check_lstnbr_sorted(t_list **a);
void	go(char **lstNbr);

//------------------------------------------------------------parsing
void	check_strnbr(char *av);
void	check_lstnbr_dup(char **lstNbr);
void	remplir_a(t_list **a, char **lstNbr);
void	check_strnbr_deux(char *strnbr);
void	check_strnbr_trois(char *strnbr);
void	check_strnbr_quatre(char *strnbr);

//------------------------------------------------------------push_swap
int		max_nbr_bit(t_list **a);
void	push_swap_500(t_list **a, t_list **b);
void	sort_par_index(t_list **a);
void	radix_part(t_list **a, t_list **b, int nbr_chft);

#endif