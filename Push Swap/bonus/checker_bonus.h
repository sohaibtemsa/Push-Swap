/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stemsama <stemsama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:50:04 by stemsama          #+#    #+#             */
/*   Updated: 2023/01/31 19:07:32 by stemsama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "get_next_line.h"
# include "../push_swap.h"
# include "../libft/libft.h"

//------------------------------------------------------------bonus
void	les_actions(t_list **a, t_list **b, char *action);
void	checker_ok_ko(t_list **a, t_list **b);
void	exec_actions(t_list **a, t_list**b);
void	go_bonus(char **lstNbr);
void	put_error(void);

#endif