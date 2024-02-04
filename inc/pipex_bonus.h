/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 07:45:18 by eescalei          #+#    #+#             */
/*   Updated: 2024/02/04 16:36:49 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./my_library/lib.h"

typedef struct s_pipex
{
	int		fdin;
	int		fdout;
	pid_t 	*pid;
	char	**path;
	int		cmd_count;
	char 	**cmd;
	char	*cmd_path;
	int		i;
	
}	t_pipe;

int		main(int ac, char **argv, char **envp);

void	execute(t_pipe *pipex, char *cmd, char **envp, int (*fd)[2]);

void	process_1(t_pipe *pipex, char *cmd, char **envp, int (*fd)[2]);
void	process_2(t_pipe *pipex, char *cmd, char **envp, int (*fd)[2]);
void	process_3(t_pipe *pipex, char *cmd, char **envp, int (*fd)[2]);
void	processes(t_pipe *pipex, char **argv, char **envp, int cmd_count);

void	create_descriptors(t_pipe *pipex, char **argv, char **envp, int ac) ;
void	create_pipe(t_pipe *pipex, int cmd_count, int (*fd)[2]);
void	manage_pipes(int cmd_count, int (*fd)[2], int i);

void	get_cmds(t_pipe *pipex);
void	get_path(t_pipe *pipex, char **envp);

int		ft_splitt(char ***strs , char *s, char c);

void	free_path(char **path);
void	print_error(t_pipe *pipex);
void	close_t(t_pipe *pipex);


#endif