/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   action.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/06 22:54:19 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/02/23 11:45:33 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "./php.h"

void	have_fork_l(t_philo *philo)
{
	sem_wait(philo->php->fork);
	philo->eatting = 1;
	if (ft_dead_chk(philo) == 0)
	{
		sem_wait(philo->php->pri);
		printf("%d %d has taken a fork\n", \
				ft_time(philo->tv2, philo->php), philo->id);
		sem_post(philo->php->pri);
	}
	sem_wait(philo->php->fork);
	if (ft_dead_chk(philo) == 0)
	{
		sem_wait(philo->php->pri);
		printf("%d %d has taken a fork\n", \
				ft_time(philo->tv2, philo->php), philo->id);
		sem_post(philo->php->pri);
	}
	usleep(100);
}

void	eatting(t_philo *philo)
{
	sem_wait(philo->php->eat);
	if (philo->eatth > 0)
		philo->eatth--;
	sem_post(philo->php->eat);
	if (ft_dead_chk(philo) == 0)
	{
		sem_wait(philo->php->pri);
		printf("%d %d is eating\n", \
				ft_time(philo->tv2, philo->php), philo->id);
		sem_post(philo->php->pri);
		ft_settime(philo);
		ft_sleep(philo->php->eattime, philo);
	}
	sem_post(philo->php->fork);
	sem_post(philo->php->fork);
	philo->eatting = 0;
}

void	sleeping(t_philo *philo)
{
	if (ft_dead_chk(philo) == 0)
	{
		sem_wait(philo->php->pri);
		printf("%d %d is sleeping\n", \
				ft_time(philo->tv2, philo->php), philo->id);
		sem_post(philo->php->pri);
		ft_sleep(philo->php->sleeptime, philo);
	}
}

void	thinking(t_philo *philo)
{
	if (ft_dead_chk(philo) == 0)
	{
		sem_wait(philo->php->pri);
		printf("%d %d is thinking\n", \
				ft_time(philo->tv2, philo->php), philo->id);
		sem_post(philo->php->pri);
	}
	usleep(100);
}
