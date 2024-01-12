/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 07:45:18 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/12 01:00:00 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "my_library/lib.h"

typedef struct s_pipex
{
	int	fd[2];
	int	id;
	
}	t_pipe;

int		main(int ac, char **argv);
void	create_pipe(t_pipe *pipex);

#endif