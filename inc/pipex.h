/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 07:45:18 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/12 18:39:10 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./my_library/lib.h"

typedef struct s_cmd
{
	char	*arg;
	char	*main_cmd;
	char	**flags;
}	t_cmd;


typedef struct s_pipex
{
	int	fd[2];	
	t_cmd **cmd;
	
}	t_pipe;

int		main(int ac, char **argv, char **env);
void	create_pipe(t_pipe *pipex);

#endif