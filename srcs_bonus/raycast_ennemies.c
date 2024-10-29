/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_ennemies.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 16:37:48 by marvin            #+#    #+#             */
/*   Updated: 2024/09/15 16:37:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube3d_bonus.h"

int	find_ennemies(t_cube *cube, int x, int y)
{
	int	i;

	i = -1;
	while (++i < cube->nb_ennemy)
		if ((int)cube->ennemies[i]->pos_y == y
			&& (int)cube->ennemies[i]->pos_x == x)
			return (i);
	return (-1);
}

void	calculate_sprite_params(t_cube *cube,
	t_raycasting *rc, t_enm *ennemy, int stripe)
{
	rc->sprite_x = ennemy->pos_x - cube->pos_x;
	rc->sprite_y = ennemy->pos_y - cube->pos_y;
	rc->inv_det = 1.0 / (cube->plane_x * cube->dir_y
			- cube->plane_y * cube->dir_x);
	rc->transform_x = rc->inv_det * (cube->dir_y
			* rc->sprite_x - cube->dir_x * rc->sprite_y);
	rc->transform_y = rc->inv_det * (-cube->plane_y
			* rc->sprite_x + cube->plane_x * rc->sprite_y);
	rc->sprite_screen_x = (int)(SCREEN_WIDTH / 2
			* (1 + rc->transform_x / rc->transform_y));
	rc->sprite_height = abs((int)(SCREEN_HEIGHT / rc->transform_y));
	rc->draw_start_y = -rc->sprite_height / 2 + SCREEN_HEIGHT / 2;
	if (rc->draw_start_y < 0)
		rc->draw_start_y = 0;
	rc->draw_end_y = rc->sprite_height / 2 + SCREEN_HEIGHT / 2;
	if (rc->draw_end_y >= SCREEN_HEIGHT)
		rc->draw_end_y = SCREEN_HEIGHT - 1;
	rc->sprite_width = abs((int)(SCREEN_HEIGHT / rc->transform_y));
	rc->draw_start_x = stripe;
	rc->draw_end_x = stripe + 1;
}

void	render_sprite(t_cube *cube, t_raycasting *rc, t_data *texture)
{
	if (rc->transform_y > 0 && rc->draw_start_x
		>= 0 && rc->draw_start_x < SCREEN_WIDTH)
	{
		rc->y = rc->draw_start_y;
		while (rc->y < rc->draw_end_y)
		{
			rc->d = (rc->y) * 256 - SCREEN_HEIGHT
				* 128 + rc->sprite_height * 128;
			rc->tex_y = ((rc->d * texture->height) / rc->sprite_height) / 256;
			rc->color = get_pixel_color(texture, rc->tex_x, rc->tex_y);
			if (rc->color != 0x00d100ff)
				my_mlx_pixel_put(cube->img, rc->draw_start_x, rc->y, rc->color);
			rc->y++;
		}
	}
}

void	draw_enemy(t_cube *cube, t_raycasting *rc, int stripe)
{
	t_data	*texture;
	t_enm	*ennemy;

	texture = &cube->assets_ennemies[cube->i_texture];
	ennemy = cube->ennemies[find_ennemies(cube, cube->map_x, cube->map_y)];
	calculate_sprite_params(cube, rc, ennemy, stripe);
	rc->tex_x = (int)(256 * (rc->draw_start_x
				- (-rc->sprite_width / 2 + rc->sprite_screen_x))
			* texture->width / rc->sprite_width) / 256;
	render_sprite(cube, rc, texture);
}
