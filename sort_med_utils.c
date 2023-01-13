/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_med_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:17:38 by abiru             #+#    #+#             */
/*   Updated: 2023/01/13 17:34:11 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_back(int j, t_list **stack_a)
{
	int	i;

	i = j;
	while (i != 0)
	{
		if (i < 0)
		{
			stack_a = rotate(stack_a);
			i++;
			if (i == 0)
				stack_a = rotate(stack_a);
		}
		else
		{
			stack_a = reverse_rotate(stack_a);
			i--;
		}
	}
}

int	arrange_a(t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while ((*stack_b)->cost_a)
	{
		if ((*stack_b)->cost_a < 0)
		{
			stack_a = reverse_rotate(stack_a);
			(*stack_b)->cost_a++;
			i--;
		}
		else
		{
			stack_a = rotate(stack_a);
			(*stack_b)->cost_a--;
			i++;
		}
	}
	return (i);
}
