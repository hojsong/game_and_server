/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   src3.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/07 02:03:52 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/02/17 18:09:46 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "./php.h"

int	ft_chkforktime(t_philo philo)
{
	if (philo.id == philo.php->pp)
	{
		if (ft_time(philo.tv, philo.php) < \
			ft_time(philo.php->philos[0].tv, philo.php))
			return (1);
		return (0);
	}
	if (ft_time(philo.tv, philo.php) < \
			ft_time(philo.php->philos[philo.id].tv, philo.php))
		return (1);
	return (0);
}

void	ft_sleep(int time, t_philo *philo)
{
	struct timeval	tv;
	int				sec;
	int				usec;

	sec = time / 1000;
	usec = time % 1000;
	gettimeofday(&tv, NULL);
	if (tv.tv_usec + (usec * 1000) >= 1000000)
		tv.tv_sec++;
	tv.tv_sec = tv.tv_sec + sec;
	tv.tv_usec = (tv.tv_usec + (usec * 1000)) % 1000000;
	while (ft_time(tv, philo->php) < 0)
		usleep(100);
}

int	ft_get_eatth(t_php *php, int i, int eatth)
{
	int	result;

	result = 0;
	pthread_mutex_lock(&php->eat);
	if (php->philos[i].eatth != 0 || eatth == 1)
		result = 1;
	pthread_mutex_unlock(&php->eat);
	return (result);
}

void	ft_philo_eat_check(t_philo *philo)
{
	if (philo->id == 1)
		ft_sleep(philo->php->maxhp + 10, philo);
	else
		ft_sleep(philo->php->eattime, philo);
}

int	ft_atoi_check(int a, int b)
{
	if (a > 214748364)
		return (2147483647);
	else if (a < -214748364)
		return (-2147483648);
	else if (a == 214748364 && b > 7)
		return (2147483647);
	else if (a == -214748364 && b < -8)
		return (-2147483648);
	else
		return (a * 10 + b);
}
