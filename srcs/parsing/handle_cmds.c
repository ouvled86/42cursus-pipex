/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:24:03 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/20 13:55:05 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

t_cmds	*check_cmds(char **envp, char *cmd1, char *cmd2)
{
	t_cmds	*ret;
	char	**path_list;

	ret = (t_cmds *)malloc(sizeof(t_cmds));
	if (!ret)
		exit(9);
	path_list = extract_paths(envp[2]);
	ret->fcmd1 = ft_split2(cmd1, ' ');
	ret->fcmd2 = ft_split2(cmd2, ' ');
	ret->cmd1 = find_path(path_list, ret->fcmd1[0]);
	if (ret->cmd1 == NULL)
	{
		perror("pipex");
		exit (14);
	}
	ret->cmd2 = find_path(path_list, ret->fcmd2[0]);
	if (ret->cmd2 == NULL)
	{
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
	return (NULL);
}
