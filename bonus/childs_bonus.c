/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:09:28 by rkrechun          #+#    #+#             */
/*   Updated: 2024/03/28 11:31:53 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void dups2(int zero, int one)
{
	dup2(zero, 0);
	dup2(one, 1);
}

static char *get_command(char **path, char *cmd)
{
	char *tmp;
	char *command;

	while(*path)
	{
		tmp = ft_strjoin(*path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
			return(command);
		free(command);
		path++;
	}
	return(NULL);
}

void child(t_pipexbonus ppxb, char *argv[], char *envp[])
{
	ppxb.pid = fork();
	if(!ppxb.pid)
	{
		if (ppxb.pid == 0)
			dups2(ppxb.infile, ppxb.pipe[1]);
		else if(ppxb.index == ppxb.cmd_nbr - 1)
			dups2(ppxb.pipe[2 * ppxb.index - 2], ppxb.outfile);
		else
			dups2(ppxb.pipe[2 * ppxb.index - 2], ppxb.pipe[2 * ppxb.index + 1]);
		close_pipes(&ppxb);	
		ppxb.cmd_args = ft_split(argv[2 + ppxb.here_doc + ppxb.index], ' ');
		ppxb.cmd = get_command(ppxb.cmd_path, ppxb.cmd_args[0]);
		if(!ppxb.cmd)
		{
			msg_pipe(ppxb.cmd_args[0]);
			child_free(&ppxb);
			exit(1);
		}
		execve(ppxb.cmd, ppxb.cmd_args, envp);
	}
}