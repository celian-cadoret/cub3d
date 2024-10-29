/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycloop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 11:06:19 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 11:06:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube3d_bonus.h"

void	save_rayc_values(t_cube *cube, int temp[3], double tmp[4])
{
	temp[1] = cube->map_x;
	temp[2] = cube->map_y;
	temp[3] = cube->side;
	tmp[1] = cube->sidedist_x;
	tmp[2] = cube->sidedist_y;
	tmp[3] = cube->deltadist_x;
	tmp[4] = cube->deltadist_y;
}

void	restore_rayc_values(t_cube *cube, int temp[3], double tmp[4])
{
	cube->map_x = temp[1];
	cube->map_y = temp[2];
	cube->side = temp[3];
	cube->sidedist_x = tmp[1];
	cube->sidedist_y = tmp[2];
	cube->deltadist_x = tmp[3];
	cube->deltadist_y = tmp[4];
}

int	rayc_rec(t_cube *cube, t_raycasting *rc)
{
	int		n;
	int		temp[3];
	double	tmp[4];

	cube->hit = 0;
	n = raycasting_hit_d(cube);
	save_rayc_values(cube, temp, tmp);
	if (n > 0)
	{
		rayc_rec(cube, rc);
		restore_rayc_values(cube, temp, tmp);
		raycasting_draw(cube);
		raycast_putpix_d(cube, rc, n);
	}
	return (n);
}
