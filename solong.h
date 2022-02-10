/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:37:27 by cjad              #+#    #+#             */
/*   Updated: 2022/02/09 19:35:50 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>

char	*ft_strjoin(char	*s1, char *s2);
char	*get_next_line(int fd);
char	*ft_substr(char	*s, unsigned int start, size_t len);
char	*ft_strdup(const char	*s1);
int		ft_strlen(char	*s);

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
	void	*e;
	void	*ne;
	void	*c;
	void	*w;
	void	*g;
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
int		mouvement(int keycode, t_vars *mlx);

#endif