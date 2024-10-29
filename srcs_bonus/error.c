/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 17:31:42 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 13:20:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube3d_bonus.h"

int	the_end_error(t_cube *cube)
{
	free(cube->error);
	if (cube->cn == 1)
		free(cube->n);
	if (cube->cs == 1)
		free(cube->s);
	if (cube->ce == 1)
		free(cube->e);
	if (cube->cw == 1)
		free(cube->w);
	if (cube->map)
		free_tab((void **)cube->map);
	mlx_destroy_image(cube->mlx_ptr, cube->screen[0].img);
	mlx_destroy_image(cube->mlx_ptr, cube->img->img);
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	if (cube->mlx_ptr)
		mlx_destroy_display(cube->mlx_ptr);
	mlx_loop_end(cube->mlx_ptr);
	free(cube->mlx_ptr);
	exit(1);
}

void	the_end_error_img2(t_cube *cube)
{
	if (cube->cn == 1)
		free(cube->n);
	if (cube->cs == 1)
		free(cube->s);
	if (cube->ce == 1)
		free(cube->e);
	if (cube->cw == 1)
		free(cube->w);
	if (cube->map)
		free_tab((void **)cube->map);
}

int	the_end_error_img(t_cube *cube, int i)
{
	printf("Error :img\n");
	free(cube->error);
	the_end_error_img2(cube);
	if (i > 3)
		destroy_img(cube);
	else
	{
		if (i > 0)
			mlx_destroy_image(cube->mlx_ptr, cube->assets[0].img);
		if (i > 1)
			mlx_destroy_image(cube->mlx_ptr, cube->assets[1].img);
		if (i > 2)
			mlx_destroy_image(cube->mlx_ptr, cube->assets[2].img);
	}
	mlx_destroy_image(cube->mlx_ptr, cube->img->img);
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	if (cube->mlx_ptr)
		mlx_destroy_display(cube->mlx_ptr);
	mlx_loop_end(cube->mlx_ptr);
	free(cube->mlx_ptr);
	exit(1);
}
