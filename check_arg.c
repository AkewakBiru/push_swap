/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:58:34 by abiru             #+#    #+#             */
/*   Updated: 2023/01/13 19:24:25 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_exit(t_list **head, char **tmp)
{
	ft_lstclear(head);
	free_arr(tmp);
	free(tmp);
	error_msg("Error\n");
}

void	check_nums(t_list **head, char **av, int ac)
{
	int		i;
	int		j;
	char	**tmp;
	t_list	*new;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		tmp = ft_split(av[i], ' ');
		while (tmp[++j])
		{
			if (ft_atol(tmp[j]) == 9223372036854775807)
				free_exit(head, tmp);
			new = ft_lstnew((int)ft_atol(tmp[j]));
			ft_lstadd_back(head, new);
		}
		free_arr(tmp);
		free(tmp);
	}
	if (check_dup(head) == 1)
		error_msg("Error\n");
}
