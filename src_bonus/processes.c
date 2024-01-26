/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:00:49 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/26 20:34:24 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void execute(t_pipe *pipex, char *cmd, char **envp)
{
	ft_splitt(&pipex->cmd, cmd, ' ');
	if(!pipex->cmd)
		print_error(pipex, "Error: command not found\n");
	get_cmds(pipex, cmd);
	execve(pipex->cmd_path, pipex->cmd, envp);
}
void get_cmds(t_pipe *pipex, char *cmd)
{
	int i;
	char *path;
	char *cmd_path;
	
	i = 0;
	pipex->cmd_path = NULL;
	while (pipex->path[i] != NULL)
	{
		path = ft_strjoin(pipex->path[i], "/");
		printf("path: %s\n", path);
		cmd_path = ft_strjoin(path, pipex->cmd[0]);
		if(access(cmd_path, X_OK) == 0)
		{
			pipex->cmd_path = cmd_path;
			free(path);
			return ;
		}
		free(path);
		free(cmd_path);
		i++;
	}
	if(pipex->cmd_path == NULL)
		print_error(pipex, "Error: command not found\n");
	
}

void process_1(t_pipe *pipex, char *cmd, char **envp)
{
	dup2(pipex->fdin, 0);
	close(pipex->pipeR[0]);
	close(pipex->pipeR[1]);
	close(pipex->pipeW[0]);
	dup2(pipex->pipeW[1], 1);
	execute(pipex, cmd, envp);
}

void process_2(t_pipe *pipex, char *cmd, char **envp)
{
	dup2(pipex->pipeW[0], 0);
	close(pipex->pipeW[1]);
	close(pipex->pipeR[0]);
	close(pipex->pipeR[1]);
	dup2(pipex->fdout, 1);
	execute(pipex, cmd, envp);
}

void process_2b(t_pipe *pipex, char *cmd, char **envp)
{
	dup2(pipex->pipeR[0], 0);
	close(pipex->pipeW[0]);
	close(pipex->pipeW[1]);
	close(pipex->pipeR[1]);
	dup2(pipex->fdout, 1);
	execute(pipex, cmd, envp);
}

void	process_3(t_pipe *pipex, char *cmd, char **envp)
{
	dup2(pipex->pipeW[0], 0);
	dup2(pipex->pipeR[1], 1);
	close(pipex->pipeW[1]);
	close(pipex->pipeR[0]);
	execute(pipex, cmd, envp);
}

void	process_4(t_pipe *pipex, char *cmd, char **envp)
{
	dup2(pipex->pipeR[0], 0);
	dup2(pipex->pipeW[1], 1);
	close(pipex->pipeW[0]);
	close(pipex->pipeR[1]);
	execute(pipex, cmd, envp);
}

void	middle_processes(t_pipe *pipex, char **argv, char **envp, int cmd_count)
{
	int i;

	i = 1;
	while(cmd_count > i)
	{
		pipex->pid[i] = fork();
		if(pipex->pid[i] == -1)
			print_error(pipex, "Error creating fork\n");
		if(pipex->pid[i] == 0)
		{
			if((i % 2) == 0)
				process_3(pipex, argv[i], envp);
			else
				process_4(pipex, argv[i], envp);
		}
		i++;
	}
	pipex->pid[i] = fork();
	if(pipex->pid[i] == -1)
		print_error(pipex, "Error creating fork\n");
	if(pipex->pid[i] == 0)
	{
		if(cmd_count == 1)
			process_2(pipex, argv[i], envp);
		else
		{
			if(cmd_count % 2 == 0)
				process_2(pipex, argv[i], envp);
			else
				process_2b(pipex, argv[i], envp);
		}
	}
}