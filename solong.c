/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:31:03 by cjad              #+#    #+#             */
/*   Updated: 2022/02/15 17:20:21 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	map(t_vars *mlx, char	*av)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(av, O_RDWR, 0777);
	if (fd < 0)
	{
		perror("Error\n");
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

void	variables(t_vars	*mlx)
{
	mlx->moves = 0;
	mlx->flag = 1;
	mlx->g = mlx_xpm_file_to_image(mlx->ptr, "./e/grass.xpm", &mlx->x, &mlx->y);
	mlx->c = mlx_xpm_file_to_image(mlx->ptr, "./e/anemo.xpm", &mlx->x, &mlx->y);
	mlx->w = mlx_xpm_file_to_image(mlx->ptr, "./e/wall.xpm", &mlx->x, &mlx->y);
	mlx->p = mlx_xpm_file_to_image(mlx->ptr, "./e/xiao.xpm", &mlx->x, &mlx->y);
	mlx->pl = mlx_xpm_file_to_image(mlx->ptr, "./e/xiol.xpm", &mlx->x, &mlx->y);
	mlx->e = mlx_xpm_file_to_image(mlx->ptr, "./e/dc.xpm", &mlx->x, &mlx->y);
	mlx->ne = mlx_xpm_file_to_image(mlx->ptr, "./e/do.xpm", &mlx->x, &mlx->y);
	mlx->gw = mlx_xpm_file_to_image(mlx->ptr, "./e/gw.xpm", &mlx->x, &mlx->y);
}

void	solong(char **av)
{
	t_vars	mlx;

	height_width(&mlx, av[1]);
	map(&mlx, av[1]);
	mlx.ptr = mlx_init();
	mlx.won = 0;
	mlx.kk = 0;
	mlx.win = mlx_new_window(mlx.ptr, mlx.wi * 100, mlx.h * 100, "so long");
	variables(&mlx);
	print_map(&mlx);
	mlx_loop_hook(mlx.ptr, loop_hook, &mlx);
	mlx_key_hook(mlx.win, movement, &mlx);
	mlx_hook(mlx.win, 17, 0, ft_close, &mlx);
	mlx_loop(mlx.ptr);
}

int	main(int ac, char	**av)
{
	if (ac == 2)
	{
		solong(av);
	}
	else
	{
		ft_printf("Error\ninvalid number of arguments");
		exit (0);
	}
}
