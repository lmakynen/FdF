/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 16:43:19 by lmakynen          #+#    #+#             */
/*   Updated: 2020/09/11 21:37:58 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# include "libft/includes/libft.h"

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				**map;
	int				alt;
	char			projection;
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
	int				z0;
	int				z1;
	int				err;
	int				err2;
	int				dir_x;
	int				dir_y;
}					t_env;

typedef struct		s_temp
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
}					t_temp;

int					main(int argc, char **argv);
int					errors(int i);
int					count_columns(char *line, t_env *env, int row);
int					get_events(int keycode, t_env *env);
int					arrlen(char **arr);
int					destroy(t_env *env);
int					get_events(int keycode, t_env *env);

void				count_rows(int fd, t_env *env);
void				make_struct(t_env *env);
void				read_file(int fd, t_env *env);
void				create_window(t_env *env);
void				put_info(t_env *env);
void				check_coordinates(t_env *env, int x, int y);
void				count_with_coordinates(t_env *env, t_temp temp);
void				bresenhams(t_env *env, t_temp *temp);
void				isometric(t_env *env);
void				start_drawing(t_env *env);
void				change_projection(int keycode, t_env *env);
void				change_zoom(int keycode, t_env *env);
void				change_color(int keycode, t_env *env);
void				change_start(int keycode, t_env *env);

#endif
