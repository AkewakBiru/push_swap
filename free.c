/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:04:27 by abiru             #+#    #+#             */
/*   Updated: 2023/01/12 21:21:23 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	error_msg(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}
