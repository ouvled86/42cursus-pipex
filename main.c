/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:51:19 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/19 16:01:45 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	safe_fork(void)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		return (-86);
	return (pid);
}

char	**extract_paths(char *s)
{
	char	*paths;
	char	**ret;

	paths = ft_substr(s, 5, ft_strlen(s));
	if (!paths)
		exit(9);
	ret = ft_split(paths, ':');
	if (!ret)
		exit(9);
	free (paths);
	return (ret);
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

void	check_args(int ac)
{
	if (ac != 5)
	{
		ft_printf("Program usage: ./pipex [file1] [cmd1] [cmd2] [file2]\n");
		exit (1);
	}
}

char	*exe_cmd(char **pl, char *cmd)
{
	int		i;
	char	*full_cmd;

	i = -1;
	if ((cmd[0] == '.' && cmd[1] == '/') || cmd[0] == '/')
	{
		if (access(cmd, X_OK) < 0)
			return (NULL);
		return (cmd);
	}
	else
	{
		while (pl[++i])
		{
			full_cmd = ft_strjoin(pl[i], cmd);
			if (access(full_cmd, X_OK) == 0)
				return (full_cmd);
			free(full_cmd);
			full_cmd = NULL;
		}
	}
	return (NULL);
}

t_cmds	*check_cmds(char **pl, char *cmd1, char *cmd2)
{
	t_cmds	*ret;

	ret->fcmd1 = ft_split2(cmd1, ' ');
	ret->fcmd2 = ft_split2(cmd2, ' ');
	ret->cmd1 = exe_cmd(pl, ret->fcmd1[0]);
	if (ret->cmd1 == NULL)
	{
		perror("pipex");
		exit (14);
	}
	ret->cmd2 = exe_cmd(pl, ret->fcmd2[0]);
	if (ret->cmd2 == NULL)
	{
		free(ret->cmd1);
		exit (14);
	}
	return (ret);
}

int	main(int ac, char **av, char **envp)
{
	t_cmds	*cmds;
	t_files	fds;
	int		pfd[2];
	int		pid1;
	int		pid2;
	char	**path_list;

	check_args(ac);
	path_list = extract_paths(envp[4]);
	cmds = check_cmds(path_list, av[2], av[3]);
	if (pipe(pfd) < 0)
		return (43);
	fds = safe_open(av[1], av[4]);
	pid1 = safe_fork();
	if (pid1 == 0)
	{
		close(fds.fd2);
		close(pfd[0]);
		dup2(fds.fd1, 0);
		dup2(pfd[1], 1);
		close(fds.fd1);
		close(pfd[1]);
		execve(cmds->cmd1, cmds->fcmd1, NULL);
		// 1st_cmd;
	}
	pid2 = safe_fork();
	if (pid2 == 0)
	{
		close(fds.fd1);
		close(pfd[1]);
		dup2(pfd[0], 0);
		dup2(fds.fd2, 1);
		close(pfd[0]);
		close(fds.fd2);
		execve(cmds->cmd2, cmds->fcmd2, NULL);
		// 2nd_cmd;
	}
	close (pfd[0]);
	close (pfd[1]);
	close (fds.fd1);
	close (fds.fd2);
	// call_fds;
	path_list = freemem(path_list);
	// free_cmds;
}
