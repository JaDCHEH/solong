/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:56:46 by cjad              #+#    #+#             */
/*   Updated: 2022/02/13 19:52:38 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

static void	move1(int keycode, t_vars *m, int i, int j)
{
	if (keycode == 0)
	{
		if (m->map[i][j - 1] != '1' && m->map[i][j - 1] != 'E' && m->al == 1)
		{
			m->moves++;
			number_of_moves(m);
			m->side = -1;
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			m->px -= 100;
			if (m->map[i][j - 1] == 'C')
			{
				m->map[i][j - 1] = '0';
				m->coin--;
			}
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			mlx_put_image_to_window(m->ptr, m->win, m->pl, m->px + 20, m->py);
			met_enemy(m->map[i][j - 1], m);
			if (m->map[i][j] != 'K')
				m->map[i][j] = '0';
			enemy(m);
			m->map[i][j - 1] = 'P';
		}
		if (m->ex == m->px && m->ey == m->py && m->coin == 0)
			exit (0);
	}
}

static void	move2(int keycode, t_vars *m, int i, int j)
{
	if (keycode == 2)
	{
		if (m->map[i][j + 1] != '1' && m->map[i][j + 1] != 'E' && m->al == 1)
		{
			m->moves++;
			number_of_moves(m);
			m->side = 1;
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			m->px += 100;
			if (m->map[i][j + 1] == 'C')
			{
				m->map[i][j + 1] = '0';
				m->coin--;
			}
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			mlx_put_image_to_window(m->ptr, m->win, m->p, m->px + 15, m->py);
			met_enemy(m->map[i][j + 1], m);
			if (m->map[i][j] != 'K')
				m->map[i][j] = '0';
			enemy(m);
			m->map[i][j + 1] = 'P';
		}
		if (m->ex == m->px && m->ey == m->py && m->coin == 0)
			exit (0);
	}
}

static void	move3(int keycode, t_vars *m, int i, int j)
{
	if (keycode == 1)
	{
		if (m->map[i + 1][j] != '1' && m->map[i + 1][j] != 'E' && m->al == 1)
		{
			m->moves++;
			number_of_moves(m);
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			m->py += 100;
			if (m->map[i + 1][j] == 'C')
			{
				m->map[i + 1][j] = '0';
				m->coin--;
			}
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			side_check(m);
			met_enemy(m->map[i + 1][j], m);
			if (m->map[i][j] != 'K')
				m->map[i][j] = '0';
			enemy(m);
			m->map[i + 1][j] = 'P';
		}
		if (m->ex == m->px && m->ey == m->py && m->coin == 0)
			exit (0);
	}
}

static void	move4(int keycode, t_vars *m, int i, int j)
{
	if (keycode == 13)
	{
		if (m->map[i - 1][j] != '1' && m->map[i - 1][j] != 'E' && m->al == 1)
		{	
			m->moves++;
			number_of_moves(m);
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			m->py -= 100;
			if (m->map[i - 1][j] == 'C')
			{
				m->map[i - 1][j] = '0';
				m->coin--;
			}
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			side_check(m);
			met_enemy(m->map[i - 1][j], m);
			if (m->map[i][j] != 'K')
				m->map[i][j] = '0';
			enemy(m);
			m->map[i - 1][j] = 'P';
		}
		if (m->ex == m->px && m->ey == m->py && m->coin == 0)
			exit (0);
	}
}

int	movement(int keycode, t_vars *m)
{
	int	i;
	int	j;

	i = m->py / 100;
	j = m->px / 100;
	move1(keycode, m, i, j);
	move2(keycode, m, i, j);
	move3(keycode, m, i, j);
	move4(keycode, m, i, j);
	if (m->coin == 0)
	{
		m->map[m->ey / 100][m->ex / 100] = '0';
		mlx_put_image_to_window(m->ptr, m->win, m->g, m->ex, m->ey);
		mlx_put_image_to_window(m->ptr, m->win, m->ne, m->ex + 12, m->ey);
	}
	if (keycode == 53)
		exit(0);
	return (0);
}
