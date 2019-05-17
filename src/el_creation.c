/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   el_creation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:01:42 by jziemann          #+#    #+#             */
/*   Updated: 2019/01/21 21:02:55 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*element_creation(char *buff)
{
	int		i;
	int		j;
	char	*element;

	if (!(element = ft_strnew(16)))
		return (NULL);
	i = -1;
	j = -1;
	while (buff[++i])
	{
		if (!((i + 1) % 5))
			continue ;
		element[++j] = buff[i];
	}
	return (element);
}
