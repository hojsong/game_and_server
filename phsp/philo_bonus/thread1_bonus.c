/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   thread1.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/05 09:27:29 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/02/23 15:04:29 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "./php.h"
#include <signal.h>

void	ft_mutex_init(t_php *php)
{
	sem_unlink("fork");
	php->fork = sem_open("fork", O_CREAT, NULL, php->pp);
	sem_unlink("pri");
	php->pri = sem_open("pri", O_CREAT, NULL, 1);
	sem_unlink("dead");
	php->dead = sem_open("dead", O_CREAT, NULL, 1);
	sem_unlink("eat");
	php->eat = sem_open("eat", O_CREAT, NULL, 1);
	sem_unlink("timeset");
	php->timeset = sem_open("timeset", O_CREAT, NULL, 1);
}

void	ft_thread_init(t_php *php)
{
	int		i;
	int		status;
	pid_t	*pid;

	pid = malloc(sizeof(pid_t) * php->pp);
	i = -1;
	while (++i < php->pp)
	{
		pid[i] = fork();
		if (pid[i] == 0)
			ft_thread_process((void *)&php->philos[i]);
	}
	waitpid(-1, &status, 0);
	if (WEXITSTATUS(status) == 0)
	{
		i = -1;
		while (++i < php->pp)
			waitpid(pid[i], 0, 0);
	}
	i = -1;
	while (++i < php->pp)
		kill(pid[i], SIGKILL);
	free(pid);
}

void	ft_thread_end(t_php *php)
{
	int	i;

	i = 0;
	while (i++ < php->pp)
		sem_post(php->fork);
	free(php->philos);
	sem_close(php->fork);
	sem_unlink("fork");
	ft_mutex_destroy(php);
}

void	ft_mutex_destroy(t_php *php)
{
	sem_post(php->pri);
	sem_close(php->pri);
	sem_unlink("pri");
	sem_post(php->eat);
	sem_close(php->eat);
	sem_unlink("eat");
	sem_post(php->timeset);
	sem_close(php->timeset);
	sem_unlink("timeset");
	sem_post(php->dead);
	sem_close(php->dead);
	sem_unlink("dead");
}
