/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:47:14 by abiru             #+#    #+#             */
/*   Updated: 2023/01/12 17:28:16 by abiru            ###   ########.fr       */
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
	t_list	*tmp = *head;
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

// void	mark_biggest(t_list **stack_a, int val)
// {
// 	t_list	*tmp;

// 	tmp = *stack_a;
// 	while (tmp)
// 	{
// 		if (tmp->content == val)
// 			tmp->flag = 4;
// 		else if (tmp->flag != 4)
// 			tmp->flag = 0;
// 		tmp = tmp->next;
// 	}
// }

/*
stack b has to be sorted in a reverse order
1, 5, 2, 4, 3 -> pb, pb - 2,4,3 & 5,1 - 2,3,4(rra, sa) & 5,1 - rrb, pa - 1,2,3,4 & 5, pa - 5,1,2,3,4, ra - 1,2,3,4,5
5,4,3,2,1 -> pb, pb - 3,2,1 & 4,5 -> 1,2,3 (sa, rra) & 4,5 - rrb, pa - 5,1,2,3, pa - 4,5,1,2,3 - ra,ra - 1,2,3,4,5

1,2,5,3,4 -> pb, pb - 5,3,4 & 2,1 -> 3,4,5 (ra) -> pa, pa - 1,2,3,4,5
1,3,5,2,4 -> pb, pb - 5, 2, 4 & 3,1 -> 2,4,5(ra) -> 1,3,2,4,5 (pa, pa) -> ra - 3,2,4,5,1, sa - 2,3,4,5,1, rra 1,2,3,4,5
rra, pb 1,3,5,2 ra,ra, pb 2,1,3, sa 1,2,3 pa, pa, ra,ra
*/

// void	assign_indices(t_list **stack)
// {
// 	t_list	*tmp;
// 	int		i;

// 	tmp = *stack;
// 	i = 0;
// 	while (tmp)
// 	{
// 		if (i > ft_lstsize(*stack) / 2)
// 			tmp->index = -(ft_lstsize(*stack) - i);
// 		else
// 			tmp->index = i;
// 		tmp = tmp->next;
// 		i++;
// 	}
// }

int	find_smallest(t_list **stack)
{
	t_list	*tmp;
	int		smallest;

	tmp = *stack;
	smallest = tmp->content;
	while (tmp)
	{
		if (tmp->content < smallest)
			smallest = tmp->content;
		tmp = tmp->next;
	}
	return (smallest);
}

/*
5,3,2,4,6,-1 -> 3,2,-1 (stack b) -> stack a -> 4,6,5 rra, sa 4,5,6
	when pushing to stack b, push the smallest item first and continue by size.
*/

// void	sort_five(t_list **stack_a, t_list **stack_b)
// {
// 	int	i;
// 	int smallest;
// 	t_list	*tmp;

// 	i = 0;
// 	tmp = *stack_a;
// 	assign_indices(stack_a);
// 	tmp = *stack_a;
// 	while (tmp && ft_lstsize(*stack_a) > 3)
// 	{
// 		i = 0;
// 		smallest = find_smallest(stack_a);
// 		while (tmp && tmp->content != smallest)
// 			tmp = tmp->next;
// 		if (tmp->index < 0)
// 		{
// 			while (i > tmp->index)
// 			{
// 				stack_a = reverse_rotate(stack_a);
// 				i--;
// 			}
// 		}
// 		else
// 		{
// 			while (tmp->index > i)
// 			{
// 				stack_a = rotate(stack_a);
// 				i++;
// 			}
// 		}
// 		push(stack_a, stack_b);
// 		assign_indices(stack_a);
// 		tmp = *stack_a;
// 		write(1, "pb\n", 3);
// 	}
// 	sort_three(stack_a);
// 	while (*stack_b)
// 	{
// 		push(stack_b, stack_a);
// 		write(1, "pa\n", 3);
// 	}
// }

/*
sort the numbers outbound,
divide into chunks,
push numbers in the lower half of the chunk to stack b.

2,4,-1,5,-3,3,7,1,9,10 -> sorted = -3,-1,1,2,3,4,5,7,9,10

*/

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
		exit(0);
	}
	if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else
		big_sort(stack_a, stack_b);
	// print_list(stack_a);
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
