/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:37:34 by cjad              #+#    #+#             */
/*   Updated: 2022/02/07 16:11:09 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	ft_strcat(char	*s1, const char	*s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
}

char	*ft_strjoin(char	*s1, char *s2)
{
	int		s1l;
	int		s2l;
	char	*s;

	if (!s1 || !s2)
		return (NULL);
	s1l = 0;
	while (s1[s1l] != '\0')
		s1l++;
	s2l = 0;
	while (s2[s2l] != '\0')
		s2l++;
	s = (char *) malloc (sizeof (char) * (s1l + s2l + 1));
	if (!s)
		return (NULL);
	s[0] = '\0';
	ft_strcat(s, s1);
	ft_strcat(s, s2);
	return (s);
}

static void	fill(char const	*s, char	*sub, unsigned int start, size_t len)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	while (s[i] != '\0')
	{
		if (i >= start && a < len)
		{
			sub[a] = s[i];
			a++;
		}
		i++;
	}
	sub[a] = '\0';
}

char	*ft_substr(char	*s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	a;
	size_t	b;
	size_t	j;

	a = 0;
	i = 0;
	b = len + 1;
	j = 0;
	if (!s)
		return (NULL);
	while (s[j] != '\0')
		j++;
	if (b > j)
		b = j + 1;
	sub = (char *) malloc (sizeof (char) * b);
	if (!sub)
		return (NULL);
	fill(s, sub, start, len);
	return (sub);
}

char	*ft_strdup(const char	*s1)
{
	int		i;
	char	*scpy;

	i = 0;
	while (s1[i] != '\0')
		i++;
	scpy = (char *) malloc (sizeof (char) * (i + 1));
	if (!scpy)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		scpy[i] = s1[i];
		i++;
	}
	scpy[i] = '\0';
	return (scpy);
}
