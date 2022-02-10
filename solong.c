/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:31:03 by cjad              #+#    #+#             */
/*   Updated: 2022/02/10 13:42:46 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	height_width(t_vars *mlx, char *av)
{
	int		fd;
	char	*s;

	fd = open(av, O_RDWR, 0777);
	if (fd < 0)
	{
		perror("unvalid file");
		exit(0);
	}
	mlx->wi = check_map(fd, mlx);
	close(fd);
	fd = open(av, O_RDWR, 0777);
	if (fd < 0)
	{
		perror("unvalid file");
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

void	map(t_vars *mlx, char	*av)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(av, O_RDWR, 0777);
	if (fd < 0)
	{
		perror("unvalid file");
		exit(0);
	}
	mlx->map = (char **) malloc (sizeof (char *) * mlx->h + 1);
	while (i < mlx->h)
	{
		mlx->map[i] = get_next_line(fd);
		i++;
	}
	mlx->map[i] = NULL;
	close(fd);
}

int	main(int ac, char	**av)
{
	t_vars	mlx;

	if (ac == 2)
	{
		height_width(&mlx, av[1]);
		map(&mlx, av[1]);
		mlx.ptr = mlx_init();
		mlx.win = mlx_new_window(mlx.ptr, mlx.wi * 100, mlx.h * 100, "so long");
		mlx.g = mlx_xpm_file_to_image(mlx.ptr, "./e/grass.xpm", &mlx.x, &mlx.y);
		mlx.c = mlx_xpm_file_to_image(mlx.ptr, "./e/anemo.xpm", &mlx.x, &mlx.y);
		mlx.w = mlx_xpm_file_to_image(mlx.ptr, "./e/wall.xpm", &mlx.x, &mlx.y);
		mlx.p = mlx_xpm_file_to_image(mlx.ptr, "./e/xiao.xpm", &mlx.x, &mlx.y);
		mlx.e = mlx_xpm_file_to_image(mlx.ptr, "./e/dc.xpm", &mlx.x, &mlx.y);
		mlx.ne = mlx_xpm_file_to_image(mlx.ptr, "./e/do.xpm", &mlx.x, &mlx.y);
		print_map(&mlx);
		mlx_key_hook(mlx.win, mouvement, &mlx);
		mlx_loop(mlx.ptr);
	}
	else
	{
		write (2, "invalid number of arguments", 28);
		exit (0);
	}
}
