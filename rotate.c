/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitagaw <mkitagaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 01:07:56 by mkitagaw          #+#    #+#             */
/*   Updated: 2026/01/04 09:22:48 by mkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack_a)
{
	if (!stack_a || !stack_a->top
		|| stack_a->top->next == stack_a-> top)
		return;
	stack_a->top = stack_a->top->next;
	write(1,"ra\n",3);
}


void	rotate_b(t_stack *stack_b)
{
	if (!stack_b || !stack_b->top
		|| stack_b->top == stack_b->top->next)
		return ;
	stack_b->top = stack_b->top->next;
	write(1,"rb\n",3);
}

void	rr(t_stack *stack_a,t_stack *stack_b)
{
	if (stack_a && stack_a->top && stack_a->top->next != stack_a->top)
		stack_a->top = stack_a->top->next;
	
	// rotate_b の中身と同じ処理
	if (stack_b && stack_b->top && stack_b->top->next != stack_b->top)
		stack_b->top = stack_b->top->next;
	
	// まとめて出力！
	write(1, "rr\n", 3);
}
