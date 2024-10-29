/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemie.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 14:33:48 by marvin            #+#    #+#             */
/*   Updated: 2024/09/12 10:33:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube3d_bonus.h"

void	ennemie2(t_enm *ennemies)
{
	if (ennemies->en->path[ennemies->i] == 'H')
		make_move_en(ennemies->cube, 0, 1, ennemies->nbr);
	else if (ennemies->en->path[ennemies->i] == 'B')
		make_move_en(ennemies->cube, 1, 1, ennemies->nbr);
	else if (ennemies->en->path[ennemies->i] == 'G')
		make_move_en(ennemies->cube, 2, 1, ennemies->nbr);
	else if (ennemies->en->path[ennemies->i] == 'D')
		make_move_en(ennemies->cube, 3, 1, ennemies->nbr);
}

void	ennemie(t_enm *ennemies)
{
	ennemies->en->erreur = 1;
	where_go(ennemies->en, ennemies);
	if ((int)ennemies->cube->pos_x != (int)ennemies->pos_player_x
		|| (int)ennemies->cube->pos_y != (int)ennemies->pos_player_y)
	{
		ennemies->en->erreur = 1;
		ennemies->i = where_go(ennemies->en, ennemies);
		ennemies->pos_player_x = ennemies->cube->pos_x;
		ennemies->pos_player_y = ennemies->cube->pos_y;
		ennemies->i--;
	}
	if (ennemies->en->erreur == 1)
		return ;
	if (ennemies->last_time + 700 > get_current_time())
		return ;
	else
		ennemies->last_time = get_current_time();
	ennemie2(ennemies);
	if (ennemies->i == 0)
	{
		gameover(ennemies->cube);
		return ;
	}
	ennemies->i--;
}

void	mouv_en(t_cube *cube)
{
	int	nb;

	nb = 0;
	while (nb < cube->nb_ennemy)
	{
		ennemie(cube->ennemies[nb]);
		nb++;
	}
}
