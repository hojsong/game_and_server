/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   process.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/05 14:58:57 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/02/16 19:45:56 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "./php.h"

void	*ft_thread_process(void *pil)
{
	t_philo	*philo;

	philo = (t_philo *)pil;
	if (philo->id % 2 == 0)
		ft_sleep(philo->php->eattime / 2, philo);
	while (!ft_dead_chk(philo))
	{
		have_fork_l(philo);
		eatting(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (0);
}

int	ft_dead_chk(t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&philo->php->dead);
	if (philo->dead != 0)
		ret = 1;
	pthread_mutex_unlock(&philo->php->dead);
	return (ret);
}

void	*ft_monitor(void *ppt)
{
	t_php	*php;
	int		i;
	int		eatth;

	eatth = 1;
	php = (t_php *)ppt;
	while (1 && eatth == 1)
	{
		usleep(100);
		eatth = 0;
		i = 0;
		while (i < php->pp)
		{
			if (ft_mon_time(php, i) >= 0)
			{
				ft_philo_all_dead(php);
				ft_die_print(php, i);
				return (0);
			}
			eatth = ft_get_eatth(php, i, eatth);
			i++;
		}
	}
	ft_philo_all_dead(php);
	return (0);
}

void	ft_die_print(t_php *php, int i)
{
	pthread_mutex_lock(&php->pri);
	printf("%d %d is die\n", \
		ft_time(php->philos[i].tv2, php), i + 1);
	pthread_mutex_unlock(&php->pri);
}

void	ft_philo_all_dead(t_php *php)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&php->dead);
	if (php->pp == 1)
		pthread_mutex_unlock(&php->fork[0]);
	while (i < php->pp)
	{
		php->philos[i].dead = 1;
		i++;
	}
	pthread_mutex_unlock(&php->dead);
}
