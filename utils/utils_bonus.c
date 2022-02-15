/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:10:42 by cjad              #+#    #+#             */
/*   Updated: 2022/02/15 19:17:32 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

void	anim1(t_vars *m, int x)
{
	if (m->hh % 15000 == 7500)
	{
		mlx_put_image_to_window(m->ptr, m->win, m->sx, x + 150, m->bb);
		mlx_put_image_to_window(m->ptr, m->win, m->sa, x - 250, m->bb);
		m->bb -= 6;
	}
	if (m->hh % 15000 == 10000)
	{
		mlx_put_image_to_window(m->ptr, m->win, m->sx, x + 150, m->bb);
		mlx_put_image_to_window(m->ptr, m->win, m->sa, x - 250, m->bb);
		m->bb -= 6;
	}
	if (m->hh % 15000 == 12500)
	{
		mlx_put_image_to_window(m->ptr, m->win, m->sx, x + 150, m->bb);
		mlx_put_image_to_window(m->ptr, m->win, m->sa, x - 250, m->bb);
		m->bb -= 6;
	}
}

void	anim(t_vars *m)
{
	int	x;

	x = m->wi * 50;
	if (m->hh % 15000 == 0)
	{
		mlx_put_image_to_window(m->ptr, m->win, m->sx, x + 150, m->bb);
		mlx_put_image_to_window(m->ptr, m->win, m->sa, x - 250, m->bb);
		m->bb += 6;
	}
	if (m->hh % 15000 == 2500)
	{
		mlx_put_image_to_window(m->ptr, m->win, m->sx, x + 150, m->bb);
		mlx_put_image_to_window(m->ptr, m->win, m->sa, x - 250, m->bb);
		m->bb += 6;
	}
	if (m->hh % 15000 == 5000)
	{
		mlx_put_image_to_window(m->ptr, m->win, m->sx, x + 150, m->bb);
		mlx_put_image_to_window(m->ptr, m->win, m->sa, x - 250, m->bb);
		m->bb += 6;
	}
	anim1(m, x);
	m->hh++;
}

void	first_line(t_vars *m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < m->wi)
	{
		mlx_put_image_to_window(m->ptr, m->win, m->w, x * 100, 0);
		x++;
	}
}

int	loop_hook(t_vars *mlx)
{
	if (mlx->al == 0 || mlx->won == 1)
	{
		if (mlx->kk == 5000)
			exit(0);
		mlx->kk++;
	}
	if (mlx->ww % 2500 == 0)
	{
		first_line(mlx);
		number_of_moves(mlx);
	}
	anim(mlx);
	mlx->ww++;
	return (0);
}

int	ft_close(void)
{
	exit(0);
	return (0);
}
