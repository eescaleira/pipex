/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:11:31 by eescalei          #+#    #+#             */
/*   Updated: 2024/02/01 12:32:42 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/pipex.h"

void get_path(t_pipe *pipex, char **envp)
{
	int	i;

	i = 0;
	while(envp[i] != NULL)
	{
		if(ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			ft_splitt(&(pipex->path), envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	if(pipex->path == NULL)
	{
		print_error(pipex, "Error getting path\n");
		exit(1);
	}
}

void create_descriptors(t_pipe *pipex, char **argv, char **envp, int ac) 
{
	if(envp == NULL || argv == NULL || ac != 5)
		exit (1);
	pipex->fdin = open(argv[1], O_RDWR);
	if(pipex->fdin < 0)
		exit (2);
	pipex->fdout = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if(pipex->fdout < 0)
	{
		close(pipex->fdin);
		exit (2);
	}
	if (pipe(pipex->pipe) < 0)
	{
		ft_printf("Error creating pipe\n");
		close(pipex->fdin);
		close(pipex->fdout);
		exit(3);
	}
}

int	main(int ac, char **argv, char **envp)
{
	t_pipe	pipex;

	create_descriptors(&pipex, argv, envp, ac);
	get_path(&pipex, envp);
	pipex.pid1 = fork();
	if(pipex.pid1 == -1)
		print_error(&pipex, "Error creating fork\n");
	if(pipex.pid1 == 0)
		process_1(&pipex, argv[2], envp);
	pipex.pid2 = fork();
	if(pipex.pid2 == -1)
		print_error(&pipex, "Error creating fork\n");
	if(pipex.pid2 == 0)
		process_2(&pipex, argv[3], envp);
	wait(NULL); 
	free_path(pipex.path);
	// check retuned errors from execves
	return 0;
}
