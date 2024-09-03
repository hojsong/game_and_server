/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojsong <hojsong@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:43:01 by hojsong           #+#    #+#             */
/*   Updated: 2022/12/19 18:56:27 by hojsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/get_next_line.h"

size_t	ft_malline(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

void	ft_sp(char const *s, char *str, size_t i, size_t j)
{
	size_t	idx;

	idx = 0;
	while (j < i + 1)
	{
		str[idx] = s[j];
		j++;
		idx++;
	}
	str[idx] = '\0';
}

void	ft_ss(char const *s, char c, char **str)
{
	size_t	i;
	size_t	stri;
	size_t	j;

	i = 0;
	stri = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			str[stri] = (char *)malloc(sizeof(char) * (i - j + 2));
			if (str[stri] == NULL)
				return ;
			ft_sp(s, str[stri], i, j);
			stri++;
		}
		if (s[i] == c)
			j = i + 1;
		i++;
	}
}

void	ft_allfree(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	ms;
	size_t	i;

	if (s == NULL)
		return (0);
	ms = ft_malline((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (ms + 1));
	if (str == NULL)
		return (0);
	ft_ss(s, c, str);
	i = 0;
	while (i < ms)
	{
		if (str[i] == NULL)
		{
			ft_allfree(str);
			return (0);
		}
		i++;
	}
	str[ms] = 0;
	return (str);
}
/*
#include <stdio.h>
int main()
{
	char s[20] = "asdfasdfasdfasdf";
	char c = 's';
	char **str;
	int	i;

	i = 0;
	str = ft_split(s,c);
	while (str[i])
	{
		printf("%s\n",str[i]);
		i++;
	}
}*/
