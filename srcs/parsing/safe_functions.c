/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:20:34 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/21 14:09:58 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

int	safe_fork(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		return (-86);
	return (pid);
}

t_files	safe_open(char *f1, char *f2)
{
	t_files	ret;

	ret.fd1 = open(f1, O_RDONLY);
	if (ret.fd1 < 0)
	{
		perror("pipex");
		exit(33);
	}
	ret.fd2 = open(f2, O_CREAT | O_WRONLY);
	if (ret.fd2 < 0)
	{
		close(ret.fd1);
		perror("pipex");
		exit(33);
	}
	return (ret);
}

void	safe_close(int fd)
{
	if (close(fd) < 0)
	{
		perror("pipex");
		exit(30);
	}
}

void	safe_dup2(int newfd, int oldfd)
{
	if (dup2(newfd, oldfd) < 0)
	{
		perror("pipex");
		exit(50);
	}
}
