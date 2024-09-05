/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   process.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/05 14:58:57 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/02/23 14:06:32 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "./php.h"

void	*ft_thread_process(void *pil)
{
	t_philo		*philo;
	pthread_t	tid;

	philo = (t_philo *)pil;
	pthread_create(&tid, NULL, ft_monitor, (void *)philo);
	pthread_detach(tid);
	if (philo->id % 2 == 0)
		ft_sleep(philo->php->eattime / 2, philo);
	while (!ft_dead_chk(philo))
	{
		have_fork_l(philo);
		eatting(philo);
		if (philo->eatth == 0)
			exit(0);
		sleeping(philo);
		thinking(philo);
	}
	exit(0);
}

int	ft_dead_chk(t_philo *philo)
{
	int	ret;

	ret = 0;
	sem_wait(philo->php->dead);
	if (philo->dead != 0)
		ret = 1;
	sem_post(philo->php->dead);
	return (ret);
}

void	*ft_monitor(void *php)
{
	t_philo	*philo;
	int		eatth;

	philo = (t_philo *)php;
	eatth = 1;
	while (1 && eatth == 1)
	{
		usleep(800);
		eatth = 0;
		if (ft_mon_time(philo) >= 0)
		{
			ft_die_print(philo, philo->id - 1);
			exit (1);
		}
		eatth = ft_get_eatth(philo);
	}
	return (0);
}

void	ft_die_print(t_philo *philo, int i)
{
	sem_wait(philo->php->pri);
	printf("%d %d is die\n", \
		ft_time(philo->tv2, philo->php), i + 1);
}
