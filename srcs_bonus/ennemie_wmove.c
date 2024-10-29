/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemie_wmove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:49:45 by marvin            #+#    #+#             */
/*   Updated: 2024/09/12 15:49:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube3d_bonus.h"

int	get_next_move(t_en *en, int *x, int *y, int dist)
{
	if (*y > 0 && en->map[*y - 1][*x] == dist - 1)
	{
		(*y)--;
		return ('B');
	}
	else if (en->map[*y + 1][*x] == dist - 1)
	{
		(*y)++;
		return ('H');
	}
	else if (*x > 0 && en->map[*y][*x - 1] == dist - 1)
	{
		(*x)--;
		return ('D');
	}
	else if (en->map[*y][*x + 1] == dist - 1)
	{
		(*x)++;
		return ('G');
	}
	return (0);
}

void	find_path(t_en *en)
{
	int	x;
	int	y;
	int	dist;
	int	path_index;
	int	next_move;

	x = en->end_x;
	y = en->end_y;
	dist = en->map[y][x];
	path_index = 0;
	while (dist > 1)
	{
		next_move = get_next_move(en, &x, &y, dist);
		if (!next_move)
			break ;
		en->path[path_index++] = next_move;
		dist--;
	}
	en->path[path_index] = '\0';
	free_tab((void **)en->map);
}

void	bfs2(int y, int x, t_en *en, int dist)
{
	if (en->map[y][x - 1] != '1' && en->map[y][x - 1] != 'C'
		&& (en->map[y][x - 1] == '0' || en->map[y][x - 1] > dist + 1))
	{
		en->map[y][x - 1] = dist + 1;
		bfs(y, x - 1, en, dist + 1);
	}
	if (en->map[y][x + 1] != '1' && en->map[y][x + 1] != 'C'
		&& (en->map[y][x + 1] == '0' || en->map[y][x + 1] > dist + 1))
	{
		en->map[y][x + 1] = dist + 1;
		bfs (y, x + 1, en, dist + 1);
	}
}

void	bfs(int y, int x, t_en *en, int dist)
{
	if ((y == en->end_y && x == en->end_x))
	{
		en->erreur = 0;
		return ;
	}
	if (dist == 6)
		return ;
	if (en->map[y - 1][x] != '1' && en->map[y - 1][x] != 'C'
		&& (en->map[y - 1][x] == '0' || en->map[y - 1][x] > dist + 1))
	{
		en->map[y - 1][x] = dist + 1;
		bfs(y - 1, x, en, dist + 1);
	}
	if (en->map[y + 1][x] != '1' && en->map[y + 1][x] != 'C'
		&& (en->map[y + 1][x] == '0' || en->map[y + 1][x] > dist + 1))
	{
		en->map[y + 1][x] = dist + 1;
		bfs(y + 1, x, en, dist + 1);
	}
	bfs2(y, x, en, dist);
}

int	where_go(t_en *en, t_enm *ennemies)
{
	en->map = ft_strdup2(ennemies->cube->map);
	en->end_y = ennemies->cube->pos_y;
	en->end_x = ennemies->cube->pos_x;
	en->map[(int)ennemies->pos_y][(int)ennemies->pos_x] = 1;
	en->map[(int)en->end_y][(int)en->end_x] = 50;
	bfs((int)ennemies->pos_y, (int)ennemies->pos_x, en, 1);
	if (en->erreur == 1)
		return (free_tab((void **)en->map), 0);
	find_path(en);
	return (ft_strlen(en->path));
}
