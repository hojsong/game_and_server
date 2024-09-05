/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   src4.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/02/21 13:28:15 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/02/23 15:11:05 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "php.h"

char	**php_split(char **av)
{
	char	**result;
	int		size;
	int		i;

	size = php_sizeof_malloc(av);
	if (size < 4 || size > 5)
		return (0);
	result = malloc(sizeof(char *) * (size + 1));
	if (result == NULL)
		return (0);
	ft_save_split(result, av);
	i = -1;
	while (++i < size)
	{
		if (result[i] == NULL)
		{
			allfree(result);
			return (0);
		}
		i++;
	}
	return (result);
}

void	allfree(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
}

void	ft_save_split(char **re, char **av)
{
	int	i;
	int	i2;
	int	ri;
	int	j;

	ri = 0;
	i = 0;
	while (av[++i])
	{
		j = 0;
		i2 = -1;
		while (av[i][++i2])
		{
			if (av[i][i2] == ' ')
				j = i2 + 1;
			else if (av[i][i2] != ' ' && (av[i][i2 + 1] == ' ' || \
						av[i][i2 + 1] == '\0'))
			{
				re[ri] = ft_save_line(av[i], i2, j);
				if (re[ri] == NULL)
					return ;
				ri++;
			}
		}
	}
}

char	*ft_save_line(char *str, int i, int j)
{
	char	*result;
	int		idx;

	idx = 0;
	result = malloc(sizeof(char) * (i - j + 2));
	if (result == NULL)
		return (0);
	while (j + idx <= i)
	{
		result[idx] = str[j + idx];
		idx++;
	}
	result[idx] = '\0';
	return (result);
}

int	php_sizeof_malloc(char **av)
{
	int	result;
	int	i;
	int	i2;

	result = 0;
	i = 1;
	while (av[i])
	{
		i2 = 0;
		while (av[i][i2])
		{
			if (av[i][i2] != ' ' && (av[i][i2 + 1] == ' ' || \
						av[i][i2 + 1] == '\0'))
				result++;
			i2++;
		}
		i++;
	}
	return (result);
}
