/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:51:19 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/21 15:16:38 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_cmds	*cmds;
	t_files	fds;
	int		pfd[2];
	pid_t	pid1;
	pid_t	pid2;

	check_args(ac);
	cmds = check_cmds(envp, av[2], av[3]);
	if (pipe(pfd) < 0)
		return (43);
	fds = safe_open(av[1], av[4]);
	pid1 = safe_fork();
	if (pid1 == 0)
		exec_one(pfd, fds, cmds);
	pid2 = safe_fork();
	if (pid2 == 0)
		exec_two(pfd, fds, cmds);
	close_all(pfd, fds);
	free_cmds(cmds);
	free(cmds);
}
