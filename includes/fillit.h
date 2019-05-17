/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:43:21 by vlegros           #+#    #+#             */
/*   Updated: 2019/01/25 18:00:08 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# define __HOR_CHECK__(i,x,y) i >= x && i <= y

extern int				g_side;

typedef	struct			s_tetrominos
{
	int					max_side;
	char				*element;
	char				**layout_matrix;
}						t_tetrominos;

int						valid_check(char *path);

char					*element_extraction(int fd);
char					*element_creation(char *buff);
void					element_converter(char *element);
int						maximum_side(char *el);

char					**layout_matrix(char *element, int side);
char					*new_vert_pos(int *coord, int side);
char					*new_hor_pos(int *coord, int side);
int						vertical_move_check(int *coord, int side);
int						horizontal_move_check(int *coord, int side);
char					*realloc_elem(char *element, int side, int *coord);
int						dim(int *coord, int side);
void					find_coords(int *coord, char *element);

t_list					*create_list_tetrominos(int fd, int counter);
int						finding_smallest_square(int counter, int side,
						t_list *head);
void					ft_free_list(t_list **begin_list);
void					errors(int num);
int						print_result(char **matrix, int side);
#endif
