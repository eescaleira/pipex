/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 07:45:18 by eescalei          #+#    #+#             */
/*   Updated: 2024/02/01 12:31:23 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./my_library/lib.h"

typedef struct s_pipex
{
	int		fdin;
	int		fdout;
	pid_t 	pid1;
	pid_t	pid2;
	int		pipe[2];
	char	**path;
	char 	**cmd;
	char	*cmd_path;
	
}	t_pipe;

int		main(int ac, char **argv, char **envp);
void	create_descriptors(t_pipe *pipex, char **argv, char **envp, int ac) ;
void	get_cmds(t_pipe *pipex, char *cmd);
void	get_path(t_pipe *pipex, char **envp);
int		ft_splitt(char ***strs , char *s, char c);
void	process_1(t_pipe *pipex, char *cmd, char **envp);
void	process_2(t_pipe *pipex, char *cmd, char **envp);
void	free_path(char **path);
void	print_error(t_pipe *pipex, char *str);
void	close_t(t_pipe *pipex);

#endif