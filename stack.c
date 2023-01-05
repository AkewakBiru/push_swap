#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list) * sizeof(int));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

// t_node	*create_node()
// {
// 	t_node *list = (t_node *)malloc(sizeof(t_node));
// 	if (!list)
// 		return (0);
// }

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
	return ;
}

void	push(t_node *list, t_node *new)
{
	
	if (!list)
		return ;
	while (list->next)
		list = list->next;
	list->next = new;
	new->next = NULL;
}

void pop(t_node *list)
{
	if (!list)
		return ;
	while (list->next->next)
		list = list->next;
	free(list->next);
	list->next = NULL;
}