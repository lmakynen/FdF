/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 18:35:32 by lmakynen          #+#    #+#             */
/*   Updated: 2020/09/04 20:40:43 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* int			arrlen(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int			*create_map(char *line, int row, t_env *env)
{
	char	**arr;
	int		i;
	int		xmax;

	i = 0;
	xmax = 0;
	arr = ft_strsplit(line, ' ');
	free(line);
	xmax = arrlen(arr);
	while (arr[i] && (i < xmax))
	{
		env->map[max_y][i] = ft_atoi(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
} */

int			count_columns(char *line, t_env *env, int row)
{
	int		column;

	column = 0;
	if (row == 0)
		env->max_x = ft_wordcount(line, ' ');
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
		if (!(env->map[max_y] = (int*)malloc(sizeof(int) * (env->max_x))))
			errors(2);
	//	if (!(env->map[max_y] = create_map(line, row, env)) == NULL)
	}
}
