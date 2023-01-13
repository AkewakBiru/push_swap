/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 14:41:37 by abiru             #+#    #+#             */
/*   Updated: 2023/01/13 14:53:28 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list) * sizeof(int));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->index = 0;
	new_node->flag = 0;
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
	return ;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!temp)
	{
		*lst = new;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
	return ;
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	lst->content = 0;
	free(lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*current;

	if (!lst)
		return ;
	temp = *lst;
	current = *lst;
	while (current != NULL)
	{
		current = current->next;
		ft_lstdelone(temp);
		temp = current;
	}
	*lst = NULL;
	return ;
}
