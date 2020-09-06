/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 18:35:32 by lmakynen          #+#    #+#             */
/*   Updated: 2020/09/06 18:21:00 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Allocates memory for the map and checks that all the rows are the same size.
** Then the program fills in the map with the values we get from the file (it
** changes them from characters to integers). The filling of the map happens
** row by row.
*/

int			arrlen(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void		create_map(char *line, int row, t_env *env)
{
	char	**arr;
	int		i;
	int		x;

	i = 0;
	x = 0;
	arr = ft_strsplit(line, ' ');
	free(line);
	x = arrlen(arr);
	while (arr[i] && (i < x))
	{
		env->map[row][i] = ft_atoi(arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
}

int			count_columns(char *line, t_env *env, int row)
{
	int		column;

	column = 0;
	if (row == 0)
	{
		env->max_x = ft_wordcount(line, ' ');
		return (0);
	}
	else
		column = ft_wordcount(line, ' ');
	if (env->max_x != column)
		return (2);
	return (0);
}

void		read_file(int fd, t_env *env)
{
	char	*line;
	int		row;

	line = NULL;
	row = 0;
	if (!(env->map = (int**)malloc(sizeof(int*) * (env->max_y))))
		errors(2);
	while ((get_next_line(fd, &line)) == 1)
	{
		if ((count_columns(line, env, row)) == 2)
			errors(3);
		if (!(env->map[row] = (int*)malloc(sizeof(int) * (env->max_x))))
			errors(2);
		create_map(line, row, env);
		row++;
	}
}
