#include "../header/client.h"

size_t	malline(char *s, char c)
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

void	sp(char const *s, char *str, size_t i, size_t j)
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

void	ss(char const *s, char c, char **str)
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
			sp(s, str[stri], i, j);
			stri++;
		}
		if (s[i] == c)
			j = i + 1;
		i++;
	}
}

void	allfree(char **str)
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

char	**split_response(char const *s, char c)
{
	char	**str;
	size_t	ms;
	size_t	i;

	if (s == NULL)
		return (0);
	ms = malline((char *)s, c);
	str = (char **)malloc(sizeof(char *) * (ms + 1));
	if (str == NULL)
		return (0);
	ss(s, c, str);
	i = 0;
	while (i < ms)
	{
		if (str[i] == NULL)
		{
			allfree(str);
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
	str = split(s,c);
	while (str[i])
	{
		printf("%s\n",str[i]);
		i++;
	}
}*/