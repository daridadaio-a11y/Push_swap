/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitagaw <mkitagaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 22:16:08 by mkitagaw          #+#    #+#             */
/*   Updated: 2026/01/04 09:28:41 by mkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*new_node(int data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	node->count_ra = 0;
	node->count_rb = 0;
	node->count_rr = 0;
	node->count_rra = 0;
	node->count_rrb = 0;
	node->count_rrr = 0;
	node->count_step = 0;
	return (node);
}
t_stack	*stack_init(char **args)
{
	t_stack	*stack_a;
	t_list	*list;
	t_list	*node;
	int		data;
	int		i;

	i = 1;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (NULL);
	*stack_a = (t_stack){0};
	if (!args || !args[0])
	{
		free(stack_a);
		return (NULL);
	}
	data = ft_atoi(args[0]);
	list = new_node(data);
	node = list;
	stack_a->size++;
	while (args[i])
	{
		data = ft_atoi(args[i]);
		node->next = new_node(data); //接続
		node->next->prev = node;
		node = node->next; //移動
		i++;
		stack_a->size++;
	}
	node->next = list;
	list->prev = node;
	stack_a->top = list;
	return (stack_a);
}

t_stack	*stack_init_empty(void)
{
	t_stack	*stack_b;

	stack_b = malloc(sizeof(t_stack));
	if (!stack_b)
		return (NULL);
	stack_b->top = NULL;
	stack_b->size = 0;
	return (stack_b);
}
