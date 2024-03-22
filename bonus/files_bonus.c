/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:28:42 by rkrechun          #+#    #+#             */
/*   Updated: 2024/03/21 16:50:31 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

char get_path(char **evnp)
{
	while(ft_strncmp("PATH=", *evnp, 5))
		evnp++;
	return (*evnp + 5);
}

void	get_infile(char **argv, t_pipexbonus *ppxb)
{
	if (ft_strncmp("here_doc", argv[1], 9) == 0)
		here_doc(argv[2], ppxb);
	else
	{
		ppxb->infile = open(argv[1], O_RDONLY);
		if(ppxb->infile < 0)
			msg_error(ERR_INFILE);
	}
}

void get_outfile(char *argv, t_pipexbonus *ppxb)
{
	if (ppxb->here_doc)
		ppxb->outfile = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		ppxb->outfile = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (ppxb->outfile < 0)
		msg_error(ERR_OUTFILE);
}