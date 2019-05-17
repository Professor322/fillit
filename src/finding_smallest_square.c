/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_smallest_square.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 21:07:30 by vlegros           #+#    #+#             */
/*   Updated: 2019/01/25 18:06:41 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		element_check(char **board, char *elem)
{
	int i;
	int j;

	i = -1;
	while (board[++i])
	{
		j = -1;
		while (elem[++j])
		{
			if (board[i][j] == '1')
				if (board[i][j] == elem[j])
					return (0);
		}
	}
	return (1);
}

char	*place_element(char *matrix, char *variant)
{
	if (!(matrix = ft_strdup(variant)))
		errors(2);
	return (matrix);
}

int		solution(t_list *temp, char **matrix)
{
	int		i;
	int		j;
	char	**variants;

	i = -1;
	variants = ((t_tetrominos *)((temp)->content))->layout_matrix;
	while (variants[++i])
	{
		j = 0;
		while (matrix[j])
			j++;
		if (element_check(matrix, variants[i]))
		{
			matrix[j] = place_element(matrix[j], variants[i]);
			if (!temp->next)
				return (1);
			else
			{
				if (solution(temp->next, matrix))
					return (1);
				ft_strdel(&matrix[j]);
			}
		}
	}
	return (0);
}

int		enlarge_layout_matrix(t_list *head, int side)
{
	t_list *temp;

	temp = head;
	while (temp)
	{
		ft_del_twodem_arr(&((t_tetrominos *)((temp)->content))->layout_matrix);
		if (!(((t_tetrominos *)((temp)->content))->layout_matrix =
			layout_matrix(((t_tetrominos *)((temp)->content))->element, side)))
			return (0);
		temp = temp->next;
	}
	return (1);
}

int		finding_smallest_square(int counter, int side, t_list *head)
{
	char	**sol_matrix;
	int		i;

	if (!(sol_matrix = (char**)malloc(sizeof(char*) * (counter + 1))))
		errors(2);
	i = -1;
	while (++i < counter)
		sol_matrix[i] = NULL;
	sol_matrix[i] = NULL;
	while (!solution(head, sol_matrix))
		if (!enlarge_layout_matrix(head, ++side))
			errors(2);
	print_result(sol_matrix, side);
	return (1);
}
