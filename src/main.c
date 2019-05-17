/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:46:20 by vlegros           #+#    #+#             */
/*   Updated: 2019/01/24 23:25:23 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		count_elem;
	int		fd;
	t_list	*head;

	if (argc != 2)
		errors(1);
	if (!(count_elem = valid_check(argv[1])))
		errors(2);
	fd = open(argv[1], O_RDONLY);
	if (!(head = create_list_tetrominos(fd, count_elem)))
		errors(2);
	finding_smallest_square(count_elem, g_side, head);
	ft_free_list(&head);
	return (0);
}
