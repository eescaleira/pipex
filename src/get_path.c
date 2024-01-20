/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:00:49 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/20 18:52:47 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void get_path(t_pipe *pipex, char **envp)
{
	int	i;

	i = 0;
	while(envp[i] != NULL)
	{
		if(ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			ft_splitt(&(pipex->path), envp[i] + 5, ':');
			ft_printf("path:[0] %s\n", pipex->path[0]);
			ft_printf("path:[1] %s\n", pipex->path[1]);
			ft_printf("path:[2] %s\n", pipex->path[2]);
			ft_printf("path:[3] %s\n", pipex->path[3]);
			ft_printf("path:[4] %s\n", pipex->path[4]);
			ft_printf("path:[5] %s\n", pipex->path[5]);
			ft_printf("path:[6] %s\n", pipex->path[6]);
			ft_printf("path:[7] %s\n", pipex->path[7]);
			ft_printf("path:[8] %s\n", pipex->path[8]);
			break ;
		}
		i++;
	}
	if(pipex->path == NULL)
	{
		ft_printf("Error getting path\n");
		exit(1);
	}
}
