/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:11:31 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/21 18:22:21 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/pipex.h"

void get_cmds(t_pipe *pipex, int ac, char **argv)
{
	int i;
	
	i = 0;
	pipex->cmd = malloc(sizeof(t_cmd) * (ac - 2));
	while (i <= ac - 4)
	{
		pipex->cmd[i] = malloc(sizeof(t_cmd));
		pipex->cmd[i]->arg = malloc(sizeof(char) * ft_strlen(argv[i + 2]));
		pipex->cmd[i]->arg = argv[i + 2];
		ft_printf("cmd: %s\n", pipex->cmd[i]->arg);
		i++;
	}
	pipex->cmd[i] = malloc(sizeof(t_cmd));
	pipex->cmd[i]->arg = NULL;
	separate_flags(pipex);
	i = 0;
	while(pipex->cmd[i]->arg != NULL)
	{
		int j = 0;
		// ft_printf("cmd: %s\n", pipex->cmd[i]->main_cmd);
		if(pipex->cmd[i]->flags != NULL)
		{
			while(pipex->cmd[i]->flags[j] != NULL)
			{
				// ft_printf("flag: %s\n", pipex->cmd[i]->flags[j]);
				j++;
			}
		}
		i++;
	}
}

void create_pipe(t_pipe *pipex) // exit (0) is not an apropriate way to exit
{
	if (pipe(pipex->fd) == -1)
	{
		ft_printf("Error creating pipe\n");
		exit(1);
	}
}

int	main(int ac, char **argv, char **envp)
{
	t_pipe	pipex;
	if(envp == NULL || argv == NULL || ac != 5)
	{
		ft_printf("Error getting env\n");
		exit(1);
	}
	get_path(&pipex, envp);
	get_cmds(&pipex, ac, argv);
	// create_pipe(&pipex);
	// pipex.pid = fork();
	// if (pipex.pid == -1)
	// {
		// ft_printf("Error creating fork\n");
		// exit(1);
	// }

	return 0;
}