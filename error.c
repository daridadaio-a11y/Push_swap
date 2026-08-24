/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitagaw <mkitagaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 04:44:35 by mkitagaw          #+#    #+#             */
/*   Updated: 2026/01/07 03:53:58 by mkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//最初からソートされている時
int	already_sort(t_stack *stack_a)
{
	t_list	*node_a;
	int		count;

	if (!stack_a || !stack_a->top)
		return (1);
	node_a = stack_a->top;
	count = 0;
	while (count < stack_a->size)
	{
		if (node_a->data > node_a->next->data)
			return (0);
		node_a = node_a->next;
		count++;
	}
	return (1);
}
//引数に文字がある場合、int整数外、重複、
int	is_argv_str(char **args)
{
	int	i;
	int	j;

	i = 0;
	if (args[0][0] == '\0')
		return (1);
	while (args[i] != NULL)
	{
		if (args[i][0] == '\0' || args[i] == NULL)
			return (1);
		j = 0;
		if (args[i][j] == '-' || args[i][j] == '+')
			j++;
		if (args[i][j] == '\0')
			return (1);
		while (args[i][j])
		{
			if (args[i][j] < '0' || args[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_over_intmax(char **args)
{
	long	data;
	int		i;

	i = 0;
	while (args[i] != NULL)
	{
		data = ft_atoi(args[i]);
		if (data < INT_MIN || data > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	is_duplicate(char **args)
{
	int	data;
	int	data2;
	int	i;
	int	j;

	data = 0;
	data2 = 0;
	i = 0;
	while (args[i] != NULL)
	{
		data = ft_atoi(args[i]);
		j = i + 1;
		while (args[j] != NULL)
		{
			data2 = ft_atoi(args[j]);
			if (data == data2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_error(char **args)
{
	if (is_argv_str(args) || is_duplicate(args) || is_over_intmax(args))
		return (1);
	return (0);
}
