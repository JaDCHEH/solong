/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:09:45 by cjad              #+#    #+#             */
/*   Updated: 2022/02/13 17:05:43 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	*ft_strchr(const char	*s, int c)
{
	int		i;
	char	*str;
	char	cc;

	i = 0;
	cc = (char) c;
	str = (char *) s;
	while (str[i] != '\0')
	{
		if (str[i] == cc)
			return (str + i);
		i++;
	}
	if (s[i] == cc)
		return (str + i);
	else
		return (NULL);
}

void	ft_strdel(char **s)
{
	if (s != NULL)
	{
		free(*s);
		*s = NULL;
	}
}

char	*find_line(char	**s, int r)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	if (r == 0 && (*s) == NULL)
		return (NULL);
	while ((*s)[i] != '\n' && (*s)[i] != '\0')
		i++;
	if ((*s)[i] == '\n')
	{
		str = ft_substr((*s), 0, i);
		temp = ft_strdup(&(*s)[i + 1]);
		free(*s);
		(*s) = temp;
		if ((*s)[0] == '\0')
			ft_strdel(s);
	}
	else
	{
		str = ft_strdup((*s));
		ft_strdel(s);
	}
	return (str);
}

void	save_sus(char	**s, char *sus)
{
	char	*temp;

	if ((*s) == NULL)
		(*s) = ft_strdup(sus);
	else
	{
		temp = ft_strjoin((*s), sus);
		free((*s));
		(*s) = temp;
	}
}

char	*get_next_line(int fd)
{
	int			r;
	static char	*s;
	char		*sus;

	if (fd < 0)
		return (NULL);
	sus = (char *) malloc (sizeof(char) * (10 + 1));
	if (!sus)
		return (NULL);
	r = read(fd, sus, 10);
	while (r > 0)
	{
		sus[r] = '\0';
		save_sus(&s, sus);
		if (ft_strchr(s, '\n'))
			break ;
		r = read(fd, sus, 10);
	}
	if (r < 0)
	{
		free(sus);
		return (NULL);
	}
	free(sus);
	return (find_line(&s, r));
}
