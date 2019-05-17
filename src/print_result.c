/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 17:58:54 by vlegros           #+#    #+#             */
/*   Updated: 2019/01/25 18:00:10 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		print_result(char **matrix, int side)
{
	int		i;
	int		j;
	char	*output;
	int		coord[4];

	if (!(output = ft_strnew(side * side)))
		errors(2);
	ft_memset(output, '.', side * side);
	i = -1;
	while (matrix[++i])
	{
		find_coords(coord, matrix[i]);
		j = -1;
		while (++j < 4)
			output[coord[j]] = 'A' + i;
	}
	i = -1;
	while (output[++i])
	{
		if (!(i % side) && i != 0)
			ft_putchar('\n');
		ft_putchar(output[i]);
	}
	ft_putchar('\n');
	return (1);
}
