
#include "pipex.h"

char *get_cmd(char **paths, char *cmd)
{
	char *temp;
	char *command;

	while(*paths)
	{
		temp = ft_strjoin(*paths, "/");
		command = ft_strjoin(temp, cmd);
		if(access(command, 0) == 0)
			return(command);
		free(command);
		paths++;
	}
	return(NULL);
}

void child1(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[1], 1);
	close(pipex.tube[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if(!pipex.cmd)
	{
		free_child(&pipex);
		exit (1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}

void child2(t_pipex pipex, char **argv, char **envp)
{
	dup2(pipex.tube[0], 0);
	close(pipex.tube[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if(!pipex.cmd)
	{
		free_child(&pipex);
		exit (1);
	}
	execve(pipex.cmd, pipex.cmd_args, envp);
}
