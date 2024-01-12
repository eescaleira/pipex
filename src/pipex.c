/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:11:31 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/12 01:09:20 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/pipex.h"
# include <stdio.h>

void create_pipe(t_pipe *pipex)
{
	if (pipe(pipex->fd) == -1)
	{
		ft_printf("Error creating pipe\n");
		exit(1);
	} 	
}

int	main(int ac, char **argv)
{
	t_pipe	pipex;
	create_pipe(&pipex);
	return 0;
}