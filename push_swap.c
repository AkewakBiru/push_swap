/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:47:14 by abiru             #+#    #+#             */
/*   Updated: 2023/01/06 19:05:27 by abiru            ###   ########.fr       */
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

void sort(t_list **stack_a, t_list **stack_b)
{
	(void)stack_a;
	(void)stack_b;
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
	printf("OK\n");
	sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
}
