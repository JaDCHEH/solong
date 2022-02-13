/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:45:35 by cjad              #+#    #+#             */
/*   Updated: 2022/02/13 19:40:21 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

void	enemy_move1(t_vars	*m, int i)
{
	int	x;
	int	y;

	x = m->enemy[i][0];
	y = m->enemy[i][1];
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
		enemy_move2(m, i);
}

void	enemy_move2(t_vars	*m, int i)
{
	int	x;
	int	y;

	x = m->enemy[i][0];
	y = m->enemy[i][1];
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
		enemy_move4(m, i);
}

void	enemy_move3(t_vars	*m, int i)
{
	int	x;
	int	y;

	x = m->enemy[i][0];
	y = m->enemy[i][1];
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
		enemy_move1(m, i);
}

void	enemy_move4(t_vars	*m, int i)
{
	int	x;
	int	y;

	x = m->enemy[i][0];
	y = m->enemy[i][1];
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
		enemy_move3(m, i);
}

void	enemy(t_vars *mlx)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	while (mlx->enemy[i])
	{
		x = mlx->px / 100 - mlx->enemy[i][0];
		y = mlx->py / 100 - mlx->enemy[i][1];
		if (no_move(mlx, mlx->enemy[i]))
			enemy_moves(mlx, i, x, y);
		i++;
	}
}
