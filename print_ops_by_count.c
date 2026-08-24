/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ops_by_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitagaw <mkitagaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 15:04:11 by mkitagaw          #+#    #+#             */
/*   Updated: 2026/01/04 09:21:29 by mkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ops_by_count(t_stack *stack_a, t_stack *stack_b,
		t_list *min_step_node)
{
	int	i;

	i = min_step_node->count_rr;
	while (i-- > 0)
		rr(stack_a, stack_b);
	i = min_step_node->count_rrr;
	while (i-- > 0)
		rrr(stack_a, stack_b);
	i = min_step_node->count_ra;
	while (i-- > 0)
		rotate_a(stack_a);
	i = min_step_node->count_rb;
	while (i-- > 0)
		rotate_b(stack_b);
	i = min_step_node->count_rra;
	while (i-- > 0)
		reverse_rotate_a(stack_a);
	i = min_step_node->count_rrb;
	while (i-- > 0)
		reverse_rotate_b(stack_b);
}
