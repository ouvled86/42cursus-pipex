/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:17:39 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/19 14:19:52 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check(char const *str, char c)
{
	int	occurances;
	int	i;

	occurances = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			occurances++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (occurances);
}

static char	*extract(int *i, char const *s, char c)
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
	return (res);
}

char	**ft_split2(char const *s, char c)
{
	int		i;
	int		j;
	int		occurances;
	char	**result;

	j = 0;
	if (!s)
		return (NULL);
	occurances = check(s, c);
	result = (char **)malloc ((occurances + 1) * sizeof (char *));
	if (!result)
		return (NULL);
	i = 0;
	while (j < occurances)
	{
		result[j] = extract(&i, s, c);
		if (result[j] == NULL)
			return (freemem(result));
		j++;
	}
	result[occurances] = NULL;
	return (result);
}
