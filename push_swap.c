/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouguri <abouguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:08:29 by abouguri          #+#    #+#             */
/*   Updated: 2024/08/12 22:29:57 by abouguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	helper(t_stack *a, t_stack *b, int i)
{
	if (i <= 3)
		sort_three_less(&a);
	else if (i <= 5)
		sort_five_less(&a, &b);
	else if (i <= 500)
		sort_more_than_five(&a, &b);
}

int	main(int ac, char **av)
{
	int		i;
	char	**str;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	i = ac - 1;
	while (i)
	{
		str = ft_split(av[i], ' ');
		f_stack_a(&a, str);
		free_spl(str);
		i--;
	}
	if (check_sort(a) == 0)
		return (0);
	i = list_size(a);
	helper(a, b, i);
}
