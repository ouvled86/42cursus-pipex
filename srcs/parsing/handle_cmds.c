/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:24:03 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/26 13:27:50 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

t_cmds	*check_cmds(char **envp, char *cmd1, char *cmd2)
{
	t_cmds	*ret;
	char	**path_list;
	int		i;

	ret = (t_cmds *)malloc(sizeof(t_cmds));
	i = 0;
	if (!ret)
		exit(9);
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4))
		i++;
	path_list = extract_paths(envp[i]);
	ret->fcmd1 = new_split(cmd1, ' ');
	ret->fcmd2 = new_split(cmd2, ' ');
	ret->cmd1 = find_path(path_list, ret->fcmd1[0]);
	ret->cmd2 = find_path(path_list, ret->fcmd2[0]);
	if (ret->cmd2 == NULL)
	{
		if (ret->cmd1)
			free(ret->cmd1);
		exit (14);
	}
	path_list = freemem(path_list);
	return (ret);
}

char	*find_path(char **pl, char *cmd)
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
	perror("pipex");
	return (NULL);
}
