/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:10:02 by rkrechun          #+#    #+#             */
/*   Updated: 2024/03/21 17:16:40 by rkrechun         ###   ########.fr       */
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

int main(int argc, char *argv[], char *envp[])
{
	t_pipexbonus	ppxb;

	if(argc < arguments_check(argv[1], &ppxb))
		return(ERR_INPUT);
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
}