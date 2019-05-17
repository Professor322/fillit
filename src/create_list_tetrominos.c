/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list_tetrominos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 18:46:21 by jziemann          #+#    #+#             */
/*   Updated: 2019/01/25 17:21:07 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int g_side;

int						ft_sqrt(int nb)
{
	int x;

	x = 1;
	if (nb == 1)
		return (1);
	while (x * x < nb)
		x++;
	return (x);
}

int						ft_max_matrix(int side, int counter)
{
	int sqrt;

	sqrt = ft_sqrt(2 * counter);
	return (side > sqrt ? side : sqrt);
}

static t_tetrominos		*create_element(int fd, int counter)
{
	t_tetrominos	*new;
	int				sqrt;

	sqrt = ft_sqrt(2 * counter);
	if (!(new = (t_tetrominos *)malloc(sizeof(t_tetrominos))))
		return (NULL);
	new->element = element_extraction(fd);
	new->max_side = maximum_side(new->element);
	if (counter >= 3)
	{
		new->layout_matrix = layout_matrix(new->element, sqrt);
		g_side = sqrt;
	}
	return (new);
}

void					ft_filling_layout_matrix(t_list *curr)
{
	int max;

	if (((t_tetrominos *)(curr->content))->max_side >
			((t_tetrominos *)((curr->next)->content))->max_side)
		max = ((t_tetrominos *)(curr->content))->max_side;
	else
		max = ((t_tetrominos *)((curr->next)->content))->max_side;
	g_side = max;
	while (curr)
	{
		((t_tetrominos *)(curr->content))->layout_matrix =
		layout_matrix(((t_tetrominos*)(curr->content))->element, max);
		curr = curr->next;
	}
}

t_list					*create_list_tetrominos(int fd, int counter)
{
	t_list			*head;
	t_tetrominos	*temp;
	t_list			*new;
	int				num;

	num = counter;
	if (!(temp = create_element(fd, counter)))
		return (NULL);
	if (!(head = ft_lstnew(temp, sizeof(t_tetrominos))))
		return (NULL);
	while (--num)
	{
		if (!(temp = create_element(fd, counter)))
			return (NULL);
		if (!(new = ft_lstnew(temp, sizeof(t_tetrominos))))
			return (NULL);
		ft_lst_addback(head, new);
	}
	if (counter == 2)
		ft_filling_layout_matrix(head);
	if (counter == 1 && (g_side = ((t_tetrominos *)(head->content))->max_side))
		((t_tetrominos *)(head->content))->layout_matrix =
layout_matrix(((t_tetrominos*)(head->content))->element,
((t_tetrominos *)(head->content))->max_side);
	return (head);
}
