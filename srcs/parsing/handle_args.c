/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:18:42 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/20 13:23:02 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	check_args(int ac)
{
	if (ac != 5)
	{
		ft_printf("Program usage: ./pipex [file1] [cmd1] [cmd2] [file2]\n");
		exit (1);
	}
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
