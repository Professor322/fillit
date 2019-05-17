/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_and_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:00:24 by jziemann          #+#    #+#             */
/*   Updated: 2019/01/25 17:50:39 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	vertical_move(int *coord, char *element)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (++i < 4)
		if (coord[i] - 4 >= 0)
			counter++;
	if (counter == 4)
	{
		i = -1;
		while (++i < 4)
		{
			element[coord[i] - 4] = element[coord[i]];
			element[coord[i]] = '0';
			coord[i] -= 4;
		}
		return (vertical_move(coord, element));
	}
}

void	horizontal_move(int *coord, char *element)
{
	int	i;
	int low_point;
	int	counter;

	i = -1;
	counter = 0;
	while (++i < 4)
	{
		low_point = 12;
		while (coord[i] < low_point)
			low_point -= 4;
		if (coord[i] - 1 >= low_point)
			counter++;
	}
	if (counter == 4)
	{
		i = -1;
		while (++i < 4)
		{
			element[coord[i] - 1] = element[coord[i]];
			element[coord[i]] = '0';
			coord[i] -= 1;
		}
		return (horizontal_move(coord, element));
	}
}

void	element_converter(char *element)
{
	int	i;
	int	j;
	int	coord[4];

	i = -1;
	j = -1;
	while (element[++i])
		if (element[i] == '#')
		{
			element[i] = '1';
			coord[++j] = i;
		}
		else
			element[i] = '0';
	vertical_move(coord, element);
	horizontal_move(coord, element);
}
