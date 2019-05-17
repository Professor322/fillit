/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_side.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 21:27:42 by jziemann          #+#    #+#             */
/*   Updated: 2019/01/23 15:25:14 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		maximum_side(char *el)
{
	if (el[0] == '1')
	{
		if ((el[0] & el[1] & el[2] & el[3]) == '1' ||
			(el[0] & el[4] & el[8] & el[12] == '1'))
			return (4);
		if ((el[0] & el[1] & el[4] & el[5]) == '1')
			return (2);
	}
	return (3);
}
