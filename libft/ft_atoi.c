/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 23:35:10 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/16 18:42:32 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	skip_spaces(const char *str, int *i, int *sign)
{
	while (str[*i] == 32 || str[*i] == '\v' || str[*i] == '\t' || 
		str[*i] == '\f' || str[*i] == '\r' || str[*i] == '\n')
		(*i)++;
	if (str[*i] == '-')
	{
		*sign *= -1;
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
}

static int	check_errs(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == 32 || str[i] == '\v' || str[i] == '\t' || 
			str[i] == '\f' || str[i] == '\r' || str[i] == '\n')
			i++;
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i])
			return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long	n;
	int		i;
	int		sign;
	long	tmp;

	n = 0;
	i = 0;
	sign = 1;
	if (check_errs(str))
		err_func(NULL, NULL);
	skip_spaces(str, &i, &sign);
	if (ft_strncmp(str, "-2147483648", 12) == 0)
		return (-2147483648);
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = n * 10 + (str[i] - '0');
		if (n > tmp)
			err_func(NULL, NULL);
		n = tmp;
		i++;
	}
	if (str[i] == '+' || str[i] == '-' || n > INT_MAX || n < INT_MIN)
		err_func(NULL, NULL);
	return (sign * n);
}
