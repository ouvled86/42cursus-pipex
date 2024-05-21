/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:16:07 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/21 15:19:29 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

void	free_cmds(t_cmds *cmds)
{
	if (cmds->cmd1)
		free(cmds->cmd1);
	cmds->cmd1 = NULL;
	if (cmds->cmd2)
		free(cmds->cmd2);
	cmds->cmd2 = NULL;
	freemem(cmds->fcmd1);
	freemem(cmds->fcmd2);
	cmds = NULL;
}
