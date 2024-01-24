/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:00:49 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/24 23:20:14 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void get_cmds(t_pipe *pipex, char *cmd)
{
	int i;
	char *path;
	char *cmd_path;
	
	i = 0;
	while (pipex->path[i] != NULL)
	{
		path = ft_strjoin(pipex->path[i], "/");
		printf("path: %s\n", path);
		cmd_path = ft_strjoin(path, pipex->cmd[0]);
		if(access(cmd_path, X_OK) == 0)
		{
			pipex->cmd_path = cmd_path;
			break ;
		}
		i++;
	}
	printf("cmd_path: %s\n", pipex->cmd_path);
}

void process_1(t_pipe *pipex, char *cmd, char **envp)
{
	dup2(pipex->fdin, 0);
	close(pipex->pipe[0]);
	dup2(pipex->pipe[1], 1);
	ft_splitt(&pipex->cmd, cmd, ' ');
	get_cmds(pipex, cmd);
	if(!pipex->cmd_path || !pipex->cmd)
	{
		ft_printf("Error: command not found\n");
		exit(1);
	}
	execve(pipex->cmd_path, pipex->cmd, envp);
}

void process_2(t_pipe *pipex, char *cmd, char **envp)
{
	dup2(pipex->pipe[0], 0);
	close(pipex->pipe[1]);
	dup2(pipex->fdout, 1);
	ft_splitt(&pipex->cmd, cmd, ' ');
	get_cmds(pipex, cmd);
	if(!pipex->cmd_path || !pipex->cmd)
	{
		ft_printf("Error: command not found\n");
		exit(1);
	}
	execve(pipex->cmd_path, pipex->cmd, envp);
}