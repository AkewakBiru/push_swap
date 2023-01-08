/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:07:30 by abiru             #+#    #+#             */
/*   Updated: 2023/01/08 16:37:54 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				cost_a;
	int				cost_b;
	int				index;
	struct s_list	*next;
}	t_list;

long	ft_atol(const char *str);
t_list	*ft_lstnew(int content);
char	**ft_split(char const *s, char c);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
int		is_sorted(t_list **head);
int		ft_lstsize(t_list *lst);
void	swap(t_list **head);
void	push(t_list **head, t_list **head2);
void	rotate(t_list **head);
void	reverse_rotate(t_list **head);
#endif