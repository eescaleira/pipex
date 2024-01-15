/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 07:45:18 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/15 00:21:01 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./my_library/lib.h"

typedef struct s_cmd
{
	char	*arg;
	char	*main_cmd;
	char	**flags;
}	t_cmd;


typedef struct s_pipex
{
	int		fd[2];
	int		pid;
	char	**path;
	t_cmd 	**cmd;
	
}	t_pipe;

int		main(int ac, char **argv, char **envp);
void	create_pipe(t_pipe *pipex);
void	get_cmds(t_pipe *pipex, int ac, char **argv);
void	get_path(t_pipe *pipex, char **envp);

#endif