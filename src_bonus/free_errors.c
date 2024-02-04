/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:14:18 by eescalei          #+#    #+#             */
/*   Updated: 2024/02/04 16:14:59 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	print_error(t_pipe *pipex)
{
	if (pipex->path)
		free_path(pipex->path);
	free(pipex->pid);
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
	int	i;

	i = 0;
	while (path[i] != NULL)
	{
		free(path[i]);
		i++;
	}
	free(path);
}
