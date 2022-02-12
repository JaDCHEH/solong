/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:45:35 by cjad              #+#    #+#             */
/*   Updated: 2022/02/12 20:45:37 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ennemy_move1(t_vars	*m, int i)
{
	int	x;
	int	y;

	x = m->ennemy[i][0];
	y = m->ennemy[i][1];
	if (m->map[y - 1][x] != '1' && m->map[y - 1][x] != 'E'
		&& m->map[y - 1][x] != 'C' && m->map[y - 1][x] != 'K')
	{
		mlx_put_image_to_window(m->ptr, m->win, m->g, x * 100, y * 100);
		mlx_put_image_to_window(m->ptr, m->win, m->g, x * 100, y * 100 - 100);
		mlx_put_image_to_window(m->ptr, m->win, m->k, x * 100, y * 100 - 100);
		m->map[y][x] = '0';
		m->map[y - 1][x] = 'K';
	}
	else
		ennemy_move2(m, i);
}

void	ennemy_move2(t_vars	*m, int i)
{
	int	x;
	int	y;

	x = m->ennemy[i][0];
	y = m->ennemy[i][1];
	if (m->map[y][x + 1] != '1' && m->map[y][x + 1] != 'E'
		&& m->map[y][x + 1] != 'C' && m->map[y][x + 1] != 'K')
	{
		mlx_put_image_to_window(m->ptr, m->win, m->g, x * 100, y * 100);
		mlx_put_image_to_window(m->ptr, m->win, m->g, x * 100 + 100, y * 100);
		mlx_put_image_to_window(m->ptr, m->win, m->k, x * 100 + 100, y * 100);
		m->map[y][x] = '0';
		m->map[y][x + 1] = 'K';
	}
	else
		ennemy_move4(m, i);
}

void	ennemy_move3(t_vars	*m, int i)
{
	int	x;
	int	y;

	x = m->ennemy[i][0];
	y = m->ennemy[i][1];
	if (m->map[y][x - 1] != '1' && m->map[y][x - 1] != 'E'
		&& m->map[y][x - 1] != 'C' && m->map[y][x - 1] != 'K')
	{
		mlx_put_image_to_window(m->ptr, m->win, m->g, x * 100, y * 100);
		mlx_put_image_to_window(m->ptr, m->win, m->g, x * 100 - 100, y * 100);
		mlx_put_image_to_window(m->ptr, m->win, m->k, x * 100 - 100, y * 100);
		m->map[y][x] = '0';
		m->map[y][x - 1] = 'K';
	}
	else
		ennemy_move1(m, i);
}

void	ennemy_move4(t_vars	*m, int i)
{
	int	x;
	int	y;

	x = m->ennemy[i][0];
	y = m->ennemy[i][1];
	if (m->map[y + 1][x] != '1' && m->map[y + 1][x] != 'E'
		&& m->map[y + 1][x] != 'C' && m->map[y + 1][x] != 'K')
	{
		mlx_put_image_to_window(m->ptr, m->win, m->g, x * 100, y * 100);
		mlx_put_image_to_window(m->ptr, m->win, m->g, x * 100, y * 100 + 100);
		mlx_put_image_to_window(m->ptr, m->win, m->k, x * 100, y * 100 + 100);
		m->map[y][x] = '0';
		m->map[y + 1][x] = 'K';
	}
	else
		ennemy_move3(m, i);
}

void	ennemy(t_vars *mlx)
{
	int	i;
	int	x;
	int	y;
	int	j;

	i = 0;
	while (mlx->ennemy[i])
	{
		x = mlx->px / 100 - mlx->ennemy[i][0];
		y = mlx->py / 100 - mlx->ennemy[i][1];
		if (no_move(mlx, i))
		{
			if (x > y && x < 0)
				ennemy_move1(mlx, i);
			if (x > y && x >= 0)
				ennemy_move2(mlx, i);
			if (x <= y && y < 0)
				ennemy_move3(mlx, i);
			if (x <= y && y >= 0)
				ennemy_move4(mlx, i);
		}
		i++;
	}
}
