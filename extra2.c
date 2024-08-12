/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouguri <abouguri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:07:38 by abouguri          #+#    #+#             */
/*   Updated: 2024/08/12 22:31:14 by abouguri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
