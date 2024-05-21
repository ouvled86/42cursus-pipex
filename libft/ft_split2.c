/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ouel-bou <ouel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:17:39 by ouel-bou          #+#    #+#             */
/*   Updated: 2024/05/21 12:11:57 by ouel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	check(char const *str, char c)
{
	int	occurances;
	int	i;
	int	qc;
	int	f;

	occurances = 0;
	qc = 0;
	f = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			occurances++;
		if (str[i] == 39 || str[i] == 34)
			qc++;
		while (str[i] && str[i] != c)
			i++;
	}
	i = qc / 2;
	return (occurances - i);
}

static char	*extract(int *i, char const *s, char c)
{
	int		ressize;
	int		tpos;
	int		j;
	int		f;
	char	*res;

	j = 0;
	f = 0;
	while (s[*i] && s[*i] == c)
		(*i)++;
	if (s[*i] == 39)
	{
		f = 1;
		(*i)++;
	}
	tpos = *i;
	if (f == 0)
	{
		while (s[*i] && s[*i] != c)
			(*i)++;
	}
	if (f == 1)
	{
		while (s[*i] && s[*i] != 39)
			(*i)++;
		ft_printf("i  is: %d\n", *i);
		f = 0;
	}
	ft_printf("%d\n", *i);
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
	ft_printf("%s\n", res);
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
	ft_printf("occurs: %d\n", occurances);
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
