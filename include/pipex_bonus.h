/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 13:09:53 by rkrechun          #+#    #+#             */
/*   Updated: 2024/03/28 14:22:03 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "../gnl/get_next_line.h"

# define ERR_INFILE "INFILE"
# define ERR_OUTFILE "OUTFILE"
# define ERR_PIPE "PIPE"
# define ERR_INPUT "INVALID NUMBER OF ARGUMENTS.\n"
# define ERR_CMD "COMAND NOT FOUND\n"
# define ERR_HEREDOC "here doc"
# define ERR_ENV "Enviroment"


typedef struct s_pipexbonus
{
	pid_t	pid;
	int		infile;
	int		outfile;
	int		index;
	int		*pipe;
	int		pipe_nbr;
	int		here_doc;
	int		cmd_nbr;
	char	*cmd;
	char	*evn_paths;
	char	**cmd_path;
	char	**cmd_args;
}				t_pipexbonus;

int 		arguments_check(char args, t_pipexbonus *ppxb);

// function
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *s);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
char			*ft_strdup(const char *src);

#endif