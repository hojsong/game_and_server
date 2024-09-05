/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   src_bonus.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/02/21 18:41:14 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/02/23 13:33:46 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "./php.h"

char	*ft_str_join(char *str1, char *str2)
{
	char	*result;
	int		i;
	int		j;

	if (str1 == NULL | str2 == NULL)
		return (0);
	result = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (result == NULL)
		return (0);
	i = -1;
	while (str1[++i])
		result[i] = str1[i];
	j = -1;
	while (str2[++j])
		result[i + j] = str2[j];
	return (result);
}

char	*ft_int_str_change(int i)
{
	char	*result;
	int		n;
	int		x;

	n = changer_size(i);
	result = malloc(sizeof(char) * (n + 1));
	result[n] = '\0';
	if (i < 0)
		result[0] = '-';
	while (i)
	{
		n--;
		x = i % 10;
		if (x < 0)
			x *= -1;
		result[n] = x + '0';
	}
	return (result);
}

int	changer_size(int i)
{
	int	result;

	result = 0;
	if (i <= 0)
		result++;
	while (i)
	{
		i /= 10;
		result++;
	}
	return (result);
}

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
