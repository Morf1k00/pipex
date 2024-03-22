/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:05:55 by rkrechun          #+#    #+#             */
/*   Updated: 2024/03/21 16:37:39 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int arguments_check(char args, t_pipexbonus *ppxb)
{
	if (ft_strncmp(args, "here_doc", 9) == 0)
	{
		ppxb->here_doc = 1;
		return (6);
	}
	else
	{
		ppxb->here_doc = 0;
		return(5);
	}
}