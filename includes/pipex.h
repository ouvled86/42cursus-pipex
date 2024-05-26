/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:51:30 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/26 14:42:55 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "libft.h"

typedef struct s_files
{
	int	fd1;
	int	fd2;
}		t_files;

typedef struct s_cmds
{
	char	*cmd1;
	char	*cmd2;
	char	**fcmd1;
	char	**fcmd2;
}			t_cmds;

void	close_all(int *pipe, t_files files);
void	free_cmds(t_cmds *cmds);

void	exec_one(int *pfd, t_files fds, t_cmds *cmds, char **envp);
void	exec_two(int *pfd, t_files fds, t_cmds *cmds, char **envp);

void	check_args(int ac);
char	**extract_paths(char *s);
t_cmds	*check_cmds(char **envp, char *cmd1, char *cmd2);
char	*find_path(char **pl, char *cmd);

int		safe_fork(void);
t_files	safe_open(char *f1, char *f2);
void	safe_close(int fd);
void	safe_dup2(int newfd, int oldfd);

#endif

// ERROR CODES
// MALLOC ERR = 9
// ACCESS ERR = 14
// CLOSE ERR = 30
// OPEN ERR = 33
// PIPE ERR = 43
// DUP ERR = 50