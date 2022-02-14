/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:46:20 by cjad              #+#    #+#             */
/*   Updated: 2022/02/14 15:08:10 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong_bonus.h"

void	side_check(t_vars *m)
{
	if (m->side == -1)
		mlx_put_image_to_window(m->ptr, m->win, m->pl, m->px + 20, m->py);
	else
		mlx_put_image_to_window(m->ptr, m->win, m->p, m->px + 15, m->py);
}

void	met_enemy(char c, t_vars *m)
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
	x = m->wi * 50;
	number = ft_itoa(m->moves);
	str = ft_strjoin(temp, number);
	mlx_clear_window(m->ptr, m->win);
	print_map(m);
	mlx_string_put(m->ptr, m->win, x, 50, 0xFFFFFF, str);
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
