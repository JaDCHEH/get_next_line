/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjad <cjad@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:37:27 by cjad              #+#    #+#             */
/*   Updated: 2021/11/27 18:37:54 by cjad             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*ft_strjoin(char	*s1, char *s2);
char	*get_next_line(int fd);
char	*ft_substr(char	*s, unsigned int start, size_t len);
char	*ft_strdup(const char	*s1);

#endif