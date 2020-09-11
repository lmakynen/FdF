/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmakynen <lmakynen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:18:53 by lmakynen          #+#    #+#             */
/*   Updated: 2020/09/11 21:37:37 by lmakynen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_start(int keycode, t_env *env)
{
	if (keycode == 123)
	{
		env->start_x -= 20;
		mlx_clear_window(env->mlx, env->win);
		put_info(env);
	}
	if (keycode == 124)
	{
		env->start_x += 20;
		mlx_clear_window(env->mlx, env->win);
		put_info(env);
	}
	if (keycode == 126)
	{
		env->start_y -= 20;
		mlx_clear_window(env->mlx, env->win);
		put_info(env);
	}
	if (keycode == 125)
	{
		env->start_y += 20;
		mlx_clear_window(env->mlx, env->win);
		put_info(env);
	}
}

void	change_color(int keycode, t_env *env)
{
	if (keycode == 5)
	{
		env->color = 0x00FF00;
		mlx_clear_window(env->mlx, env->win);
		put_info(env);
	}
	if (keycode == 11)
	{
		env->color = 0x0000FF;
		mlx_clear_window(env->mlx, env->win);
		put_info(env);
	}
	if (keycode == 15)
	{
		env->color = 0xFF0000;
		mlx_clear_window(env->mlx, env->win);
		put_info(env);
	}
}

void	change_zoom(int keycode, t_env *env)
{
	if (keycode == 78)
	{
		if (env->scale > 1)
		{
			env->scale /= 2;
			mlx_clear_window(env->mlx, env->win);
			put_info(env);
		}
	}
	if (keycode == 69)
	{
		if (env->scale < 1000)
		{
			env->scale *= 2;
			mlx_clear_window(env->mlx, env->win);
			put_info(env);
		}
	}
}

void	change_projection(int keycode, t_env *env)
{
	if (keycode == 35)
	{
		if (env->projection != 'P')
		{
			env->projection = 'P';
			mlx_clear_window(env->mlx, env->win);
			put_info(env);
		}
	}
	if (keycode == 34)
	{
		if (env->projection != 'I')
		{
			env->projection = 'I';
			mlx_clear_window(env->mlx, env->win);
			put_info(env);
		}
	}
}

int		get_events(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 36)
	{
		make_struct(env);
		mlx_clear_window(env->mlx, env->win);
		put_info(env);
	}
	if (keycode == 83)
	{
		env->alt--;
		mlx_clear_window(env->mlx, env->win);
		put_info(env);
	}
	if (keycode == 84)
	{
		env->alt++;
		mlx_clear_window(env->mlx, env->win);
		put_info(env);
	}
	change_projection(keycode, env);
	change_zoom(keycode, env);
	change_color(keycode, env);
	change_start(keycode, env);
	return (0);
}
