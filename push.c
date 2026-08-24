/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitagaw <mkitagaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 10:27:58 by mkitagaw          #+#    #+#             */
/*   Updated: 2026/01/06 22:41:02 by mkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// b の先頭要素を取り、a の先頭に置く。b が空なら何もしない。

void	push(t_stack *stack_dst,t_list *tmp)
{
	if (!stack_dst->top)
	{
		tmp->next = tmp;
		tmp->prev = tmp;
		stack_dst->top = tmp;
	}
	else
	{
		tmp->next = stack_dst->top;
		tmp->prev = stack_dst->top->prev;
		stack_dst->top->prev->next = tmp;
		stack_dst->top->prev = tmp;
		stack_dst->top = tmp;
	}
	stack_dst->size++;
}
void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	t_list *tmp;
		if (!stack_b->top)
		return ;
	tmp = stack_b->top;
	if (tmp == tmp->next)
		stack_b->top = NULL;
	else
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		stack_b->top = tmp->next;
	}
	stack_b->size--;
	push(stack_a,tmp);
	write(1,"pa\n",3);

}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_list *tmp;
		if (!stack_a->top)
		return ;
	tmp = stack_a->top;
	if (tmp == tmp->next)
		stack_a->top = NULL;
	else
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		stack_a->top = tmp->next;
	}
	stack_a->size--;
	push(stack_b,tmp);
	write(1,"pb\n",3);
}
