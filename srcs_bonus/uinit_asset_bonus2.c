/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uinit_asset_bonus2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:46:49 by marvin            #+#    #+#             */
/*   Updated: 2024/09/12 15:46:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube3d_bonus.h"

void	init_ennemies3(t_cube *cube, int ene, t_en *en)
{
	cube->ennemies[ene]->cube = cube;
	cube->ennemies[ene]->en = en;
	cube->ennemies[ene]->en->erreur = 1;
	cube->ennemies[ene]->dir_x = -1;
	cube->ennemies[ene]->dir_y = 0.0;
	cube->ennemies[ene]->nbr = ene;
	cube->ennemies[ene]->last_time = get_current_time();
	cube->ennemies[ene]->pos_player_x
		= cube->ennemies[ene]->cube->pos_x;
	cube->ennemies[ene]->pos_player_y
		= cube->ennemies[ene]->cube->pos_y;
	cube->ennemies[ene]->i = where_go(cube->ennemies[ene]->en,
			cube->ennemies[ene]);
}

void	init_ennemies2(t_cube *cube, int i, int ene, t_en *en)
{
	int		j;

	while (cube->map[i])
	{
		j = 0;
		if (ft_strchr(cube->map[i], 'M') != NULL)
		{
			while (cube->map[i][j] && cube->map[i][j] != '\n')
			{
				if (cube->map[i][j] == 'M' && ene < cube->nb_ennemy)
				{
					cube->ennemies[ene] = malloc(sizeof(t_enm));
					cube->ennemies[ene]->pos_x = j + 0.5;
					cube->ennemies[ene]->pos_y = i + 0.5;
					init_ennemies3(cube, ene, en);
					ene++;
				}
				j++;
			}
		}
		i++;
	}
}
