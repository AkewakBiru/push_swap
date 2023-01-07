/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:12:27 by abiru             #+#    #+#             */
/*   Updated: 2023/01/07 13:15:20 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **head)
{
	t_list	*tmp;

	tmp = *head;
	while (tmp->next)
	{
		if (tmp->content >= tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
