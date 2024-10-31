/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:20:25 by ade-fran          #+#    #+#             */
/*   Updated: 2024/01/29 16:20:27 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_readl(int fd, char *temp, char (*buf)[BUFFER_SIZE + 1], ssize_t *r)
{
	while (!ft_check_new_line(*buf, '\n') && *r != 0)
	{
		if ((*buf)[0] && !temp)
		{
			temp = ft_strjoin(temp, *buf);
			if (!temp)
				return (NULL);
			ft_bzero(*buf, BUFFER_SIZE + 1);
		}
		*r = read(fd, *buf, BUFFER_SIZE);
		if (*r < 0)
			return (free(temp), NULL);
		if (*r == 0)
		{
			if (temp)
				return (ft_bzero(*buf, BUFFER_SIZE + 1), temp);
			return (NULL);
		}
		(*buf)[*r] = '\0';
		temp = ft_strjoin(temp, *buf);
		if (!temp)
			return (NULL);
	}
	return (temp);
}

char	*ft_get_line(char *temp, char (*buf)[BUFFER_SIZE + 1], char **line)
{
	int		i;
	int		j;
	size_t	size;

	i = 0;
	j = 0;
	if (!ft_check_new_line(temp, '\n'))
		size = ft_strlen(temp);
	else
		size = ft_check_new_line(temp, '\n');
	*line = (char *)malloc((size + 2) * sizeof(char));
	if (!(*line))
		return (NULL);
	while (temp[i] && temp[i] != '\n')
	{
		(*line)[i] = temp[i];
		i++;
	}
	(*line)[i++] = '\n';
	(*line)[i] = '\0';
	ft_bzero(*buf, BUFFER_SIZE + 1);
	while (temp[i])
		(*buf)[j++] = temp[i++];
	(*buf)[j] = '\0';
	return (*line);
}

char	*ft_get_next_line(int fd)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*temp;
	char			*next_line;
	ssize_t			r;

	r = 1;
	temp = NULL;
	if (fd == -1 || BUFFER_SIZE == 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	if (ft_check_new_line(buf, '\n'))
	{
		temp = ft_strjoin(temp, buf);
		if (!temp)
			return (NULL);
	}
	temp = ft_readl(fd, temp, &buf, &r);
	if (!temp)
		return (NULL);
	if (r == 0)
		return (temp);
	next_line = ft_get_line(temp, &buf, &next_line);
	return (free(temp), next_line);
}
