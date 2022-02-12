/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:43:30 by cjad              #+#    #+#             */
/*   Updated: 2022/02/12 20:51:30 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_strlen(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	loop(t_vars	*m, t_print	*map)
{
	if (m->map[map->i][map->j] == '1')
		mlx_put_image_to_window(m->ptr, m->win, m->w, map->x, map->y);
	if (m->map[map->i][map->j] == 'P')
	{
		m->px = map->x;
		m->py = map->y;
		mlx_put_image_to_window(m->ptr, m->win, m->g, map->x, map->y);
		mlx_put_image_to_window(m->ptr, m->win, m->p, map->x + 15, map->y);
	}
	if (m->map[map->i][map->j] == 'C')
	{
		mlx_put_image_to_window(m->ptr, m->win, m->g, map->x, map->y);
		mlx_put_image_to_window(m->ptr, m->win, m->c, map->x + 16, map->y + 15);
	}
	if (m->map[map->i][map->j] == 'E')
	{
		m->ex = map->x;
		m->ey = map->y;
		mlx_put_image_to_window(m->ptr, m->win, m->g, map->x, map->y);
		mlx_put_image_to_window(m->ptr, m->win, m->e, map->x + 12, map->y);
	}
	if (m->map[map->i][map->j] == '0')
		mlx_put_image_to_window(m->ptr, m->win, m->g, map->x, map->y);
}

static void	print_ennemy(t_vars *m, t_print *map, int *i)
{
	if (m->map[map->i][map->j] == 'K')
	{
		m->ennemy[*i][0] = map->j;
		m->ennemy[*i][1] = map->i;
		mlx_put_image_to_window(m->ptr, m->win, m->g, map->x, map->y);
		mlx_put_image_to_window(m->ptr, m->win, m->k, map->x, map->y);
		i++;
	}
}

void	print_map(t_vars *m)
{
	t_print	map;
	int		i;

	i = 0;
	map.i = 0;
	map.y = 0;
	while (m->map[map.i])
	{
		map.j = 0;
		map.x = 0;
		while (m->map[map.i][map.j])
		{
			loop(m, &map);
			print_ennemy(m, &map, &i);
			map.x += 100;
			map.j++;
		}
		map.y += 100;
		map.i++;
	}
}
