/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:22:13 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/26 13:21:32 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	exec_one(int *pfd, t_files fds, t_cmds *cmds, char **envp)
{
	safe_close(fds.fd2);
	safe_close(pfd[0]);
	safe_dup2(fds.fd1, STDIN_FILENO);
	safe_dup2(pfd[1], STDOUT_FILENO);
	safe_close(fds.fd1);
	safe_close(pfd[1]);
	execve(cmds->cmd1, cmds->fcmd1, envp);
}

void	exec_two(int *pfd, t_files fds, t_cmds *cmds, char **envp)
{
	safe_close(fds.fd1);
	safe_close(pfd[1]);
	safe_dup2(pfd[0], STDIN_FILENO);
	safe_dup2(fds.fd2, STDOUT_FILENO);
	safe_close(pfd[0]);
	safe_close(fds.fd2);
	execve(cmds->cmd2, cmds->fcmd2, envp);
}
