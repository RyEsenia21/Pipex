/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryesenia <ryesenia@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:35:47 by ryesenia          #+#    #+#             */
/*   Updated: 2022/03/16 20:30:38 by ryesenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define STDOUT 1
# define STDIN 0
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void			check_arg(int argc);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
void			parent_process(int end[2], char **argv);
void			child_process(int fdp[2], char **argv);
void			execute_process(char **envp, char *argv, int i);
int				fork_proc(char **argv, char **envp, int i);
void			c_p_e(char **argv, char **envp, int i, int end[2]);
char			**ft_split(char const *s, char c);

#endif