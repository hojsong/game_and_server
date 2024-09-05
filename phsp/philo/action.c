/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   action.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/06 22:54:19 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/02/17 14:01:43 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "./php.h"

void	have_fork_l(t_philo *philo)
{
	pthread_mutex_lock(&philo->php->fork[philo->left]);
	philo->eatting = 1;
	if (ft_dead_chk(philo) == 0)
	{
		pthread_mutex_lock(&philo->php->pri);
		printf("%d %d has taken a fork\n", \
				ft_time(philo->tv2, philo->php), philo->id);
		pthread_mutex_unlock(&philo->php->pri);
	}
	if (philo->id == philo->php->pp && philo->id % 2 == 1 && \
		philo->php->philos[0].eatting == 1)
		ft_philo_eat_check(philo);
	pthread_mutex_lock(&philo->php->fork[philo->right]);
	if (ft_dead_chk(philo) == 0)
	{
		pthread_mutex_lock(&philo->php->pri);
		printf("%d %d has taken a fork\n", \
				ft_time(philo->tv2, philo->php), philo->id);
		pthread_mutex_unlock(&philo->php->pri);
	}
	usleep(100);
}

void	eatting(t_philo *philo)
{
	pthread_mutex_lock(&philo->php->eat);
	if (philo->eatth > 0)
		philo->eatth--;
	pthread_mutex_unlock(&philo->php->eat);
	if (ft_dead_chk(philo) == 0)
	{
		pthread_mutex_lock(&philo->php->pri);
		printf("%d %d is eating\n", \
				ft_time(philo->tv2, philo->php), philo->id);
		pthread_mutex_unlock(&philo->php->pri);
		ft_settime(philo);
		ft_sleep(philo->php->eattime, philo);
	}
	pthread_mutex_unlock(&philo->php->fork[philo->id - 1]);
	if (philo->id == philo->php->pp)
		pthread_mutex_unlock(&philo->php->fork[0]);
	else
		pthread_mutex_unlock(&philo->php->fork[philo->id]);
	philo->eatting = 0;
}

void	sleeping(t_philo *philo)
{
	if (ft_dead_chk(philo) == 0)
	{
		pthread_mutex_lock(&philo->php->pri);
		printf("%d %d is sleeping\n", \
				ft_time(philo->tv2, philo->php), philo->id);
		pthread_mutex_unlock(&philo->php->pri);
		ft_sleep(philo->php->sleeptime, philo);
	}
}

void	thinking(t_philo *philo)
{
	if (ft_dead_chk(philo) == 0)
	{
		pthread_mutex_lock(&philo->php->pri);
		printf("%d %d is thinking\n", \
				ft_time(philo->tv2, philo->php), philo->id);
		pthread_mutex_unlock(&philo->php->pri);
	}
	usleep(100);
}
