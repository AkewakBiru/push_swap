/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:47:14 by abiru             #+#    #+#             */
/*   Updated: 2023/01/13 19:31:29 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	if (tmp->content > tmp->next->content)
	{
		write(1, "sa\n", 3);
		swap(head);
	}
	tmp = tmp->next;
	if (tmp->content > tmp->next->content)
		reverse_rotate(head);
	tmp = *head;
	if (tmp->content > tmp->next->content)
	{
		write(1, "sa\n", 3);
		swap(head);
	}
}

void	init_vars(t_list **stack_a, t_ints *t_int)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_a;
	t_int->arr = (int *)malloc(sizeof(int) * ft_lstsize(*stack_a));
	if (!t_int->arr)
		return ;
	sort_nums(stack_a, ft_lstsize(*stack_a), t_int->arr);
	while (tmp)
	{
		i = -1;
		while (++i < ft_lstsize(*stack_a))
		{
			if (tmp->content == t_int->arr[i])
				tmp->index = i;
		}
		tmp = tmp->next;
	}
	t_int->max_dig = ft_lstsize(*stack_a) - 1;
	t_int->bit_num = 0;
	while ((t_int->max_dig >> t_int->bit_num) != 0)
		t_int->bit_num++;
	return ;
}

void	sort_big(t_list **stack_a, t_list **stack_b)
{
	int		i;
	t_ints	*t_int;
	int		j;

	t_int = (t_ints *)malloc(sizeof(t_ints));
	if (!t_int)
		return ;
	init_vars(stack_a, t_int);
	i = -1;
	while (++i < t_int->bit_num)
	{
		j = -1;
		while (++j < t_int->max_dig + 1)
		{
			if (((*stack_a)->index >> i & 1) == 0)
				push(stack_a, stack_b, 0);
			else
				stack_a = rotate(stack_a);
		}
		while (*stack_b)
			push(stack_b, stack_a, 1);
	}
	free(t_int->arr);
	free(t_int);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(stack_a))
	{
		ft_lstclear(stack_a);
		exit(0);
	}
	if (ft_lstsize(*stack_a) == 2)
	{
		write(1, "sa\n", 3);
		swap(stack_a);
	}
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) < 50)
		sort_medium(stack_a, stack_b);
	else
		sort_big(stack_a, stack_b);
	return ;
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (check_validity(av, ac) == 2)
		error_msg("Error\n");
	check_nums(&stack_a, av, ac);
	if (ft_lstsize(stack_a) == 1)
	{
		ft_lstclear(&stack_a);
		exit(0);
	}
	sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
