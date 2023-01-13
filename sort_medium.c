/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 23:41:27 by abiru             #+#    #+#             */
/*   Updated: 2023/01/13 12:59:17 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mark_biggest(t_list **stack_a, int big)
{
	int		i;
	t_list	*tmp;

	i = -1;
	while (++i < 3)
	{
		tmp = *stack_a;
		big = -2147483648;
		while (tmp)
		{
			if (tmp->content > big && tmp->flag != 4)
				big = tmp->content;
			tmp = tmp->next;
		}
		tmp = *stack_a;
		while (tmp)
		{
			if (tmp->content == big)
				tmp->flag = 4;
			else if (tmp->flag != 4)
				tmp->flag = 0;
			tmp = tmp->next;
		}
	}
}

void	assign_indices(t_list **stack)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		if (i > ft_lstsize(*stack) / 2)
			tmp->index = -(ft_lstsize(*stack) - i);
		else
			tmp->index = i;
		tmp = tmp->next;
		i++;
	}
}

void	calc_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		j;

	tmp = *stack_b;
	tmp2 = *stack_a;
	j = 0;
	assign_indices(stack_b);
	while (tmp)
	{
		tmp->cost_a = 0;
		while (tmp->content > tmp2->content)
		{
			tmp2 = tmp2->next;
			tmp->cost_a++;
		}
		if (tmp->cost_a > ft_lstsize(*stack_a) / 2)
			tmp->cost_a = -(ft_lstsize(*stack_a) - tmp->cost_a);
		tmp = tmp->next;
		j++;
	}
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
	{
		if ((*stack_a)->flag != 4)
			push(stack_a, stack_b, 0);
		else
			stack_a = rotate(stack_a);
	}
	sort_three(stack_a);
	push(stack_b, stack_a, 1);
}

void	sort_medium(t_list **stack_a, t_list **stack_b)
{
	int		big;
	int		i;

	big = -2147483648;
	mark_biggest(stack_a, big);
	assign_indices(stack_a);
	push_b(stack_a, stack_b);
	while (*stack_b)
	{
		i = 0;
		assign_indices(stack_b);
		calc_cost(stack_a, stack_b);
		arrange_b(i, stack_a, stack_b);
		push(stack_b, stack_a, 1);
		put_back(i, stack_a);
	}
}
