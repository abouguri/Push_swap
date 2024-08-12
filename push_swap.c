
#include "push_swap.h"

void	free_spl(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

int	search_for_pos(t_stack *a, int key_num, int size)
{
	int	i;

	i = 0;
	while (--size)
	{
		if (a->nb <= key_num)
			break ;
		i++;
		a = a->next;
	}
	return (i);
}

int	search_for_big(t_stack *b)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	j = 0;
	nb = b->nb;
	while (b)
	{
		if (nb < b->nb)
		{
			nb = b->nb;
			i = j;
		}
		j++;
		b = b->next;
	}
	return (i);
}

int	search_for_small(t_stack *a)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	j = 0;
	nb = a->nb;
	while (a)
	{
		if (nb > a->nb)
		{
			nb = a->nb;
			i = j;
		}
		j++;
		a = a->next;
	}
	return (i);
}

int	main(int ac, char **av)
{
	int		i;
	char	**str;
	t_stack	*a = NULL;
	t_stack	*b = NULL;

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
	if (i <= 3)
		sort_three_less(&a);
	else if (i <= 5)
		sort_five_less(&a, &b);
	else if (i <= 500)
		sort_more_than_five(&a, &b);
}