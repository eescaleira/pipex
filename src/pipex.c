
#include "pipex.h"

char *find_path_env(char **envp)
{
	while(ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

int main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	if (argc != 5)
		return 0;
	pipex.infile = open(argv[1], O_RDWR);
	if (pipex.infile < 0)
		return 0; 
	pipex.outfile = open(argv[argc -1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.outfile < 0)
		return 0; 
	if(pipe(pipex.tube) < 0)
		return 0;
	pipex.paths = find_path_env(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		child1(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		child2(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	free_parent(&pipex);
	return 0;
}
