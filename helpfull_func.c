
#include "push_swap.h"

int	ft_chunk(int size_a)
{
	int	chunk;

	chunk = 0;
	if (size_a <= 20)
		chunk = size_a / 2;
	else if (size_a <= 100)
		chunk = size_a / 6;
	else if (size_a > 100)
		chunk = size_a / 11;
	return (chunk);
}

void	ft_check_double(t_stack *a)
{
	int	nb;

	nb = a->nb;
	while (a->next != NULL)
	{
		a = a->next;
		if (nb == a->nb)
			ft_exit();
	}
}

void	f_stack_a(t_stack **a, char **str)
{
	int	i;

	i = 0;
	if (str[i] == NULL)
		ft_exit();
	while (str[i])
		i++;
	while (i--)
	{
		printf("array:  %s\n", str[i]);

		add_front(a, ft_lstnew(ft_atoi(str[i])));
		ft_check_double(*a);

	}
}

int	check_sort(t_stack *a)
{
	while (a->next)
	{
		if (a->nb > a->next->nb)
			return (1);
		a = a->next;
	}
	return (0);
}

void	sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	swap;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				swap = tab[i];
				tab[i] = tab[j];
				tab[j] = swap;
			}
			j++;
		}
		i++;
	}
}
