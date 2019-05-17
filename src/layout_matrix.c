/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 21:31:29 by vlegros           #+#    #+#             */
/*   Updated: 2019/01/24 22:56:00 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**failure(char ***matrix)
{
	ft_del_twodem_arr(matrix);
	return (NULL);
}

char	**matrix_creator(int *coord, int *temp_coord, char **matrix, int side)
{
	int i;
	int	d_dimension;

	i = 1;
	d_dimension = dim(coord, side);
	while (i < d_dimension)
	{
		while (horizontal_move_check(coord, side))
			if (!(matrix[i++] = new_hor_pos(coord, side)))
				return (failure(&matrix));
		if (vertical_move_check(coord, side))
		{
			if (!(matrix[i] = new_vert_pos(temp_coord, side)))
				return (failure(&matrix));
			find_coords(temp_coord, matrix[i]);
			find_coords(coord, matrix[i++]);
		}
	}
	matrix[i] = NULL;
	return (matrix);
}

char	**layout_matrix(char *element, int side)
{
	int		coord[4];
	int		temp_coord[4];
	char	*elem;
	char	**matrix;

	find_coords(coord, element);
	if (!(elem = realloc_elem(element, side, coord)))
		return (NULL);
	find_coords(coord, elem);
	find_coords(temp_coord, elem);
	if (!(matrix = (char**)malloc(sizeof(char*) * (dim(coord, side) + 1))))
		return (NULL);
	matrix[0] = elem;
	return (matrix_creator(coord, temp_coord, matrix, side));
}
