/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 00:00:49 by eescalei          #+#    #+#             */
/*   Updated: 2024/01/15 18:23:21 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/pipex.h"

// int	ft_size_word(char const *s, char c, int i)
// {
// 	int	size;

// 	size = 0;
// 	while (s[i] != c && s[i])
// 	{
// 		size++;
// 		i++;
// 	}
// 	return (size);
// }

// int	ft_count_word(char const *s, char c)
// {
// 	int	i;
// 	int	word;

// 	i = 0;
// 	word = 0;
// 	while (s && s[i])
// 	{
// 		if (s[i] != c)
// 		{
// 			word++;
// 			while (s[i] != c && s[i])
// 				i++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (word);
// }

void get_path(t_pipe *pipex, char **envp)
{
	int	i;

	i = 0;
	while(envp[i] != NULL)
	{
		if(ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			ft_split(envp[i] + 5, ':');
			printf("path: %s\n", pipex->path[0]);
			printf("path: %s\n", pipex->path[1]);
			printf("path: %s\n", pipex->path[2]);
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
