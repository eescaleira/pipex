/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:14:18 by eescalei          #+#    #+#             */
/*   Updated: 2024/02/03 14:27:12 by eescalei         ###   ########.fr       */
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
	close_t(pipex);
	exit(5);
}
void	close_t(t_pipe *pipex)
{
	close(pipex->fdin);
	close(pipex->fdout);
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