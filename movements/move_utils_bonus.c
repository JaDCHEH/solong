/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:46:20 by cjad              #+#    #+#             */
/*   Updated: 2022/02/15 19:19:02 by cjad             ###   ########.fr       */
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

void	met_enemy(char c, t_vars *m, int a)
{
	int	x;
	int	y;

	x = (m->wi / 2 * 100) - 150;
	y = (m->h / 2 * 100) - 74;
	if (c == 'K' && a)
	{
		m->al = 0;
		mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
		mlx_put_image_to_window(m->ptr, m->win, m->ded, m->px, m->py - 15);
		mlx_put_image_to_window(m->ptr, m->win, m->game, x, y);
	}
	if (!a)
	{
		mlx_put_image_to_window(m->ptr, m->win, m->g, m->px, m->py);
		mlx_put_image_to_window(m->ptr, m->win, m->ded, m->px, m->py - 15);
		mlx_put_image_to_window(m->ptr, m->win, m->game, x, y);
	}
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

void	number_of_moves(t_vars	*m)
{
	char	*str1;
	char	*str2;
	char	*temp;
	char	*number;
	int		x;

	temp = ft_strdup("Moves x ");
	x = m->wi * 50;
	number = ft_itoa(m->moves);
	str1 = ft_strjoin(temp, number);
	free(temp);
	free(number);
	temp = ft_strdup("Coins x ");
	number = ft_itoa(m->coin);
	str2 = ft_strjoin(temp, number);
	mlx_clear_window(m->ptr, m->win);
	print_map(m);
	mlx_string_put(m->ptr, m->win, x + 200, 50, 0xFFFFFF, str1);
	mlx_string_put(m->ptr, m->win, x - 200, 50, 0xFFFFFF, str2);
	free(temp);
	free(str2);
	free(str1);
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
