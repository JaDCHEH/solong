/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:46:20 by cjad              #+#    #+#             */
/*   Updated: 2022/02/12 20:47:52 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	side_check(t_vars *m)
{
	if (m->side == -1)
		mlx_put_image_to_window(m->ptr, m->win, m->pl, m->px + 20, m->py);
	else
		mlx_put_image_to_window(m->ptr, m->win, m->p, m->px + 15, m->py);
}

void	met_ennemy(char c, t_vars *m)
{
	int	x;
	int	y;

	x = (m->wi / 2 * 100) - 150;
	y = (m->h / 2 * 100) - 74;
	if (c == 'K')
	{
		m->al = 0;
		mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
		mlx_put_image_to_window(m->ptr, m->win, m->ded, m->px, m->py - 15);
		mlx_put_image_to_window(m->ptr, m->win, m->game, x, y);
	}
}

void	number_of_moves(t_vars	*m)
{
	char	*str;
	char	*temp;
	char	*number;
	int		x;

	temp = ft_strdup("Moves x ");
	x = m->wi * 100 - 100;
	number = ft_itoa(m->moves);
	str = ft_strjoin(temp, number);
	mlx_clear_window(m->ptr, m->win);
	print_map(m);
	mlx_string_put(m->ptr, m->win, x, 50, 0xFF0000, str);
	free(temp);
	free(str);
	free(number);
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

int	no_move(t_vars	*m, int i)
{
	int	a;
	int	x;
	int	y;

	x = m->ennemy[i][0];
	y = m->ennemy[i][1];
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
