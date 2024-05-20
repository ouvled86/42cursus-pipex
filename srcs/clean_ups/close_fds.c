/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:16:06 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/20 13:17:35 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	close_all(int *pipe, t_files files)
{
	if (close(pipe[0]) < 0)
	{
		perror("pipex");
		exit(30);
	}
	if (close(pipe[1]) < 0)
	{
		perror("pipex");
		exit(30);
	}
	if (close(files.fd1) < 0)
	{
		perror("pipex");
		exit(30);
	}
	if (close(files.fd2) < 0)
	{
		perror("pipex");
		exit(30);
	}
}