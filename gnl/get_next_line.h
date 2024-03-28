/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:40:04 by rkrechun          #+#    #+#             */
/*   Updated: 2024/03/28 11:43:54 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

//get next line
char		*get_next_line(int fd);

//utilis to get next line
size_t		ft_strlen(char *s);
char		*ft_strchr(char *s, int c);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strjoin(char *str, char *buffer);


# endif