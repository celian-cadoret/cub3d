/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:20:29 by marvin            #+#    #+#             */
/*   Updated: 2024/09/11 10:20:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube3d_bonus.h"

long	get_current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	update_curr_asset(t_cube *cube)
{
	long	new;

	new = get_current_time();
	if (new - cube->last_time >= 900)
	{
		if (cube->i_texture >= cube->size_asst_e)
			cube->i_texture = 0;
		else
			cube->i_texture += 1;
		cube->last_time = new;
	}
}

void	time_to_play(t_cube *cube)
{
	long	new;

	new = get_current_time();
	if (new - cube->sound_oldt >= 13500)
	{
		playsound("loop", 0, 0, 0);
		cube->sound_oldt = new;
	}
}

void	gameover(t_cube *cube)
{
	cube->gameover = 1;
	playsound("screamer", 0, 0, 0);
	mlx_put_image_to_window(cube->mlx_ptr,
		cube->win_ptr, cube->screen[2].img, 0, 0);
	mlx_do_sync(cube->mlx_ptr);
	sleep(2);
	mlx_put_image_to_window(cube->mlx_ptr,
		cube->win_ptr, cube->screen[1].img, 0, 0);
}
