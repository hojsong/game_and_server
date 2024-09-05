/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   src1.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/05 08:37:01 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/02/23 15:33:56 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "./php.h"

t_php	*ft_php_init(int argc, char **argv)
{
	t_php	*php;

	php = malloc(sizeof(t_php));
	if (php == NULL)
		return (0);
	php->pp = ft_philo_atoi(argv[0]);
	php->maxhp = ft_philo_atoi(argv[1]);
	php->eattime = ft_philo_atoi(argv[2]);
	php->sleeptime = ft_philo_atoi(argv[3]);
	if (ft_check_php(php) || (argc == 5 && ft_philo_atoi(argv[4]) == 0))
	{
		free(php);
		return (0);
	}
	php->philos = ft_philo_init(php->pp, argc, argv, php);
	if (php->philos == NULL)
	{
		free(php);
		return (0);
	}
	return (php);
}

t_philo	*ft_philo_init(int size, int argc, char **argv, t_php *php)
{
	t_philo	*philo;
	int		i;
	int		eat;

	eat = -1;
	if (argc == 5)
		eat = ft_philo_atoi(argv[4]);
	i = -1;
	philo = malloc(sizeof(t_philo) * size);
	if (philo == NULL)
		return (0);
	while (++i < size)
	{
		philo[i].id = i + 1;
		philo[i].eatth = eat;
		philo[i].eatting = 0;
		philo[i].php = php;
		philo[i].dead = 0;
		philo[i].left = i;
		philo[i].right = i + 1;
		ft_timeinit(&philo[i]);
		gettimeofday(&philo[i].tv2, NULL);
	}
	philo[i - 1].right = 0;
	return (philo);
}

int	ft_check_php(t_php *php)
{
	if (php->pp == 0)
		return (1);
	if (php->maxhp == 0)
		return (1);
	if (php->eattime == 0)
		return (1);
	if (php->sleeptime == 0)
		return (1);
	return (0);
}

int	*ft_init_th(int pp, int setidx)
{
	int	i;
	int	*result;

	result = malloc(sizeof(int) * pp);
	i = 0;
	while (i < pp)
	{
		result[i] = setidx;
		i++;
	}
	return (result);
}

int	ft_philo_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = ft_atoi_check(result, str[i] - '0');
		i++;
	}
	if (str[i])
		return (0);
	return (result);
}
