/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_hor_pos_crt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:10:22 by vlegros           #+#    #+#             */
/*   Updated: 2019/01/23 17:17:07 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		horizontal_move_check(int *coord, int side)
{
	int high_point;
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (++i < 4)
	{
		high_point = -1;
		while (coord[i] > high_point)
			high_point += side;
		if (coord[i] + 1 <= high_point)
			counter++;
	}
	return (counter == 4 ? 1 : 0);
}

char	*new_hor_pos(int *coord, int side)
{
	int		i;
	char	*new_elem;

	if (!(new_elem = ft_strnew(side * side)))
		return (NULL);
	ft_memset(new_elem, '0', side * side);
	i = -1;
	while (++i < 4)
	{
		new_elem[coord[i] + 1] = '1';
		coord[i] += 1;
	}
	return (new_elem);
}
