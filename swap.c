/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitagaw <mkitagaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 23:31:32 by mkitagaw          #+#    #+#             */
/*   Updated: 2026/01/04 18:12:56 by mkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	t_list *first;  // 1
	t_list *second; // 2
	if (!stack_a || stack_a->size < 2)
		return ;
	first = stack_a->top;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->prev = first->prev;
	first->prev->next = second;
	second->next = first;
	first->prev = second;
	stack_a->top = second;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack_b)
{
	t_list *first;
	t_list *second;
	if (!stack_b || stack_b->size < 2)
		return ;
	first = stack_b->top;
	second = first->next;
	first->next = second->next;
	second->next->prev = first;
	second->prev = first->prev;
	first->prev->next = second;
	second->next = first;
	first->prev = second;
	stack_b->top = second;
	write(1, "sb\n", 3);
}