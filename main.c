/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:08:21 by ryesenia          #+#    #+#             */
/*   Updated: 2022/03/16 20:31:16 by ryesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	c_p_e(char **argv, char **envp, int i, int end[2])
{
	child_process(end, argv);
	execute_process(envp, argv[2], i);
	perror("rebenKA :)");
}

int	fork_proc(char **argv, char **envp, int i)
{
	pid_t	pid;
	int		buff;
	int		end[2];

	if (pipe(end) == -1)
		return (2);
	pid = fork();
	if (pid < 0)
	{
		perror("bad process :)");
		return (1);
	}
	if (pid != 0)
	{
		waitpid(pid, &buff, WUNTRACED);
		parent_process(end, argv);
		execute_process(envp, argv[3], i);
		perror("papanYA");
	}
	else
		c_p_e(argv, envp, i, end);
	return (0);
}

int	main(int ac, char **ag, char **envp)
{
	int			i;

	check_arg(ac);
	i = 0;
	while (envp[i] != 0)
	{
		if ((ft_strncmp("PATH=", envp[i], 5)) == 0)
			break ;
		i++;
	}
	if (fork_proc(ag, envp, i))
		return (3);
	return (0);
}
