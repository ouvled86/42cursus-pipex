/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:51:30 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/19 15:48:09 by ouel-bou         ###   ########.fr       */
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
}		t_cmds;

#endif

// ERROR CODES
// MALLOC ERR = 9
// ACCESS ERR = 14
// OPEN ERR = 33
// PIPE ERR = 43
// DUP ERR = 50