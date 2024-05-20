/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:22:13 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/20 16:44:27 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	exec_one(int *pfd, t_files fds, t_cmds *cmds)
{
	if (close(fds.fd2) < 0)
	{
		perror("pipex");
		exit(30);
	}
	if (close(pfd[0]) < 0)
	{
		perror("pipex");
		exit(30);
	}
	dup2(fds.fd1, 0);
	dup2(pfd[1], 1);
	if (close(fds.fd1) < 0)
	{
		perror("pipex");
		exit(30);
	}
	if (close(pfd[1]) < 0)
	{
		perror("pipex");
		exit(30);
	}
	execve(cmds->cmd1, cmds->fcmd1, NULL);
}

void	exec_two(int *pfd, t_files fds, t_cmds *cmds)
{
	int i = -1;
	while (cmds->fcmd2[++i])
		ft_printf("%s\n", cmds->fcmd2[i]);
	if (close(fds.fd1) < 0)
	{
		perror("pipex");
		exit(30);
	}
	if (close(pfd[1]) < 0)
	{
		perror("pipex");
		exit(30);
	}
	dup2(pfd[0], 0);
	dup2(fds.fd2, 1);
	if (close(pfd[0]) < 0)
	{
		perror("pipex");
		exit(30);
	}
	if (close(fds.fd2) < 0)
	{
		perror("pipex");
		exit(30);
	}
	execve(cmds->cmd2, cmds->fcmd2, NULL);
}
