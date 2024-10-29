/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemie3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:50:24 by marvin            #+#    #+#             */
/*   Updated: 2024/09/12 15:50:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube3d_bonus.h"

double	calcul_newposx_en(int dir, t_cube *cube, double moveSpeed, int nb)
{
	if (dir == 0)
		return (cube->ennemies[nb]->pos_x);
	else if (dir == 1)
		return (cube->ennemies[nb]->pos_x);
	else if (dir == 2)
		return (cube->ennemies[nb]->pos_x - moveSpeed);
	else
		return (cube->ennemies[nb]->pos_x + moveSpeed);
}

double	calcul_newposy_en(int dir, t_cube *cube, double moveSpeed, int nb)
{
	if (dir == 0)
		return (cube->ennemies[nb]->pos_y - moveSpeed);
	else if (dir == 1)
		return (cube->ennemies[nb]->pos_y + moveSpeed);
	else if (dir == 2)
		return (cube->ennemies[nb]->pos_y);
	else
		return (cube->ennemies[nb]->pos_y);
}

void	make_move_en(t_cube *cube, int dir, double moveSpeed, int nb)
{
	double	newpos_x;
	double	newpos_y;
	int		i;

	i = 0;
	newpos_x = calcul_newposx_en(dir, cube, moveSpeed, nb);
	newpos_y = calcul_newposy_en(dir, cube, moveSpeed, nb);
	while (cube->ennemies[i])
	{
		if (i != nb && cube->ennemies[i]->pos_x == newpos_x
			&& cube->ennemies[i]->pos_y == newpos_y)
			return ;
		i++;
	}
	if (cube->map[(int)(cube->ennemies[nb]->pos_y)][(int)(newpos_x)] != '1'
		&& cube->map[(int)(cube->ennemies[nb]->pos_y)][(int)(newpos_x)] != 'C')
		cube->ennemies[nb]->pos_x = newpos_x;
	if (cube->map[(int)(newpos_y)][(int)(cube->ennemies[nb]->pos_x)] != '1'
		&& cube->map[(int)(newpos_y)][(int)(cube->ennemies[nb]->pos_x)] != 'C')
		cube->ennemies[nb]->pos_y = newpos_y;
}
