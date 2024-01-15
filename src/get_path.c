/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:00:49 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/15 00:04:06 by eescalei         ###   ########.fr       */
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
			pipex->path = ft_split(envp[i] + 5, ':');
			// printf("path: %s\n", pipex->path);
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