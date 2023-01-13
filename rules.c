/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:48:39 by abiru             #+#    #+#             */
/*   Updated: 2023/01/13 12:55:37 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head)
{
	t_list	*tmp;
	int		val;

	tmp = *head;
	if (!tmp || !tmp->next)
		return ;
	val = tmp->content;
	tmp->content = tmp->next->content;
	tmp->next->content = val;
}

void	push(t_list **head, t_list **head2, int flag)
{
	t_list	*top;
	t_list	*tmp;

	if (!head || !(*head))
		return ;
	tmp = *head;
	top = ft_lstnew(tmp->content);
	top->index = tmp->index;
	*head = (*head)->next;
	ft_lstdelone(tmp);
	ft_lstadd_front(head2, top);
	if (flag == 0)
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}

t_list	**rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!head || !(*head))
		return (NULL);
	tmp = *head;
	*head = (*head)->next;
	tmp2 = ft_lstnew(tmp->content);
	tmp2->index = tmp->index;
	ft_lstdelone(tmp);
	ft_lstadd_back(head, tmp2);
	write(1, "ra\n", 3);
	return (head);
}

t_list	**reverse_rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!head || !(*head))
		return (NULL);
	tmp = ft_lstlast(*head);
	tmp2 = ft_lstnew(tmp->content);
	tmp = *head;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstdelone(tmp->next);
	tmp->next = NULL;
	ft_lstadd_front(head, tmp2);
	write(1, "rra\n", 4);
	return (head);
}
