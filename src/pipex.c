/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:11:31 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/12 19:02:43 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/pipex.h"

void get_cmds(t_pipe *pipex, int ac, char **argv)
{
	int i = 0;
	
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
}

void create_pipe(t_pipe *pipex)
{
	if (pipe(pipex->fd) == -1)
	{
		ft_printf("Error creating pipe\n");
		exit(1);
	}
}

int	main(int ac, char **argv, char **env)
{
	t_pipe	pipex;
	if(env == NULL || argv == NULL)
	{
		ft_printf("Error getting env\n");
		exit(1);
	}
	create_pipe(&pipex);
	get_cmds(&pipex, ac, argv);
	return 0;
}