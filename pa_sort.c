/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitagaw <mkitagaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 09:36:30 by mkitagaw          #+#    #+#             */
/*   Updated: 2026/01/04 14:52:30 by mkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ターゲット（自分が戻るべき、自分より大きくて一番近い数字）をさがす
static t_list	*find_target_in_a(t_stack *stack_a, int val_b)
{
	t_list	*cur;
	t_list	*target;
	long	num_a;
	int		count;

	cur = stack_a->top;
	target = NULL;
	num_a = LONG_MAX; //比較のために最大値をいれるintmaxまで入るようにする。
	count = 0;
	while (count < stack_a->size)
	{
		if (cur->data > val_b && cur->data < num_a)
		{
			num_a = cur->data;
			target = cur;
		}
		cur = cur->next;
		count++;
	}
	// もし自分より大きい数字がいなかったら（自分が一番大きいなら）、最小値の上に戻る
	if (target == NULL)
	{
		num_a = LONG_MAX;
		count = 0;
		cur = stack_a->top;
		while (count < stack_a->size)
		{
			if (cur->data < num_a)
			{
				num_a = cur->data;
				target = cur;
			}
			cur = cur->next;
			count++;
		}
	}
	return (target);
}
//ｂにあるすべての数字をaの正しいばしょに戻す儀式
void	return_b_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*target;
	int		count;
	t_list	*tmp;

	while (stack_b->size > 0)
	{
		target = find_target_in_a(stack_a, stack_b->top->data);
		count = 0;
		tmp = stack_a->top;
		while (tmp != target)
		{
			count++;
			tmp = tmp->next;
		}
		if (count <= stack_a->size / 2)
		{
			while (stack_a->top != target)
				rotate_a(stack_a);
		}
		else
		{
			while (stack_a->top != target)
				reverse_rotate_a(stack_a);
		}
		push_a(stack_a, stack_b);
	}
}

// 最後に、世界の秩序を整える（最小値を一番上に持ってくる）
void	final_adjustment(t_stack *stack_a)
{
	t_list	*top_node;
	t_list	*cur;
	int		top_num_a;
	int		pos;
	int		count;

	top_num_a = INT_MAX;
	cur = stack_a->top;
	top_node = NULL;
	pos = 0;
	count = 0;
	// 最小値がどこにいるか探すよ
	while (count < stack_a->size)
	{
		if (cur->data < top_num_a)
		{
			top_num_a = cur->data;
			top_node = cur;
		}
		cur = cur->next;
		count++;
	}
	// 最小値までの距離を測る
	cur = stack_a->top;
	while (cur != top_node)
	{
		pos++;
		cur = cur->next;
	}
	// 整列するまで回す
	if (pos <= stack_a->size / 2)
		while (stack_a->top != top_node)
			rotate_a(stack_a);
	else
		while (stack_a->top != top_node)
			reverse_rotate_a(stack_a);
}
