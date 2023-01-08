/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:47:14 by abiru             #+#    #+#             */
/*   Updated: 2023/01/08 17:18:35 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	is_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_validity(char **arg, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < ac)
	{
		j = -1;
		if (arg[i][0] == '\0' || is_space(arg[i]))
			return (2);
		while (arg[i][++j] != '\0')
		{
			if ((arg[i][j] < '0' || arg[i][j] > '9')
				&& arg[i][j] != ' ' && arg[i][j] != '+'
				&& arg[i][j] != '-')
				return (2);
		}
	}
	return (0);
}

int	check_dup(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *head;
	tmp2 = *head;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->content == tmp2->content)
			{
				ft_lstclear(head);
				return (1);
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	free_mem(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = (*head)->next;
	tmp2 = (*head)->next;
	while (tmp != *head)
	{
		tmp = tmp->next;
		free(tmp2);
		tmp2 = tmp;
	}
	free(tmp);
	exit(1);
}

void	free_arr(char **lst)
{
	int	i;

	i = 0;
	while (lst[i])
	{
		free(lst[i]);
		i++;
	}
}

void	check_nums(t_list **head, char **av, int ac)
{
	int		i;
	int		j;
	char	**tmp;
	t_list	*new;

	i = 1;
	while (i < ac)
	{
		j = 0;
		tmp = ft_split(av[i], ' ');
		while (tmp[j])
		{
			if (ft_atol(tmp[j]) == 9223372036854775807)
			{
				ft_lstclear(head);
				free_arr(tmp);
				free(tmp);
				error_msg("ERROR\n");
			}
			new = ft_lstnew((int)ft_atol(tmp[j]));
			ft_lstadd_back(head, new);
			j++;
		}
		free_arr(tmp);
		free(tmp);
		i++;
	}
	if (check_dup(head) == 1)
		error_msg("ERROR\n");
}

void print_list(t_list **head)
{
	t_list *tmp = *head;
	while (tmp)
	{
		printf("%d->", tmp->content);
		tmp = tmp->next;
	}
	printf("NULL\n");
}

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

void	cost_b(t_list *tmp, t_list **stack_b)
{
	if (tmp->index == 0)
		tmp->cost_b = 0;
	else if (tmp->index > ft_lstsize(stack_b) / 2)
		tmp->cost_b = ft_lstsize(stack_b) - tmp->index;
	else
		tmp->cost_b = tmp->index;
}

void	cost_a(t_list *tmp, t_list **stack_a, t_list **stack_b)
{
	
}

void	calc_cost(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_b;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		cost_a(tmp, stack_a, stack_b);
		cost_b(tmp, stack_b);
		tmp = tmp->next;
	}
}

void	sort_five(t_list **stack_a, t_list **stack_b, int size)
{
	while (ft_lstsize(stack_a) > 3)
	{
		push(stack_a, stack_b);
		write(1, "pb\n", 3);
	}
	sort_three(stack_a);
	calc_cost(stack_b, stack_a);
	push(stack_b, stack_a);
	// write(1, "pa\n", 3);
	// if (size == 4)
	// {
	// 	if ((*stack_a)->content > (*stack_a)->next->content
	// 		&& (*stack_a)->content > (*stack_a)->next->next->content
	// 		&& (*stack_a)->content > (*stack_a)->next->next->next->content)
	// 		rotate(stack_a);
	// 	else if ((*stack_a)->content > (*stack_a)->next->content
	// 		&& (*stack_a)->content > (*stack_a)->next->next->content)
	// 	{
	// 		reverse_rotate(stack_a);
	// 		swap(stack_a);
	// 		write(1, "sa\n", 3);
	// 		rotate(stack_a);
	// 		rotate(stack_a);
	// 	}
	// 	else if ((*stack_a)->content > (*stack_a)->next->content)
	// 	{
	// 		swap(stack_a);
	// 		write(1, "sa\n", 3);
	// 	}
	// 	if (is_sorted(stack_a))
	// 	{
	// 		ft_lstclear(stack_a);
	// 		exit(0);
	// 	}
	// }
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	(void)stack_b;
	if (is_sorted(stack_a))
	{
		ft_lstclear(stack_a);
		exit(0);
	}
	if (ft_lstsize(*stack_a) == 2)
	{
		write(1, "sa\n", 3);
		swap(stack_a);
		exit(1);
	}
	if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else
		sort_five(stack_a, stack_b, ft_lstsize(*stack_a));
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
		error_msg("ERROR\n");
	check_nums(&stack_a, av, ac);
	if (ft_lstsize(stack_a) == 1)
	{
		ft_lstclear(&stack_a);
		exit(0);
	}
	sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
}
