/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 16:43:19 by lmakynen          #+#    #+#             */
/*   Updated: 2020/09/04 20:46:40 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/includes/libft.h"

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				**map;
	int				alt;
	int				projection;
	unsigned long	color;
	int				scale;
	int				start_x;
	int				start_y;
	int				max_x;
	int				max_y;
	int				x0;
	int				x1;
	int				y0;
	int				y1;
	int				dx;
	int				dy;
	int				err;
	int				err2;
	int				dir_x;
	int				dir_y;
}					t_env;

int					main(int argc, char **argv);
int					errors(int i);
int					count_columns(char *line, t_env *env, int row);

void				count_rows(int fd, t_env *env);
void				make_struct(t_env *env);
void				read_file(int fd, t_env *env);

#endif
