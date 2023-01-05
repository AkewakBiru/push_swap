/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:07:30 by abiru             #+#    #+#             */
/*   Updated: 2023/01/02 13:02:02 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

// typedef struct Node {
// 	int data;
// 	struct Node *next;
// 	struct Node *prev;
// } t_node;

long	ft_atol(const char *str);
t_list	*ft_lstnew(int content);
#endif