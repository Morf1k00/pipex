/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:10:02 by rkrechun          #+#    #+#             */
/*   Updated: 2024/03/28 15:05:58 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

void create_pipe(t_pipexbonus *ppxb)
{
	int i;

	i = 0;
	while(i < ppxb->cmd_nbr - 1)
	{
		if (pipe(ppxb->pipe + 2 * i) < 0)
			parent_free(ppxb);
		i++;
	}
}

void close_pipe(t_pipexbonus *ppxb)
{
	int i;

	i = 0;
	while (i< ppxb->pipe_nbr)
	{
		close(ppxb->pipe[i]);
		i++;
	}
}

int main(int argc, char *argv[], char *envp[])
{
	t_pipexbonus	ppxb;

	if(argc < arguments_check(argv[1], &ppxb))
		return(msg(ERR_INPUT));
	get_infile(argv, &ppxb);
	get_outfile(argv[argc - 1], &ppxb);
	ppxb.cmd_nbr = argc - 3 - ppxb.here_doc;
	ppxb.pipe_nbr = (ppxb.cmd_nbr - 1) * 2;
	ppxb.pipe = (int *)malloc(sizeof(int) * ppxb.pipe_nbr);
	if (ppxb.pipe == NULL)
		msg_error(ERR_PIPE);
	ppxb.evn_paths = get_path(envp);
	ppxb.cmd_path = ft_split(ppxb.evn_paths, ':');
	if(!ppxb.cmd_path)
		pipe_free(&ppxb);
	create_pipe(&ppxb);
	ppxb.index = -1;
	while(++(ppxb.index) < ppxb.cmd_nbr)
		child(ppxb, argv, envp);
	close_pipe(&ppxb);
	waitpid(-1, NULL, 0);
	parent_free(&ppxb);
	return(0);
}