/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:09:45 by cjad              #+#    #+#             */
/*   Updated: 2021/11/27 17:02:34 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

void	strfree(char **s)
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
		str = ft_substr((*s), 0, i + 1);
		temp = ft_strdup(&(*s)[i + 1]);
		free(*s);
		(*s) = temp;
		if ((*s)[0] == '\0')
			strfree(s);
	}
	else
	{
		str = ft_strdup((*s));
		strfree(s);
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sus = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!sus)
		return (NULL);
	r = read(fd, sus, BUFFER_SIZE);
	while (r > 0)
	{
		sus[r] = '\0';
		save_sus(&s, sus);
		if (ft_strchr(s, '\n'))
			break ;
		r = read(fd, sus, BUFFER_SIZE);
	}
	if (r < 0)
	{
		free(sus);
		return (NULL);
	}
	free(sus);
	return (find_line(&s, r));
}
