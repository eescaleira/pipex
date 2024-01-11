/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eescalei <eescalei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 15:08:24 by eescalei          #+#    #+#             */
/*   Updated: 2023/12/19 23:37:19 by eescalei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_find_nl(char *s)
{
	unsigned int	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (-1);
	return (i);
}

char	*createline(char *buf_static)
{
	char	*line;
	int		i;

	if (ft_strlen(buf_static) <= 0)
		return (NULL);
	i = ft_find_nl(buf_static);
	if (i == -1 || i == ((int)ft_strlen(buf_static) - 1))
	{
		line = ft_strdup(buf_static);
		return (line);
	}
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buf_static[i] != '\n')
	{
		line[i] = buf_static[i];
		i++;
	}
	line[i] = '\n';
	line[i + 1] = '\0';
	return (line);
}

char	*createbuff(char	*buf_static)
{
	int				i;
	unsigned int	buf_len;

	if (!buf_static)
		return (NULL);
	buf_len = ft_strlen(buf_static);
	i = ft_find_nl(buf_static);
	if (i == -1 || ((buf_len - i) == 1))
	{
		free(buf_static);
		return (NULL);
	}
	buf_static = ft_substr(buf_static, (i + 1), (buf_len - i - 1));
	return (buf_static);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	int			b_read;
	static char	*buf_static[1000];

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	b_read = 0;
	while (ft_find_nl(buf_static[fd]) == -1)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read <= 0)
			break ;
		buffer[b_read] = '\0';
		buf_static[fd] = ft_strjoinn(buf_static[fd], buffer);
	}
	free(buffer);
	if (b_read == -1)
		return (NULL);
	line = createline(buf_static[fd]);
	buf_static[fd] = createbuff(buf_static[fd]);
	return (line);
}

/* int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	if(av[1] && ac)
		printf(get_next_line(fd));
	else
		printf("plese insert a file name");
	return(0);
} */