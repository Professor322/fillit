/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 18:48:00 by vlegros           #+#    #+#             */
/*   Updated: 2018/11/27 21:46:08 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t length;

	if (!s)
		return ;
	length = ft_strlen((const char*)s);
	if (!length)
		return ;
	while (length--)
		*s++ = '\0';
}
