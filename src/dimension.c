/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimension.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:14:44 by vlegros           #+#    #+#             */
/*   Updated: 2019/01/23 17:34:28 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		dim(int *coord, int side)
{
	int	max_i;
	int	max_j;
	int	i;

	max_i = 0;
	max_j = 0;
	i = -1;
	while (++i < 4)
	{
		if (coord[i] % side > max_j)
			max_j = coord[i] % side;
		if (coord[i] / side > max_i)
			max_i = coord[i] / side;
	}
	return ((side - max_j) * (side - max_i));
}
