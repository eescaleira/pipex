/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:59:14 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/20 19:12:59 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int check_flags(char *str)
{
	int i;

	i = 0;
	if(str)
		if(str[0] == '-' && str[1] != '\0' && str[1] != ' ')
			return(1);
	return (0);
}

void separate_flags(t_pipe *pipex)
{
	int i;
	int j;
	char **flags;

	i = 0;
	j = 1;
	flags = ft_splitt(&flags, pipex->cmd[i]->arg, ' ');
	while(pipex->cmd[i])
	{
		pipex->cmd[i]->main_cmd = flags[0];
		while(check_flags(flags[j]) > 0)
		{
			
		}
	}
}
