/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:14:37 by rkrechun          #+#    #+#             */
/*   Updated: 2024/03/28 15:08:10 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_reads(int fd, char *str)
{
	int		len;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (free(buff), free(str), NULL);
	len = 1;
	while (!ft_strchr(str, '\n') && len != 0)
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len == -1)
			return (free(buff), free(str), NULL);
		buff[len] = '\0';
		str = ft_strjoins(str, buff);
	}
	return (free(buff), str);
}

static char	*ft_print(char *str)
{
	int		len;
	char	*buff;

	len = 0;
	if (!str[len])
		return (NULL);
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	buff = malloc(sizeof(char) * (len + 2));
	if (!buff)
		return (NULL);
	len = 0;
	while (str[len] && str[len] != '\n')
	{
		buff[len] = str[len];
		len++;
	}
	if (str[len] == '\n')
	{
		buff[len] = '\n';
		len++;
	}
	buff[len] = '\0';
	return (buff);
}

static char	*ft_next_line(char *str)
{
	int		len;
	char	*buff;

	len = 0;
	while (str[len] != '\0' && str[len] != '\n')
		len++;
	if (!str[len])
		return (free(str), NULL);
	buff = malloc(sizeof(char) * (ft_strlens(str) - len + 1));
	if (!buff)
		return (free(str), NULL);
	len++;
	ft_strcpy(buff, &str[len]);
	return (free(str), buff);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_reads(fd, str);
	if (!str)
		return (NULL);
	s = ft_print(str);
	str = ft_next_line(str);
	return (s);
}
