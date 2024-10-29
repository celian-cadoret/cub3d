/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 12:14:40 by marvin            #+#    #+#             */
/*   Updated: 2024/09/16 17:18:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cube3d_bonus.h"

void	destroy_img(t_cube *cube)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		mlx_destroy_image(cube->mlx_ptr, cube->assets[i].img);
		mlx_destroy_image(cube->mlx_ptr, cube->doors[i].img);
	}
	i = -1;
	while (++i < 3)
	{
		mlx_destroy_image(cube->mlx_ptr, cube->screen[i].img);
		mlx_destroy_image(cube->mlx_ptr, cube->assets_ennemies[i].img);
	}
}

int	the_end(t_cube *cube)
{
	free_tab((void **)cube->map);
	free(cube->error);
	free(cube->n);
	free(cube->s);
	free(cube->e);
	free(cube->w);
	destroy_img(cube);
	mlx_destroy_image(cube->mlx_ptr, cube->img->img);
	mlx_destroy_window(cube->mlx_ptr, cube->win_ptr);
	if (cube->mlx_ptr)
		mlx_destroy_display(cube->mlx_ptr);
	mlx_loop_end(cube->mlx_ptr);
	free(cube->mlx_ptr);
	if (cube->nb_ennemy)
	{
		free(cube->ennemies[0]->en);
		free_tab((void **)cube->ennemies);
	}
	exit(0);
}

char	**ft_strdup2(char **s)
{
	char	**dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	dest = malloc(sizeof(char *) * (i + 1));
	dest[i] = NULL;
	while (s[j])
	{
		dest[j] = ft_strdup(s[j]);
		j++;
	}
	return (dest);
}

char	***ft_strdup3(char ***s)
{
	char	***dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	dest = malloc(sizeof(char **) * (i + 1));
	dest[i] = NULL;
	while (s[j])
	{
		dest[j] = ft_strdup2(s[j]);
		j++;
	}
	return (dest);
}

void	divide_dir2(char *dir, char **temp2, t_cube *cube)
{
	if (ft_strchr(dir, 'F') != NULL && cube->cf == 0)
	{
		cube->f = rgb_to_hex(temp2, cube);
		cube->cf++;
		return ;
	}
	if (ft_strchr(dir, 'C') != NULL && cube->cc == 0)
	{
		cube->c = rgb_to_hex(temp2, cube);
		cube->cc++;
		return ;
	}
	cube->error = ft_strdup("plus de 1 pour une direction");
}
