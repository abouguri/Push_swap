/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouguri <abouguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:06:03 by abouguri          #+#    #+#             */
/*   Updated: 2024/08/12 22:06:04 by abouguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct push_swap
{
	int					nb;
	struct push_swap	*next;
}						t_stack;

typedef struct push_swap_vars
{
	int					*tab;
	int					i;
	int					key;
	int					pos;
	int					size_a;
}						t_var;

void					free_spl(char **splited);
void					ft_exit(void);
void					ft_check_double(t_stack *a);
void					f_stack_a(t_stack **a, char **str);
int						check_sort(t_stack *a);
void					sort_tab(int *tab, int size);
int						list_size(t_stack *lst);
t_stack					*ft_lstnew(int content);
void					add_front(t_stack **lst, t_stack *new);
void					ft_lstadd_back(t_stack **lst, t_stack *new);
void					sa(t_stack **a);
void					sb(t_stack **b);
void					pa(t_stack **a, t_stack **b);
void					pb(t_stack **a, t_stack **b);
void					ra(t_stack **a);
void					rb(t_stack **b);
void					rra(t_stack **a);
void					rrb(t_stack **b);
char					**ft_split(char const *s, char c);
int						count_words(char const *s1, char c);
void					word_malloc(char **splited, char const *s1, char c,
							int nw);
void					free_func(char **splited, int i);
int						ft_atoi(const char *str);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strdup(const char *s1);
size_t					ft_strlen(const char *s);
void					sort_five_less(t_stack **a, t_stack **b);
void					push_to_b(t_stack **a, t_stack **b, int i);
int						*stack_to_arr(t_stack *a);
int						find_in_arr(int *arr, t_stack *a, int c);
void					sort_three_less(t_stack **a);
void					sort_more_than_five(t_stack **a, t_stack **b);
void					push_chunks_to_b(int i, int *tab, t_stack **a,
							t_stack **b);
int						ft_chunk(int size_a);
int						search_for_small(t_stack *a);
int						search_for_big(t_stack *b);
int						search_for_pos(t_stack *a, int key_num, int size);
void					push_rest_to_b(t_stack **a, t_stack **b);
void					repush_conditions(t_stack **a, t_stack **b, t_var *var);
void					else_conditions(t_stack **a, t_stack **b, t_var *var);

#endif
