#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*prev;
	struct s_list	*next;
	int				data;
	// これより下は追加した変数
	int				count_ra;
	int				count_rra;
	int				count_rb;
	int				count_rrb;
	int				count_rr;
	int				count_rrr;
	int				count_step;
}					t_list;

typedef struct s_stack
{
	int				size;
	t_list			*top;
}					t_stack;

t_stack				*stack_init_empty(void);
t_stack				*stack_init(char **args);
char				**ft_split(char const *s, char c);
long				ft_atoi(const char *str);
void				sort(t_stack *stack_a, t_stack *stack_b);
int					already_sort(t_stack *stack_a);
int					is_argv_str(char **args);
int					is_over_intmax(char **args);
int					is_duplicate(char **args);
int					check_error(char **args);
void				swap_a(t_stack *stack_a);
void				swap_b(t_stack *stack_b);
void				push(t_stack *stack_dst, t_list *tmp);
void				push_a(t_stack *stack_a, t_stack *stack_b);
void				push_b(t_stack *stack_a, t_stack *stack_b);
void				rotate_a(t_stack *stack_a);
void				rotate_b(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				reverse_rotate_a(t_stack *stack_a);
void				reverse_rotate_b(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);
void				sort_2(t_stack *stack_a);
void				sort_3(t_stack *stack_a);
void				sort_4(t_stack *stack_a, t_stack *stack_b);
t_list				*find_node_to_b(t_stack *stack_a, t_stack *stack_b);
void				print_ops_by_count(t_stack *stack_a, t_stack *stack_b,
						t_list *min_step_node);
void				return_b_to_a(t_stack *stack_a, t_stack *stack_b);
void				final_adjustment(t_stack *stack_a);
void				free_args(char **args);
void				free_stack(t_stack *stack);
#endif