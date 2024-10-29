/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:02:27 by marvin            #+#    #+#             */
/*   Updated: 2024/08/06 10:02:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube3d_bonus.h"

void	open_doors(t_cube *cube)
{
	int	mapy;
	int	mapx;

	mapx = (int)cube->pos_x;
	mapy = (int)cube->pos_y;
	if (cube->act_doors_state == 1)
	{
		if (cube->map[mapy][mapx + 1] == 'C')
			cube->map[mapy][mapx + 1] = 'O';
		else if (cube->map[mapy][mapx + 1] == 'O')
			cube->map[mapy][mapx + 1] = 'C';
		if (cube->map[mapy][mapx - 1] == 'C')
			cube->map[mapy][mapx - 1] = 'O';
		else if (cube->map[mapy][mapx - 1] == 'O')
			cube->map[mapy][mapx - 1] = 'C';
		if (cube->map[mapy - 1][mapx] == 'C')
			cube->map[mapy - 1][mapx] = 'O';
		else if (cube->map[mapy - 1][mapx] == 'O')
			cube->map[mapy - 1][mapx] = 'C';
		if (cube->map[mapy + 1][mapx] == 'C')
			cube->map[mapy + 1][mapx] = 'O';
		else if (cube->map[mapy + 1][mapx] == 'O')
			cube->map[mapy + 1][mapx] = 'C';
	}
	cube->act_doors_state = 0;
}
