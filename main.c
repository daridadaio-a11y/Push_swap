/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkitagaw <mkitagaw@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 01:18:18 by mkitagaw          #+#    #+#             */
/*   Updated: 2026/01/06 22:02:28 by mkitagaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// //引数を全部スペース区切りで連結する
char	*join_args(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*str;
	int		len;

	len = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j++])
			len++;
		len++; //スペース分
		i++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			str[k++] = argv[i][j++];
		str[k++] = ' ';
		i++;
	}
	str[k] = '\0';
	return (str);
}

// splitされた配列をfree
void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	is_only_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*joined_str;
	char	**args;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '\0' || is_only_space(argv[i]))
			return (write(STDERR_FILENO, "Error\n", 6), 1);
		i++;
	}
	if (argc < 2)
		return (0);
	joined_str = join_args(argc, argv);
	if (!joined_str)
		return (write(STDERR_FILENO, "Error\n", 6), 1);
	args = ft_split(joined_str, ' ');
	free(joined_str);
	if (!args || !args[0])
	{
		free_args(args);
		return (write(STDERR_FILENO, "Error\n", 6), 1);
	}
	if (check_error(args))
	{
		write(STDERR_FILENO, "Error\n", 6);
		free_args(args);
		return (1);
	}
	stack_a = stack_init(args);
	stack_b = stack_init_empty();
	if (already_sort(stack_a))
	{
		free_stack(stack_a);
		free_args(args);
		free_stack(stack_b);
		return (0);
	}
	sort(stack_a,stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	free_args(args);
	return (0);
}
