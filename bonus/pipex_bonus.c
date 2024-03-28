/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:10:02 by rkrechun          #+#    #+#             */
/*   Updated: 2024/03/28 18:26:20 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	create_pipe(t_pipexbonus *ppxb)
{
	int	i;

	i = 0;
	while (i < ppxb->cmd_nbr - 1)
	{
		if (pipe(ppxb->pipe + 2 * i) < 0)
			parent_free(ppxb);
		i++;
	}
}

void	close_pipe(t_pipexbonus *ppxb)
{
	int	i;

	i = 0;
	while (i < (ppxb->pipe_nbr))
	{
		close(ppxb->pipe[i]);
		i++;
	}
}

int	main(int argc, char *argv[], char *env[])
{
	t_pipexbonus	ppxb;

	if (argc < arguments_check(argv[1], &ppxb))
		return (msg(ERR_INPUT));
	get_infile(argv, &ppxb);
	get_outfile(argv[argc - 1], &ppxb);
	ppxb.cmd_nbr = argc - 3 - ppxb.here_doc;
	ppxb.pipe_nbr = 2 * (ppxb.cmd_nbr - 1);
	ppxb.pipe = (int *)malloc(sizeof(int) * ppxb.pipe_nbr);
	if (!ppxb.pipe)
		msg_error(ERR_PIPE);
	ppxb.evn_paths = get_path(env);
	ppxb.cmd_path = ft_split(ppxb.evn_paths, ':');
	if (!ppxb.cmd_path)
		pipe_free(&ppxb);
	create_pipe(&ppxb);
	ppxb.index = -1;
	while (++(ppxb.index) < ppxb.cmd_nbr)
		child(ppxb, argv, env);
	close_pipe(&ppxb);
	waitpid(-1, NULL, 0);
	parent_free(&ppxb);
	return (0);
}
