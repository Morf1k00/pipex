/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:10:00 by rkrechun          #+#    #+#             */
/*   Updated: 2024/03/28 14:25:05 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void child_free(t_pipexbonus *pipex)
{
	int	i;

	i = 0;
	while(pipex->cmd_path[i])
	{
		free(pipex->cmd_path[i]);
		i++;
	}
	free(pipex->cmd_path);
	free(pipex->cmd);
}


void pipe_free(t_pipexbonus *ppxb)
{
	close(ppxb->infile);
	close(ppxb->outfile);
	if (ppxb->here_doc)
		unlink(".heredoc_tmp");
	free(ppxb->pipe);
	msg(ERR_ENV);
	exit(1);
}

void parent_free(t_pipexbonus *ppxb)
{
	int i;

	i = 0;
	close(ppxb->infile);
	close(ppxb->outfile);
	if(ppxb->here_doc)
		unlink(".heredoc_tmp");
	while(ppxb->cmd_path[i])
	{
		free(ppxb->cmd_path[i]);
		i++;
	}
	free(ppxb->cmd_path);
	free(ppxb->pipe);
}
