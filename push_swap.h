/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 01:07:30 by abiru             #+#    #+#             */
/*   Updated: 2023/01/13 19:27:24 by abiru            ###   ########.fr       */
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
	int				flag;
	int				id;
	struct s_list	*next;
}	t_list;

typedef struct s_ints
{
	int	*arr;
	int	bit_num;
	int	max_dig;
}	t_ints;

long	ft_atol(const char *str);
t_list	*ft_lstnew(int content);
char	**ft_split(char const *s, char c);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
int		is_sorted(t_list **head);
void	swap(t_list **head);
void	push(t_list **head, t_list **head2, int flag);
t_list	**rotate(t_list **head);
t_list	**reverse_rotate(t_list **head);
int		sort_nums(t_list	**head, int size, int *arr);
void	sort_medium(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **head);
int		check_validity(char **arg, int ac);
int		check_dup(t_list **head);
void	check_nums(t_list **head, char **av, int ac);
void	error_msg(char *msg);
void	free_arr(char **lst);
size_t	ft_strlen(const char *s);
int		arrange_a(t_list **stack_a, t_list **stack_b);
void	put_back(int i, t_list **stack_a);
#endif