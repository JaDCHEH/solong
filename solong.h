/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:37:27 by cjad              #+#    #+#             */
/*   Updated: 2022/02/15 17:20:12 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <stdarg.h>

char	*ft_strjoin(char	*s1, char *s2);
char	*get_next_line(int fd);
char	*ft_substr(char	*s, unsigned int start, size_t len);
char	*ft_strdup(const char	*s1);
int		ft_strlen(char	*s);
char	*ft_itoa(int n);

typedef struct s_map
{
	char	*s1;
	char	*s2;
	int		a;
	int		b;
	int		check;
}	t_map;

typedef struct s_vars
{
	void	*ptr;
	void	*win;
	void	*p;
	void	*pl;
	void	*e;
	void	*ne;
	void	*c;
	void	*w;
	void	*gw;
	void	*g;
	int		flag;
	int		won;
	int		kk;
	int		x;
	int		y;
	int		coin;
	int		h;
	int		wi;
	int		px;
	int		py;
	int		ex;
	int		ey;
	char	**map;
	int		side;
	int		moves;
}	t_vars;

typedef struct s_print
{
	int	i;
	int	j;
	int	x;
	int	y;
}	t_print;

void	print_map(t_vars	*mlx);
int		check_map(int fd, t_vars *mlx);
int		movement(int keycode, t_vars *mlx);
void	ft_printf(const char *s, ...);
void	side_check(t_vars *m);
void	height_width(t_vars *mlx, char *av);
void	won(t_vars *m);
int		loop_hook(t_vars *mlx);
int		ft_close(void);

#endif