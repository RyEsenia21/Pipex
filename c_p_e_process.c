/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_p_e_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:35:37 by ryesenia          #+#    #+#             */
/*   Updated: 2022/03/16 20:30:49 by ryesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parent_process(int end[2], char **argv)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 00774);
	if (fd < 0)
	{
		perror(argv[4]);
		exit(2);
	}
	if (dup2(fd, STDOUT) < 0)
		perror("Couldn't write to the file");
	if (dup2(end[0], STDIN) < 0)
		perror("Couldn't read from the pipe");
	close(fd);
	close(end[0]);
	close(end[1]);
}

void	child_process(int end[2], char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror(argv[1]);
		exit(1);
	}
	if (dup2(fd, STDIN) < 0)
		perror("Couldn't read from the file");
	if (dup2(end[1], STDOUT) < 0)
		perror("Couldn't write to the pipe");
	close(end[0]);
	close(end[1]);
}

void	execute_process(char **envp, char *argv, int i)
{
	char	*path;
	char	**dv;
	char	**cmd;
	char	*str;
	char	*str2;

	path = envp[i] + 5;
	dv = ft_split(path, ':');
	cmd = ft_split(argv, ' ');
	while (*dv)
	{
		str = ft_strjoin(*dv, "/");
		str2 = ft_strjoin(str, cmd[0]);
		execve(str2, cmd, envp);
		dv++;
		free(str);
		free(str2);
	}
}
