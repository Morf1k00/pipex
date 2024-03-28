/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:09:58 by rkrechun          #+#    #+#             */
/*   Updated: 2024/03/28 16:46:41 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	msg(char *n)
{
	write(2, n, ft_strlen(n));
	return (1);
}

void	msg_error(char *n)
{
	perror(n);
	exit(1);
}

void	msg_pipe(char *n)
{
	write(2, ERR_CMD, ft_strlen(ERR_CMD));
	write(2, n, ft_strlen(n));
	write(2, "\n", 1);
}
