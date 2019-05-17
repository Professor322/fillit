/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jziemann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 20:48:41 by jziemann          #+#    #+#             */
/*   Updated: 2019/01/24 23:07:46 by jziemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_free_list(t_list **begin_list)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *begin_list;
	if (!temp1)
		return ;
	while (temp1)
	{
		temp2 = temp1->next;
		ft_strdel(&(((t_tetrominos *)(temp1->content))->element));
		ft_del_twodem_arr(&(((t_tetrominos *)(temp1->content))->layout_matrix));
		free(temp1);
		temp1 = temp2;
	}
	*begin_list = 0;
}
