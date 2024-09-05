/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   thread1.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/05 09:27:29 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/02/21 18:35:34 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "./php.h"

void	ft_mutex_init(t_php *php)
{
	int				i;

	i = 0;
	php->fork = malloc(sizeof(pthread_mutex_t) * php->pp);
	while (i < php->pp)
	{
		pthread_mutex_init(&php->fork[i], NULL);
		i++;
	}
	pthread_mutex_init(&php->pri, NULL);
	pthread_mutex_init(&php->dead, NULL);
	pthread_mutex_init(&php->eat, NULL);
	pthread_mutex_init(&php->timeset, NULL);
}

void	ft_thread_init(t_php *php)
{
	int			i;
	pthread_t	tid;

	php->thread = malloc(sizeof(pthread_t) * php->pp);
	i = -1;
	while (++i < php->pp)
	{
		pthread_create(&php->thread[i], NULL, \
				ft_thread_process, (void *)&php->philos[i]);
	}
	pthread_create(&tid, NULL, ft_monitor, (void *)php);
	pthread_detach(tid);
}

void	ft_thread_end(t_php *php)
{
	int	i;

	i = 0;
	while (i < php->pp)
	{
		pthread_mutex_unlock(&php->fork[i]);
		pthread_mutex_destroy(&php->fork[i]);
		pthread_join(php->thread[i], NULL);
		i++;
	}
	ft_mutex_destroy(php);
	free(php->thread);
	free(php->fork);
	free(php->philos);
}

void	ft_mutex_destroy(t_php *php)
{
	pthread_mutex_unlock(&php->pri);
	pthread_mutex_destroy(&php->pri);
	pthread_mutex_unlock(&php->eat);
	pthread_mutex_destroy(&php->eat);
	pthread_mutex_unlock(&php->timeset);
	pthread_mutex_destroy(&php->timeset);
	pthread_mutex_unlock(&php->dead);
	pthread_mutex_destroy(&php->dead);
}
