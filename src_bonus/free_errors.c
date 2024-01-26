/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:14:18 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/26 20:40:55 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void print_error(t_pipe *pipex, char *str)
{
	ft_printf("%s\n", str);
	if(pipex->path)
		free_path(pipex->path);
	free(pipex->pid);
	if(pipex->cmd)
		free_path(pipex->cmd);
	if(pipex->cmd_path)
		free(pipex->cmd_path);
	if(str != "Error: command not found\n")
		close_t(pipex);
	exit(5);
}
void	close_t(t_pipe *pipex)
{
	close(pipex->fdin);
	close(pipex->fdout);
	close(pipex->pipeW[0]);
	close(pipex->pipeW[1]);
	close(pipex->pipeR[0]);
	close(pipex->pipeR[1]);
}

void	free_path(char **path)
{
	int i; 

	i = 0;
	while (path[i] != NULL)
	{
		free(path[i]);
		i++;
	}
	free(path);
}