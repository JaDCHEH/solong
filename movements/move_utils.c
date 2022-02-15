/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:46:20 by cjad              #+#    #+#             */
/*   Updated: 2022/02/15 17:22:00 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	side_check(t_vars *m)
{
	if (m->side == -1)
		mlx_put_image_to_window(m->ptr, m->win, m->pl, m->px + 20, m->py);
	else
		mlx_put_image_to_window(m->ptr, m->win, m->p, m->px + 15, m->py);
}

void	won(t_vars *m)
{
	int	x;
	int	y;

	x = (m->wi / 2 * 100) - 125;
	y = (m->h / 2 * 100) - 35;
	m->won = 1;
	mlx_put_image_to_window(m->ptr, m->win, m->gw, x, y);
}

int	loop_hook(t_vars *mlx)
{	
	if (mlx->won == 1)
	{
		if (mlx->kk == 5000)
			exit(0);
		mlx->kk++;
	}
	return (0);
}

void	height_width(t_vars *mlx, char *av)
{
	int		fd;
	char	*s;

	fd = open(av, O_RDWR, 0777);
	if (fd < 0)
	{
		perror("Error\n");
		exit(0);
	}
	mlx->wi = check_map(fd, mlx);
	close(fd);
	fd = open(av, O_RDWR, 0777);
	if (fd < 0)
	{
		perror("Error\n");
		exit(0);
	}
	s = get_next_line(fd);
	mlx->h = 0;
	while (s)
	{
		mlx->h++;
		free(s);
		s = get_next_line(fd);
	}
}

int	ft_close(void)
{
	exit (0);
	return (0);
}
