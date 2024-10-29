/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:44:14 by marvin            #+#    #+#             */
/*   Updated: 2024/08/01 14:44:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

char	*space(t_tri_index	*tri)
{
	char	*temp2;

	temp2 = malloc(sizeof(char ) * (tri->m + 1));
	while (tri->j < tri->m)
	{
		temp2[tri->j] = ' ';
		tri->j++;
	}
	temp2[tri->j - 1] = '\n';
	temp2[tri->j] = '\0';
	return (temp2);
}

void	sdup(t_tri_index	*tri, char **temp, char **tab)
{
	temp[tri->l] = malloc(sizeof(char) * (tri->m + 1));
	while (tab[tri->k][++tri->j] && tab[tri->k][tri->j] != '\n')
		temp[tri->l][tri->j] = tab[tri->k][tri->j];
	while (tri->j < tri->m - 1)
	{
		temp[tri->l][tri->j] = ' ';
		tri->j++;
	}
	temp[tri->l][tri->j] = '\n';
	temp[tri->l][tri->j + 1] = '\0';
	tri->j = -1;
	tri->k++;
	tri->l++;
}

char	**expende_tab(char **tab)
{
	char		**temp;
	char		*temp2;
	t_tri_index	*tri;

	tri = malloc(sizeof(t_tri_index));
	set_val(tri, tab);
	temp = malloc(sizeof(char *) * (tri->l + 4));
	temp2 = space(tri);
	temp[0] = ft_strdup(temp2);
	free(temp2);
	tri->l = 1;
	tri->j = -1;
	while (tab[tri->k])
		sdup(tri, temp, tab);
	tri->j = 0;
	temp2 = space(tri);
	temp[tri->l] = ft_strdup(temp2);
	temp[tri->l + 1] = '\0';
	free(temp2);
	free_tab(tab);
	free(tri);
	return (temp);
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
				&& test->map[i][j] != 'W' && test->map[i][j] != '\n'
				&& test->map[i][j] != '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
