/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:31:10 by rkrechun          #+#    #+#             */
/*   Updated: 2024/03/15 15:14:14 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char *get_cmd(char **path, char *cmd)
{
	char *tmp;
	char *command;

	while(*path)
	{
		tmp = ft_strjoin(*path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, 0) == 0)
			return(command);
		free(command);
		path++;
	}
	return(NULL);
}

void fist_child(t_pipex pipex, char **argv, char **evn)
{
	dup2(pipex.tube[1], 1);
	close(pipex.tube[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_path, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		msg(ERR_PIPE);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, evn);
}

void secod_child(t_pipex pipex, char **argv, char **evn)
{
	dup2(pipex.tube[0], 0);
	close(pipex.tube[1]);
	dup2(pipex.infile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_path, pipex.cmd_args[0]);
	if (!pipex.cmd)
	{
		child_free(&pipex);
		msg(ERR_PIPE);
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_args, evn);
}