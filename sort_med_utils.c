/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_med_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiru <abiru@student.42abudhabi.ae>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:17:38 by abiru             #+#    #+#             */
/*   Updated: 2023/01/12 21:18:30 by abiru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_back(int i, t_list **stack_a)
{
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

void	arrange_b(int i, t_list **stack_a, t_list **stack_b)
{
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
}
