/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:45:48 by vlegros           #+#    #+#             */
/*   Updated: 2019/01/25 20:23:13 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_links(char *buff, int i)
{
	int counter;
	int	low_point;
	int	high_point;

	counter = 0;
	low_point = 0;
	high_point = 3;
	while (low_point <= 15 && high_point <= 18)
	{
		if (__HOR_CHECK__(i, low_point, high_point))
			break ;
		low_point += 5;
		high_point += 5;
	}
	if (i - 1 >= low_point && buff[i - 1] == '#')
		counter++;
	if (i + 1 <= high_point && buff[i + 1] == '#')
		counter++;
	if (i - 5 >= 0 && buff[i - 5] == '#')
		counter++;
	if (i + 5 <= 18 && buff[i + 5] == '#')
		counter++;
	return (counter);
}

int		valid_tetrimino_check(char *buff)
{
	int		i;
	int		link_counter;
	int		tetr_counter;

	link_counter = 0;
	tetr_counter = 0;
	i = -1;
	while (++i < 20)
	{
		if (!((i + 1) % 5))
			continue ;
		if (buff[i] == '#')
		{
			link_counter += count_links(buff, i);
			tetr_counter++;
		}
	}
	return ((link_counter >= 6 && link_counter <= 8) && tetr_counter == 4 ?
				1 : 0);
}

int		valid_filling_check(int rd, char *buff)
{
	int		i;

	i = -1;
	if (rd != 20 && rd != 21)
		return (0);
	while (++i < rd)
	{
		if (!((i + 1) % 5))
		{
			if (buff[i] != '\n')
				return (0);
			i++;
		}
		if (buff[i] != '.' && buff[i] != '#')
		{
			if (rd == 21 && i == 20 && buff[i] == '\n')
				break ;
			if (rd == 20 && i == 20)
				break ;
			return (0);
		}
	}
	return (1);
}

int		valid_check(char *path)
{
	char	buff[21];
	int		fd;
	int		rd;
	int		flag;
	int		counter;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	flag = 0;
	counter = 0;
	while ((rd = read(fd, buff, 21)))
	{
		if (rd == 20)
			flag = 1;
		if (!valid_filling_check(rd, buff))
			return (0);
		if (!valid_tetrimino_check(buff))
			return (0);
		counter++;
	}
	close(fd);
	return (flag && counter <= 26 ? counter : 0);
}
