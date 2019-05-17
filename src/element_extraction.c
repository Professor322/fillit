/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_extraction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 23:05:53 by vlegros           #+#    #+#             */
/*   Updated: 2019/01/25 17:49:07 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*element_extraction(int fd)
{
	int		rd;
	char	buff[21];
	char	*element;

	element = NULL;
	if ((rd = read(fd, buff, 21)))
	{
		rd == 21 ? (buff[rd - 1] = '\0')
				: (buff[rd] = '\0');
		if (!(element = element_creation(buff)))
			return (NULL);
	}
	element_converter(element);
	return (element);
}
