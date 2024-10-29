/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:44:14 by marvin            #+#    #+#             */
/*   Updated: 2024/09/15 17:03:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube3d_bonus.h"

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
	free_tab((void **)tab);
	free(tri);
	return (temp);
}

void	taille(t_cube *cube, int fd)
{
	char	*temp;

	cube->length = 1;
	cube->width = 0;
	temp = get_next_line(fd);
	while (temp[cube->width] != '\n')
		cube->width++;
	cube->width--;
	while (temp != NULL)
	{
		free(temp);
		temp = NULL;
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		cube->length++;
	}
	free(temp);
}

int	is_valid_position(t_cube *cube, double pos_x,
	double pos_y, double hitbox_size)
{
	return (cube->map[(int)(pos_y)][(int)(pos_x + hitbox_size)] != '1' &&
			cube->map[(int)(pos_y)][(int)(pos_x - hitbox_size)] != '1' &&
			cube->map[(int)(pos_y + hitbox_size)][(int)(pos_x)] != '1' &&
			cube->map[(int)(pos_y - hitbox_size)][(int)(pos_x)] != '1' &&
			cube->map[(int)(pos_y)][(int)(pos_x + hitbox_size)] != 'C' &&
			cube->map[(int)(pos_y)][(int)(pos_x - hitbox_size)] != 'C' &&
			cube->map[(int)(pos_y + hitbox_size)][(int)(pos_x)] != 'C' &&
			cube->map[(int)(pos_y - hitbox_size)][(int)(pos_x)] != 'C');
}
