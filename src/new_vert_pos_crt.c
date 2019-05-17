/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_vert_pos_crt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:08:34 by vlegros           #+#    #+#             */
/*   Updated: 2019/01/23 17:42:54 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*new_vert_pos(int *coord, int side)
{
	int		i;
	char	*new_elem;

	if (!(new_elem = ft_strnew(side * side)))
		return (NULL);
	ft_memset(new_elem, '0', side * side);
	i = -1;
	while (++i < 4)
	{
		new_elem[coord[i] + side] = '1';
		coord[i] += side;
	}
	return (new_elem);
}

int		vertical_move_check(int *coord, int side)
{
	int i;
	int	counter;

	i = -1;
	counter = 0;
	while (++i < 4)
		if (coord[i] + side <= side * side - 1)
			counter++;
	return (counter == 4 ? 1 : 0);
}
