/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitagaw <mkitagaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 04:09:32 by mkitagaw          #+#    #+#             */
/*   Updated: 2026/01/07 04:22:09 by mkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	count_to_top_a(t_stack *stack_a)
{
	int		count;
	t_list	*cur_a;

	//スタックaに入っているすべてのノードに対して、スタックaのトップに
	//もって行くためのraやrraの実行したい回数をt_listの構造体の中のra,rraに入れる
	//回数の入れ方の例：list_a->count_ra = count;
	cur_a = stack_a->top;
	count = 0;
	while (count < stack_a->size)
	{
		cur_a->count_ra = count;
		cur_a->count_rra = stack_a->size - count;
		if (cur_a->count_ra < cur_a->count_rra)
			cur_a->count_rra = 0;
		else
			cur_a->count_ra = 0;
		count++;
		cur_a = cur_a->next;
	}
}
// rbのカウント
void	check_rb(t_list *node, t_stack *stack_b, int target)
{
	int		count;
	t_list	*cur_b;

	count = 0;
	cur_b = stack_b->top;
	while (count < stack_b->size)
	{
		if (cur_b->data == target)
		{
			node->count_rb = count;
			return ;
		}
		cur_b = cur_b->next;
		count++;
	}
}
// rrbのカウント
void	check_rrb(t_list *node, t_stack *stack_b, int target)
{
	int		count;
	t_list	*cur_b;

	count = 0;
	cur_b = stack_b->top;
	while (count < stack_b->size)
	{
		if (cur_b->data == target)
		{
			node->count_rrb = count;
			return ;
		}
		cur_b = cur_b->prev;
		count++;
	}
}

// stack_bの最大値をtopに持っていく最小手数のカウント
void	count_rb_rrb(t_list *node, t_stack *stack_b, int target)
{
	check_rb(node, stack_b, target);
	check_rrb(node, stack_b, target);
	if (node->count_rb < node->count_rrb)
		node->count_rrb = 0;
	else
		node->count_rb = 0;
}

// stack_bの中で最大値を探す
int	find_max_b(t_stack *stack_b)
{
	int		num_max;
	t_list	*node;
	int		i;

	i = 0;
	node = stack_b->top;
	num_max = node->data;
	while (i < stack_b->size)
	{
		if (node->data > num_max)
			num_max = node->data;
		node = node->next;
		i++;
	}
	return (num_max);
}
int	find_min_b(t_stack *stack_b)
{
	int		num_min;
	t_list	*node;
	int		i;

	i = 0;
	node = stack_b->top;
	num_min = node->data;
	while (i < stack_b->size)
	{
		if (node->data < num_min)
			num_min = node->data;
		node = node->next;
		i++;
	}
	return (num_min);
}
// stack_aよりも小さい数字の中で一番大きい数字
int	find_target_b(int num_a, t_stack *stack_b)
{
	t_list	*node;
	long	target;
	int		count;

	count = 0;
	if (!stack_b || !stack_b->top)
		return (0);
	node = stack_b->top;
	target = LONG_MIN;
	while (count < stack_b->size)
	{
		if (node->data < num_a && node->data > target)
			target = node->data;
		node = node->next;
		count++;
	}
	//もしstack_aより小さい値がstack_bになかったらstack_bの最大値をターゲットにする
	if (target == LONG_MIN)
		return (find_max_b(stack_b));
	return ((int)target);
}
// 特定のノードに対して、ターゲットを探して手数を計算する
void	count_to_b(t_list *node_a, t_stack *stack_b)
{
	int	target;
	int	max_b;
	int	min_b;

	max_b = find_max_b(stack_b);
	min_b = find_min_b(stack_b);
	// 自分が最大値より大きい、または最小値より小さいなら、最大値の上に乗せる
	if (node_a->data > max_b || node_a->data < min_b)
		target = max_b;
	else
		target = find_target_b(node_a->data, stack_b);
	count_rb_rrb(node_a, stack_b, target);
}
//スタックaに入っているすべてのノードに対して、
//現在のスタックbを何回rb,rrbすればpbしてソートされている状態になっているかを調べて、
//それをt_listの構造体の中のrb,rrbに入れる関数
//例：スタックbの中身が　5 2 1 で　3 を入れたい場合はrbを一回やればpbしていい状態になるので
//	　list_b->count_rb = 1　とする
void	count_sort_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int		count;
	t_list	*node_a;

	count = 0;
	node_a = stack_a->top;
	while (count < stack_a->size)
	{
		count_to_b(node_a, stack_b);
		node_a = node_a->next;
		count++;
	}
}
void	calc(int *a, int *b, int *rr)
{
	if (*a < *b)
	{
		*rr = *a;
		*b = *b - *rr;
		*a = 0;
	}
	else if (*b < *a)
	{
		*rr = *b;
		*a = *a - *rr;
		*b = 0;
	}
	else
	{
		*rr = *a;
		*a = 0;
		*b = 0;
	}
}
void	count_rr(t_list *node)
{
	int	ra;
	int	rb;
	int	rr;

	ra = node->count_ra;
	rb = node->count_rb;
	rr = node->count_rr;
	calc(&ra, &rb, &rr);
	node->count_ra = ra;
	node->count_rb = rb;
	node->count_rr = rr;
}

void	count_rrr(t_list *node)
{
	int	rra;
	int	rrb;
	int	rrr;

	rra = node->count_rra;
	rrb = node->count_rrb;
	rrr = node->count_rrr;
	calc(&rra, &rrb, &rrr);
	node->count_rra = rra;
	node->count_rrb = rrb;
	node->count_rrr = rrr;
}
void	count_step_plus(t_list *node)
{
	node->count_step = node->count_ra + node->count_rb + node->count_rr;
	node->count_step += node->count_rra + node->count_rrb + node->count_rrr;
}
void	count_step(t_stack *stack_a)
{
	int		count;
	t_list	*node;

	count = 0;
	node = stack_a->top;
	while (count < stack_a->size)
	{
		count_rr(node);
		count_rrr(node);
		count_step_plus(node);
		node = node->next;
		count++;
	}
	// 1, count_raとcount_rbの数によって、rrの数を計算する（ra,rbの状態によって計算するかどうか判断する）
	// 2, count_rra,count_rrbについても1と同様に計算する
	// 3, t_listの構造体のcount_stepにra,rb,rra,rrb,rr,rrrの数を合算したものを入れる
}

t_list	*find_min_step_node(t_stack *stack_a)
{
	int		count;
	int		min_step_val;
	t_list	*min_step_node;
	t_list	*node_a;

	// count_stepが１番小さいノードを探してリターンする関数
	count = 0;
	min_step_node = stack_a->top;
	min_step_val = min_step_node->count_step;
	node_a = stack_a->top;
	while (count < stack_a->size)
	{
		if (node_a->count_step < min_step_val)
		{
			min_step_val = node_a->count_step;
			min_step_node = node_a;
		}
		node_a = node_a->next;
		count++;
	}
	return (min_step_node);
}

//呼び出し元で動かしたいノードのデータを受け取ってそのデータに基づいてコマンドを実行するための関数
t_list	*find_node_to_b(t_stack *stack_a, t_stack *stack_b)
{
	t_list	*min_step_node;

	count_to_top_a(stack_a);           // top_aに持っていくまでの手数を調べる関数
	count_sort_to_b(stack_a, stack_b); // top_bの理想的なところへ持っていくまでの手数を調べる関数
	count_step(stack_a);
	min_step_node = find_min_step_node(stack_a);
	// stack_aのstepが一番小さいノードを調べる関数
	return (min_step_node);
}
