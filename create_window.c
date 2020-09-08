/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 18:51:55 by lmakynen          #+#    #+#             */
/*   Updated: 2020/09/08 20:17:49 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Creates the window and writes instructions there. The counting
** begins here. First we have a while loop which continues until we
** have gone through every single coordinate. Then we get the
** current coordinates and the next ones.
*/

void		check_coordinates(t_env *env, int x, int y)
{
	t_temp	temp;

	temp.x0 = x;
	temp.y0 = y;
	if (x < env->max_x - 1)
	{
		temp.x1 = x + 1;
		temp.y1 = y;
		count_with_coordinates(env, temp);
	}
	if (y < env->max_y - 1)
	{
		temp.x1 = x;
		temp.y1 = y + 1;
		count_with_coordinates(env, temp);
	}
}

void		start_drawing(t_env *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->max_y)
	{
		x = 0;
		while (x < env->max_x)
		{
			check_coordinates(env, x, y);
			x++;
		}
		y++;
	}
}

void		put_info(t_env *env)
{
	mlx_string_put(env->mlx, env->win, 50, 50, 0xFF007F, "ESC = EXIT");
	mlx_string_put(env->mlx, env->win, 50, 70, 0x66FF66,
			"R, G, B = CHANGE COLOR");
	mlx_string_put(env->mlx, env->win, 50, 90, 0x66FF66,
			"BACKSPACE = RESET");
	mlx_string_put(env->mlx, env->win, 50, 110, 0x66FF66,
			"1 and 2 = ZOOM IN AND OUT");
	mlx_string_put(env->mlx, env->win, 50, 130, 0x66FF66,
			"I and P = CHANGE PROJECTION");
	mlx_string_put(env->mlx, env->win, 50, 150, 0x66FF66,
			"+ and - = CHANGE ALTITUDE");
	start_drawing(env);
}

void		create_window(t_env *env)
{
	if ((env->mlx = mlx_init()) == NULL)
		exit(1);
	env->win = mlx_new_window(env->mlx, 1000, 1000, "FdF");
	put_info(env);
	//mlx_key_hook(env->win, get_events, env);
	mlx_loop(env->mlx);
}
