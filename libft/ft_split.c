/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:12:59 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/04/16 18:50:06 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check(char **str, char c)
{
	int	occurances;
	int	i;
	int	j;

	occurances = 0;
	j = 1;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (ft_isdigit_signed(str[j][i]))
				occurances++;
			else
				err_func(NULL, NULL);
			while (ft_isdigit_signed(str[j][i]))
				i++;
			if (str[j][i] == c)
				i++;
			if (!(ft_isdigit_signed(str[j][i])) && str[j][i])
				err_func(NULL, NULL);
		}
		j++;
	}
	return (occurances);
}

char	**freemem(char **res)
{
	int	i;

	i = 0;
	if (res)
	{
		while (res[i])
			free(res[i++]);
		free(res);
	}
	return (NULL);
}

static char	*extract(int *i, char *s, char c)
{
	int		ressize;
	int		tpos;
	int		j;
	char	*res;

	j = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	tpos = *i;
	while (s[*i] && s[*i] != c)
		(*i)++;
	ressize = *i - tpos;
	res = (char *)malloc((ressize + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (tpos + j < *i)
	{
		res[j] = s[tpos + j];
		j++;
	}
	res[j] = '\0';
	while (s[*i] && s[*i] == c)
		(*i)++;
	return (res);
}

void	extract_all(int *i, int k, char **s, char **r)
{
	static int	j;
	int			occs;

	occs = check(s, ' ');
	while (j < occs && s[k][*i])
	{
		r[j] = extract(i, s[k], ' ');
		if (r[j] == NULL)
			r = freemem(r);
		j++;
	}
}

char	**ft_split(char **s, char c)
{
	int		occurances;
	char	**result;
	int		i;
	int		j;
	int		k;

	j = 0;
	k = 1;
	if (!s || !*s)
		return (NULL);
	occurances = check(s, c);
	result = (char **)malloc ((occurances + 1) * sizeof (char *));
	if (!result)
		return (NULL);
	while (s[k])
	{
		i = 0;
		extract_all(&i, k, s, result);
		k++;
	}
	result[occurances] = NULL;
	return (result);
}
