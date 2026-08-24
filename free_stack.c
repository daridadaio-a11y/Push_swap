/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitagaw <mkitagaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 03:25:23 by mkitagaw          #+#    #+#             */
/*   Updated: 2026/01/04 03:36:31 by mkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
void	free_stack(t_stack *stack)
{
	t_list *list;
	t_list *node;
	int i;
	i = 0;
	if(!stack)
		return;
	if(stack->top)
	{
		list =stack->top;
		while(i < stack->size)
		{
			node = list->next;
			free(list);
			list = node;
			i++;
		}
	}
	free(stack);
}
