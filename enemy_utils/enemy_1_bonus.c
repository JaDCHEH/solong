/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 15:52:36 by cjad              #+#    #+#             */
/*   Updated: 2022/02/13 19:53:56 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

int	no_move(t_vars	*m, int *i)
{
	int	a;
	int	x;
	int	y;

	x = i[0];
	y = i[1];
	a = 0;
	if (m->map[y + 1][x] != '1' && m->map[y + 1][x] != 'E'
		&& m->map[y + 1][x] != 'C' && m->map[y + 1][x] != 'K')
		a++;
	if (m->map[y - 1][x] != '1' && m->map[y - 1][x] != 'E'
		&& m->map[y - 1][x] != 'C' && m->map[y - 1][x] != 'K')
		a++;
	if (m->map[y][x + 1] != '1' && m->map[y][x + 1] != 'E'
		&& m->map[y][x + 1] != 'C' && m->map[y][x + 1] != 'K')
		a++;
	if (m->map[y][x - 1] != '1' && m->map[y][x - 1] != 'E'
		&& m->map[y][x - 1] != 'C' && m->map[y][x - 1] != 'K')
		a++;
	return (a);
}

void	enemy_move5(t_vars	*m, int i, int a)
{
	if (a > 0)
		enemy_move4(m, i);
	else
		enemy_move1(m, i);
}

void	enemy_move6(t_vars	*m, int i, int a)
{
	if (a > 0)
		enemy_move2(m, i);
	else
		enemy_move3(m, i);
}

int	enemy_1moves(t_vars	*mlx, int i, int x, int y)
{
	if (x <= y && y > 0)
	{
		enemy_move4(mlx, i);
		return (0);
	}
	if (x == 0 && y != x)
	{
		enemy_move5(mlx, i, y);
		return (0);
	}
	if (y == 0 && x != y)
	{
		enemy_move6(mlx, i, x);
		return (0);
	}
	return (0);
}

int	enemy_moves(t_vars	*mlx, int i, int x, int y)
{
	if (x > y && x < 0)
	{
		enemy_move1(mlx, i);
		return (0);
	}
	if (x > y && x > 0)
	{
		enemy_move2(mlx, i);
		return (0);
	}
	if (x <= y && y < 0)
	{
		enemy_move3(mlx, i);
		return (0);
	}
	enemy_1moves(mlx, i, x, y);
	return (0);
}
