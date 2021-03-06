/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 15:47:17 by vlegros           #+#    #+#             */
/*   Updated: 2018/12/09 17:24:52 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vec	*ft_vec_init(size_t size)
{
	t_vec *temp;

	if ((temp = (t_vec*)malloc(sizeof(t_vec))))
	{
		if ((temp->data = ft_memalloc(size)))
		{
			ft_memset(temp->data, '\0', size);
			temp->capacity = size;
			temp->data_tail = temp->data;
		}
		else
		{
			temp->capacity = 0;
			temp->data_tail = NULL;
		}
	}
	return (temp);
}
