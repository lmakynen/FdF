/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:52:34 by lmakynen          #+#    #+#             */
/*   Updated: 2020/09/08 20:17:16 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** First we count the height (z0 and z1) for both coordinate points.
** If zoom has been used, we count the new coordinates using scale
** (the program does this anyways but the scale stays the same unless
** zoom has been used). If the projection is isometric, we count the
** new isometric coordinate points. Then we set the temporary coordinates
** to the ones we have counted. After that we use Bresenham's line algorithm
** which draws the line between start point and end point (pixel by pixel).
*/

void	isometric(t_env *env)
{
	int	previous_x;
	int	previous_y;

	previous_x = env->x0;
	previous_y = env->y0;
	env->x0 = (previous_x - previous_y) * cos(0.523599);
	env->y0 = -(env->z0) + (previous_x + previous_y) * sin(0.523599);
	previous_x = env->x1;
	previous_y = env->y1;
	env->x1 = (previous_x - previous_y) * cos(0.523599);
	env->y1 = -(env->z1) + (previous_x + previous_y) * sin(0.523599);
}

void	bresenhams(t_env *env, t_temp *temp)
{
	env->dx = ft_abs(temp->x1 - temp->x0);
	env->dir_x = (temp->x0 < temp->x1) ? 1 : -1;
	env->dy = -ft_abs(temp->y1 - temp->y0);
	env->dir_y = (temp->y0 < temp->y1) ? 1 : -1;
	env->err = env->dx + env->dy;
	while (1)
	{
		mlx_pixel_put(env->mlx, env->win, (temp->x0 + env->start_x),
				(temp->y0 + env->start_y), env->color);
		if (temp->x0 == temp->x1 && temp->y0 == temp->y1)
			break ;
		env->err2 = 2 * env->err;
		if (env->err2 >= env->dy)
		{
			env->err += env->dy;
			temp->x0 += env->dir_x;
		}
		if (env->err2 <= env->dx)
		{
			env->err += env->dx;
			temp->y0 += env->dir_y;
		}
	}
}

void	count_with_coordinates(t_env *env, t_temp temp)
{
	env->z0 = env->map[temp.y0][temp.x0] * env->alt;
	env->z1 = env->map[temp.y1][temp.x1] * env->alt;
	env->x0 = temp.x0 * env->scale;
	env->x1 = temp.x1 * env->scale;
	env->y0 = temp.y0 * env->scale;
	env->y1 = temp.y1 * env->scale;
	if (env->projection == 'I')
		isometric(env);
	temp.x0 = env->x0;
	temp.y0 = env->y0;
	temp.x1 = env->x1;
	temp.y1 = env->y1;
	bresenhams(env, &temp);
}
