/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 15:42:29 by lmakynen          #+#    #+#             */
/*   Updated: 2020/09/08 20:29:48 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Opens the map file and fills in the struct a bit. After that
** the program counts the rows (max y) using get_next_line.
** Then it sends the map file and struct forward. This file also
** contains the error messages. Quite simple :)
*/

int				errors(int i)
{
	if (i == 1)
		ft_putstr_fd("Opening the file failed\n", 2);
	else if (i == 2)
		ft_putstr_fd("Error with malloc\n", 2);
	else if (i == 3)
		ft_putstr_fd("Invalid map\n", 2);
	else if (i == 4)
		ft_putstr_fd("Invalid map, doesn't have any content\n", 2);
	exit(1);
}

void			make_struct(t_env *env)
{
	env->start_x = 400;
	env->start_y = 400;
	env->color = 0xFFFFFF;
	env->projection = 'I';
	env->alt = 1;
	env->scale = 15;
}

void			count_rows(int fd, t_env *env)
{
	char		*line;
	int			rows;

	line = NULL;
	rows = 0;
	while ((get_next_line(fd, &line)) == 1)
	{
		free(line);
		rows++;
	}
	env->max_y = rows;
	if (rows == 0)
		errors(4);
}

int				main(int argc, char **argv)
{
	int			fd;
	t_env		env;

	if (argc == 2)
	{
		if (!(fd = open(argv[1], O_RDONLY)))
			errors(1);
		make_struct(&env);
		count_rows(fd, &env);
		close(fd);
		if (!(fd = open(argv[1], O_RDONLY)))
			errors(1);
		read_file(fd, &env);
		create_window(&env);
		return (0);
	}
	ft_putstr("usage: ./fdf <file>\n");
	exit(0);
}
