/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitagaw <mkitagaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 06:22:56 by mkitagaw          #+#    #+#             */
/*   Updated: 2026/01/07 00:45:40 by mkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *stack_a)
{
	swap_a(stack_a);
}

void	sort_3(t_stack *stack_a) // 1 2 3っていうソートにしたい
{
	int first;
	int second;
	int third;

	if (stack_a == NULL || stack_a->size != 3)
		return ;
	first = stack_a->top->data;
	second = stack_a->top->next->data;
	third = stack_a->top->next->next->data;
	if (first > second && second < third && first < third) // 2 1 3
		sort_2(stack_a);
	else if (first > second && second > third) // 3 2 1
	{
		sort_2(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (first > second && second < third && first > third) // 3 1 2
		rotate_a(stack_a);
	else if (first < second && second > third && first < third) // 1 3 2
	{
		sort_2(stack_a);
		rotate_a(stack_a);
	}
	else if (first < second && second > third && first > third) // 2 3 1
		reverse_rotate_a(stack_a);
}


void	sort_4(t_stack *stack_a, t_stack *stack_b)
{
	int		count;
	int		min;
	t_list	*cur;

	/* 最小値を探す */
	min = stack_a->top->data;
	cur = stack_a->top;
	count = 0;
	while (count < stack_a->size)
	{
		if (cur->data < min)
			min = cur->data;
		cur = cur->next;
		count++;
	}
	/* 最小値が top に来るまで回す */
	while (stack_a->top->data != min)
		rotate_a(stack_a);
	/* 1個だけ B に逃がす */
	push_b(stack_a, stack_b);
	/* 残り3つを既存の関数で */
	sort_3(stack_a);
	/* 戻す */
	push_a(stack_a, stack_b);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	t_list *min_step_node;
	if (stack_a->size == 2)
		sort_2(stack_a);
	else if (stack_a->size == 3)
		sort_3(stack_a);
	else if (stack_a->size == 4)
	{
		sort_4(stack_a, stack_b);
	}
	else if (stack_a->size > 4)
	{
		// bが空だとだめ
		push_b(stack_a, stack_b);
		push_b(stack_a, stack_b);
		while (stack_a->size > 3)
		{
			min_step_node = find_node_to_b(stack_a,stack_b);
			print_ops_by_count(stack_a, stack_b, min_step_node);
			push_b(stack_a, stack_b);
		}
		sort_3(stack_a);
		// bからaに戻す
		return_b_to_a(stack_a, stack_b);
		final_adjustment(stack_a);
	}
}
