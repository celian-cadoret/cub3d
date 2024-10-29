/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_doors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:53:30 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 11:06:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube3d_bonus.h"

t_data	*obj_text_rec(t_cube *cube, char c)
{
	t_data	*temp;

	if (c == 'O')
		temp = &cube->doors[0];
	else if (c == 'C')
		temp = &cube->doors[3];
	else
		temp = &cube->assets_ennemies[cube->i_texture];
	return (temp);
}

int	raycasting_hit_d(t_cube *cube)
{
	while (cube->hit == 0)
	{
		if (cube->sidedist_x < cube->sidedist_y)
		{
			cube->sidedist_x += cube->deltadist_x;
			cube->map_x += cube->step_x;
			cube->side = 0;
		}
		else
		{
			cube->sidedist_y += cube->deltadist_y;
			cube->map_y += cube->step_y;
			cube->side = 1;
		}
		if (cube->map[cube->map_y][cube->map_x] == '1')
			cube->hit = 1;
		if (cube->map[cube->map_y][cube->map_x] == 'C'
			|| cube->map[cube->map_y][cube->map_x] == 'O')
			return (cube->hit = 1, 1);
		if (is_enemy_there(cube, cube->map_x, cube->map_y))
			return (cube->hit = 1, 2);
	}
	return (0);
}

void	raycast_putpix_d(t_cube *cube, t_raycasting *rc, int cond)
{
	if (cond == 2)
		return (draw_enemy(cube, rc, rc->x));
	if (cond == 0)
		return ;
	rc->y = cube->drawstart - 1;
	if (cube->side == 0)
		rc->wallx = cube->pos_y + cube->perp_wall_dist * cube->raydir_y;
	else
		rc->wallx = cube->pos_x + cube->perp_wall_dist * cube->raydir_x;
	rc->wallx -= floor(rc->wallx);
	rc->temp = obj_text_rec(cube, cube->map[cube->map_y][cube->map_x]);
	rc->tex_x = (int)(rc->wallx * (double)(rc->temp->width));
	if ((cube->side == 0 && cube->raydir_x < 0)
		|| (cube->side == 1 && cube->raydir_y > 0))
		rc->tex_x = rc->temp->width - rc->tex_x - 1;
	while (++rc->y < cube->drawend)
	{
		rc->d = rc->y * 256 - SCREEN_HEIGHT * 128 + cube->line_height * 128;
		rc->tex_y = ((rc->d * rc->temp->height) / cube->line_height) / 256;
		rc->color = get_pixel_color(rc->temp, rc->tex_x, rc->tex_y);
		if (cond == 1 && rc->color != 0x00d100ff)
			my_mlx_pixel_put(cube->img, rc->x, rc->y, rc->color);
	}
}

void	raycasting_doors(t_cube *cube)
{
	t_raycasting	rc;
	int				tp;

	rc.x = -1;
	while (++rc.x < SCREEN_WIDTH)
	{
		raycasting_init1(cube, rc.x);
		raycasting_sidedist(cube);
		tp = rayc_rec(cube, &rc);
		raycasting_draw(cube);
		raycast_putpix_d(cube, &rc, tp);
	}
	mlx_put_image_to_window(cube->mlx_ptr, cube->win_ptr, cube->img->img, 0, 0);
	minimap(cube);
}
