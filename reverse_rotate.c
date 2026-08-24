/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitagaw <mkitagaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 23:41:02 by mkitagaw          #+#    #+#             */
/*   Updated: 2026/01/04 09:23:05 by mkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *stack_a)
{
	if (!stack_a || !stack_a->top
		|| stack_a->top->next == stack_a->top)
		return ;
	stack_a->top = stack_a->top->prev;
	write(1,"rra\n",4);
}

void	reverse_rotate_b(t_stack *stack_b)
{
	if (!stack_b || !stack_b->top
		|| stack_b->top == stack_b->top->next)
		return ;
	stack_b->top = stack_b->top->prev;
	write(1,"rrb\n",4);
}

#include "push_swap.h"

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	// reverse_rotate_a の中身
	if (stack_a && stack_a->top && stack_a->top->next != stack_a->top)
		stack_a->top = stack_a->top->prev;

	// reverse_rotate_b の中身
	if (stack_b && stack_b->top && stack_b->top->next != stack_b->top)
		stack_b->top = stack_b->top->prev;

	// まとめて出力！
	write(1, "rrr\n", 4);
}