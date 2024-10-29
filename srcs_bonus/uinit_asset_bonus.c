/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uinit_asset_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:02:08 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 17:15:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube3d_bonus.h"

int	find_ennemie(t_test *test)
{
	int	i;
	int	j;
	int	ennemie;

	i = 0;
	ennemie = 0;
	while (test->map[i])
	{
		j = 0;
		if (ft_strchr(test->map[i], 'M') != NULL)
		{
			while (test->map[i][j] && test->map[i][j] != '\n')
			{
				if (test->map[i][j] == 'M')
				{
					ennemie++;
				}
				j++;
			}
		}
		i++;
	}
	return (ennemie);
}

void	init_ennemies(t_cube *cube)
{
	t_en	*en;

	if (cube->nb_ennemy == 0)
		return ;
	en = malloc(sizeof(t_en));
	cube->ennemies = malloc((cube->nb_ennemy + 1) * sizeof(t_enm *));
	cube->ennemies[cube->nb_ennemy] = '\0';
	init_ennemies2(cube, 0, 0, en);
}

int	verif_map_arg(t_test *test)
{
	int	i;
	int	j;

	i = 0;
	while (test->map[i])
	{
		j = 0;
		while (test->map[i][j])
		{
			if (test->map[i][j] != '0' && test->map[i][j] != '1'
				&& test->map[i][j] != ' ' && test->map[i][j] != 'N'
				&& test->map[i][j] != 'S' && test->map[i][j] != 'E'
				&& test->map[i][j] != 'W' && test->map[i][j] != 'C'
				&& test->map[i][j] != 'M' && test->map[i][j] != 'O'
				&& test->map[i][j] != '\n' && test->map[i][j] != '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
