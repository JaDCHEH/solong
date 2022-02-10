/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:56:46 by cjad              #+#    #+#             */
/*   Updated: 2022/02/10 13:43:05 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	move1(int keycode, t_vars *m, int i, int j)
{
	if (keycode == 123)
	{
		if (m->map[i][j - 1] != '1' && m->map[i][j - 1] != 'E')
		{
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			m->px -= 100;
			if (m->map[i][j - 1] == 'C')
			{
				m->map[i][j - 1] = '0';
				m->coin--;
			}
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			mlx_put_image_to_window(m->ptr, m->win, m->p, m->px + 15, m->py);
		}
		if (m->ex == m->px && m->ey == m->py && m->coin == 0)
			exit (0);
	}
}

static void	move2(int keycode, t_vars *m, int i, int j)
{
	if (keycode == 124)
	{
		if (m->map[i][j + 1] != '1' && m->map[i][j + 1] != 'E')
		{
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			m->px += 100;
			if (m->map[i][j + 1] == 'C')
			{
				m->map[i][j + 1] = '0';
				m->coin--;
			}
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			mlx_put_image_to_window(m->ptr, m->win, m->p, m->px + 15, m->py);
		}
		if (m->ex == m->px && m->ey == m->py && m->coin == 0)
			exit (0);
	}
}

static void	move3(int keycode, t_vars *m, int i, int j)
{
	if (keycode == 125)
	{
		if (m->map[i + 1][j] != '1' && m->map[i + 1][j] != 'E')
		{
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			m->py += 100;
			if (m->map[i + 1][j] == 'C')
			{
				m->map[i + 1][j] = '0';
				m->coin--;
			}
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			mlx_put_image_to_window(m->ptr, m->win, m->p, m->px + 15, m->py);
		}
		if (m->ex == m->px && m->ey == m->py && m->coin == 0)
			exit (0);
	}
}

static void	move4(int keycode, t_vars *m, int i, int j)
{
	if (keycode == 126)
	{
		if (m->map[i - 1][j] != '1' && m->map[i - 1][j] != 'E')
		{	
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			m->py -= 100;
			if (m->map[i - 1][j] == 'C')
			{
				m->map[i - 1][j] = '0';
				m->coin--;
			}
			mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
			mlx_put_image_to_window(m->ptr, m->win, m->p, m->px + 15, m->py);
		}
		if (m->ex == m->px && m->ey == m->py && m->coin == 0)
			exit (0);
	}
}

int	mouvement(int keycode, t_vars *m)
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
		m->map[m->ey / 100][m->ex / 100] = 0;
		mlx_put_image_to_window(m->ptr, m->win, m->g, m->ex, m->ey);
		mlx_put_image_to_window(m->ptr, m->win, m->ne, m->ex + 12, m->ey);
	}
	if (keycode == 53)
		exit(0);
	return (0);
}
