/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:00:49 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/29 19:30:30 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void execute(t_pipe *pipex, char *cmd, char **envp)
{
	ft_splitt(&pipex->cmd, cmd, ' ');
	get_cmds(pipex, cmd);
	if(!pipex->cmd)
		print_error(pipex, "Error: command not found\n");
	execve(pipex->cmd_path, pipex->cmd, envp);
}

void process_1(t_pipe *pipex, char *cmd, char **envp, int cmd_count, int fd[cmd_count][2], int i)
{
	close(pipex->fdout);
	manage_pipes(pipex, cmd_count, fd, i);
	dup2(pipex->fdin, 0);
	execute(pipex, cmd, envp);
}

void	process_2(t_pipe *pipex, char *cmd, char **envp, int cmd_count, int fd[cmd_count][2], int i)
{
	close(pipex->fdin);
	close(pipex->fdout);
	manage_pipes(pipex, cmd_count, fd, i);
	execute(pipex, cmd, envp);
}

void process_3(t_pipe *pipex, char *cmd, char **envp, int cmd_count, int fd[cmd_count][2], int i)
{
	close(pipex->fdin);
	manage_pipes(pipex, cmd_count, fd, i);
	dup2(pipex->fdout, 1);
	execute(pipex, cmd, envp);
}

void	processes(t_pipe *pipex, char **argv, char **envp, int cmd_count)
{
	int i;
	int fd[cmd_count - 1][2];

	create_pipe(pipex, cmd_count - 1, fd);
	pipex->pid[0] = fork();
	if(pipex->pid[0] == -1)
		print_error(pipex, "Error creating fork\n");
	if(pipex->pid[0] == 0)
	{
		process_1(pipex, argv[2], envp, cmd_count, fd, 0);
		waitpid(pipex->pid[0], NULL, 0);
	}
	i = 1;
	while((cmd_count - 1) > i)
	{
		pipex->pid[i] = fork();
		if(pipex->pid[i] == -1)
			print_error(pipex, "Error creating fork\n");
		if(pipex->pid[i] == 0)
		{
			process_2(pipex, argv[i + 2], envp, cmd_count, fd, i);
			waitpid(pipex->pid[i], NULL, 0);
		}
		i++;
	}
	pipex->pid[i] = fork();
	if(pipex->pid[i] == -1)
		print_error(pipex, "Error creating fork\n");
	if(pipex->pid[i] == 0)
	{
		process_3(pipex, argv[i + 2], envp, cmd_count, fd, i);
		waitpid(pipex->pid[i], NULL, 0);
	}
}
