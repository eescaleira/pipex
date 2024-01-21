/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:59:14 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/21 18:19:59 by eescalei         ###   ########.fr       */
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
int count_flags(char **flags)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while(flags[i])
	{
		if(check_flags(flags[i]) == 1)
			count++;
		i++;
	}
	return (count - 1);
}
void separate_flags(t_pipe *pipex)
{
	int i;
	int j;
	int c;
	int flag_count;
	int cmd_count;
	char **flags;

	i = 0;
	cmd_count = 0;
	// flags = NULL;
	while (pipex->cmd[cmd_count]->arg)
		cmd_count++;
	while (i < cmd_count)
	{
		ft_splitt(&flags, pipex->cmd[i]->arg, ' ');
		pipex->cmd[i]->main_cmd = flags[0];
		// printf("main_cmd: %s\n", pipex->cmd[i]->main_cmd);
		flag_count = 0;
		j = 1;
		while(flags[j])
		{
			if(check_flags(flags[j]))
				flag_count++;
				j++; 
		}
		if(flag_count > 0)
		{	
			pipex->cmd[i]->flags = malloc(sizeof(char *) * (flag_count + 1));
			j = 1;
			c = 1;
			while (flags[j])
			{
				if(check_flags(flags[j]))
				{
					pipex->cmd[i]->flags[j - 1] = flags[c];
					c++;
				}
				j++;
			}	
			pipex->cmd[i]->flags[j - 1] = NULL;
		}
		else
			pipex->cmd[i]->flags = NULL;
		i++;
	}	
}
