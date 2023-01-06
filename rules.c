/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 17:48:39 by abiru             #+#    #+#             */
/*   Updated: 2023/01/06 21:20:09 by abiru            ###   ########.fr       */
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

void	push(t_list **head, t_list **head2)
{
	t_list	*top;
	t_list	*tmp;

	if (!head || !(*head))
		return ;
	tmp = *head;
	top = ft_lstnew(tmp->content);
	*head = (*head)->next;
	ft_lstdelone(tmp);
	ft_lstadd_front(head2, top);
}

void	rotate(t_list **head)
{
	t_list	*tmp;

	if (!head || !(*head))
		return ;
	tmp = *head;
	*head = (*head)->next;
	ft_lstdelone(tmp);
	tmp = ft_lstnew((*head)->content);
	ft_lstadd_back(head, tmp);
}

void	reverse_rotate(t_list **head)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!head || !(*head))
		return ;
	tmp = ft_lstlast(*head);
	tmp2 = ft_lstnew(tmp->content);
	ft_lstdelone(tmp);
	ft_lstadd_front(head, tmp2);
}
