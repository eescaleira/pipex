/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:11:31 by eescalei          #+#    #+#             */
/*   Updated: 2024/02/03 18:15:11 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	create_descriptors(t_pipe *pipex, char **argv, char **envp, int ac)
{
	pipex->cmd_count = ac -3;
	if (envp == NULL || argv == NULL || ac < 5)
		exit (1);
	pipex->fdin = open(argv[1], O_RDWR);
	printf("%i" , pipex->fdin);
	if (pipex->fdin <= 0)
		exit (2);
	pipex->fdout = open(argv[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (pipex->fdout <= 0)
	{
		close(pipex->fdin);
		exit (2);
	}
	pipex->pid = malloc((ac - 2) * sizeof(int));
	if (pipex->pid == NULL)
	{
		close(pipex->fdin);
		close(pipex->fdout);
		exit(3);
	}
	pipex->pid[ac - 2] = 0;
}

int	main(int ac, char **argv, char **envp)
{
	t_pipe	pipex;

	create_descriptors(&pipex, argv, envp, ac);
	get_path(&pipex, envp);
	processes(&pipex, argv, envp, ac -3);
	free_path(pipex.path);
	wait(NULL);
	return (0);
}
