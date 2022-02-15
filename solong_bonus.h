/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:37:27 by cjad              #+#    #+#             */
/*   Updated: 2022/02/15 19:07:54 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_BONUS_H
# define SOLONG_BONUS_H
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
	void	*g;
	void	*gw;
	void	*k;
	void	*ded;
	void	*game;
	void	*sx;
	void	*sa;
	int		flag;
	int		bb;
	int		kk;
	int		hh;
	int		ww;
	int		x;
	int		y;
	int		coin;
	int		h;
	int		wi;
	int		px;
	int		py;
	int		ex;
	int		ey;
	int		al;
	int		won;
	int		ennum;
	int		**enemy;
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
void	met_enemy(char c, t_vars *m, int a);
void	number_of_moves(t_vars	*m);
void	height_width(t_vars *mlx, char *av);
void	enemy(t_vars *mlx);
void	enemy_move1(t_vars	*m, int i);
void	enemy_move2(t_vars	*m, int i);
void	enemy_move3(t_vars	*m, int i);
void	enemy_move4(t_vars	*m, int i);
void	enemy_move5(t_vars	*m, int i, int a);
void	enemy_move6(t_vars	*m, int i, int a);
int		enemy_moves(t_vars	*mlx, int i, int x, int y);
int		no_move(t_vars	*m, int *i);
void	won(t_vars *m);
int		loop_hook(t_vars *mlx);
int		ft_close(void);

#endif