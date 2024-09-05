/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   src2.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/06 22:18:59 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/02/21 17:02:49 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "./php.h"

void	ft_put_str_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_timeinit(t_philo *philo)
{
	struct timeval	tv;
	int				sec;
	int				usec;

	gettimeofday(&tv, NULL);
	sec = philo->php->maxhp / 1000;
	usec = philo->php->maxhp % 1000;
	if (tv.tv_usec + (usec * 1000) >= 1000000)
		tv.tv_sec++;
	tv.tv_sec = tv.tv_sec + sec;
	tv.tv_usec = (tv.tv_usec + (usec * 1000)) % 1000000;
	philo->tv.tv_sec = tv.tv_sec;
	philo->tv.tv_usec = tv.tv_usec;
}

void	ft_settime(t_philo *philo)
{
	struct timeval	tv;
	int				sec;
	int				usec;

	pthread_mutex_lock(&philo->php->timeset);
	gettimeofday(&tv, NULL);
	sec = philo->php->maxhp / 1000;
	usec = philo->php->maxhp % 1000;
	if (tv.tv_usec + (usec * 1000) >= 1000000)
		tv.tv_sec++;
	philo->tv.tv_sec = tv.tv_sec + sec;
	philo->tv.tv_usec = (tv.tv_usec + (usec * 1000)) % 1000000;
	pthread_mutex_unlock(&philo->php->timeset);
}

int	ft_time(struct timeval ptv, t_php *php)
{
	struct timeval	tv;
	int				tvtotal;
	int				phtotal;

	pthread_mutex_lock(&php->timeset);
	gettimeofday(&tv, NULL);
	tvtotal = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	phtotal = (ptv.tv_sec * 1000) + (ptv.tv_usec / 1000);
	pthread_mutex_unlock(&php->timeset);
	return (tvtotal - phtotal);
}

int	ft_mon_time(t_php *php, int i)
{
	struct timeval	tv;
	int				tvtotal;
	int				phtotal;

	pthread_mutex_lock(&php->timeset);
	gettimeofday(&tv, NULL);
	tvtotal = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	phtotal = (php->philos[i].tv.tv_sec * 1000) + \
		(php->philos[i].tv.tv_usec / 1000);
	pthread_mutex_unlock(&php->timeset);
	return (tvtotal - phtotal);
}
