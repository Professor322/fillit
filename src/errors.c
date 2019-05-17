/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 23:01:55 by vlegros           #+#    #+#             */
/*   Updated: 2019/01/25 17:34:47 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	errors(int num)
{
	if (num == 1)
	{
		ft_putstr("usage: ./fillit source_file\n");
		exit(0);
	}
	else if (num == 2)
	{
		ft_putstr("error\n");
		exit(0);
	}
}
