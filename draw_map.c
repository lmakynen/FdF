/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:52:34 by lmakynen          #+#    #+#             */
/*   Updated: 2020/09/06 20:46:17 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	count_with_coordinates(t_env *env, t_temp temp)
{
	env->z0 = env->map[temp].y0][temp].x0] * env->altitude;
	env->z1 = env->map[temp].y1][temp].x1] * env->altitude;
	env->x0 =[temp].x0 * env->zoom;
	env->x1 =[temp].x1 * env->zoom;;
	env->y0 =[temp].y0 * env->zoom;;
	env->y1 =[temp].y1 * env->zoom;;
//	if (env->pers == 'I')
//	{
//		isometric(env, 1);
//		isometric(env, 2);
//	}
[temp].x0 = env->x0;
[temp].y0 = env->y0;
[temp].x1 = env->x1;
[temp].y1 = env->y1;
//	draw_pixel(env,[temp]);
}
