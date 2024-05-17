/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:51:19 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/17 15:03:15 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	main(int ac, char **av)
{
	int	pid1;
	int	pid2;

	if (ac != 4)
	{
		ft_printf("Program usage: ./pipex [file1] [cmd1] [cmd2] [file2]");
		return (1);
	}
	
}