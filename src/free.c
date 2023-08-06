
#include "pipex.h"


void close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

void free_child(t_pipex *pipex)
{
	int i;

	i = 0;
	while(pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
	free(pipex->cmd);
}

void free_parent(t_pipex *pipex)
{
	int i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while(pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
}