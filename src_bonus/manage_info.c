/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:29:08 by eescalei          #+#    #+#             */
/*   Updated: 2024/02/03 17:19:44 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	get_cmds(t_pipe *pipex)
{
	int		i;
	char	*path;
	char	*cmd_path;

	i = 0;
	pipex->cmd_path = NULL;
	while (pipex->path[i] != NULL)
	{
		path = ft_strjoin(pipex->path[i], "/");
		cmd_path = ft_strjoin(path, pipex->cmd[0]);
		if (access(cmd_path, X_OK) == 0)
		{
			pipex->cmd_path = cmd_path;
			free(path);
			return ;
		}
		free(path);
		free(cmd_path);
		i++;
	}
}

void	manage_pipes(int cmd_count, int (*fd)[2], int i)
{
	int	j;

	j = 0;
	while (j < cmd_count)
	{
		if (j != i)
		{
			if (j != i - 1)
			{
				close(fd[j][0]);
				close(fd[j][1]);
			}
			else
				close(fd[j][1]);
		}
		else
			close(fd[j][0]);
		j++;
	}
}

void	create_pipe(t_pipe *pipex, int cmd_count, int (*fd)[2])
{
	int	i;

	i = 0;
	while (i < cmd_count)
	{
		if (pipe(fd[i]) < 0)
		{
			ft_printf("Error creating pipe\n");
			close(pipex->fdin);
			close(pipex->fdout);
			exit(3);
		}
		i++;
	}
}

void	get_path(t_pipe *pipex, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			ft_splitt(&(pipex->path), envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	if (pipex->path == NULL)
		print_error(pipex, "Error getting path\n");
}
