/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:12:52 by vlegros           #+#    #+#             */
/*   Updated: 2019/01/25 17:49:25 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*realloc_elem(char *element, int side, int *coord)
{
	char	*new_elem;
	int		difference;
	int		i;

	if ((int)ft_strlen(element) == side * side)
		return (ft_strdup(element));
	if (!(new_elem = ft_strnew(side * side)))
		return (NULL);
	ft_memset(new_elem, '0', side * side);
	difference = side - 4;
	i = -1;
	while (++i < 4)
		if (coord[i] >= 4 && coord[i] <= 7)
			new_elem[coord[i] + difference] = '1';
		else if (coord[i] >= 8 && coord[i] <= 11)
			new_elem[coord[i] + difference * 2] = '1';
		else if (coord[i] >= 12)
			new_elem[coord[i] + difference * 3] = '1';
		else
			new_elem[coord[i]] = '1';
	return (new_elem);
}
