/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   php.h											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/03 14:33:19 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/02/23 14:16:19 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef PHP_H
# define PHP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/stat.h>

typedef struct s_philo
{
	int				id;
	int				eatth;
	int				eatting;
	int				dead;
	struct timeval	tv;
	struct timeval	tv2;
	struct s_php	*php;
}	t_philo;

typedef struct s_php
{
	int				pp;
	int				maxhp;
	int				eattime;
	int				sleeptime;
	int				death;
	sem_t			*fork;
	sem_t			*pri;
	sem_t			*eat;
	sem_t			*dead;
	sem_t			*timeset;
	pthread_t		tid;
	struct s_philo	*philos;
}	t_php;

void	ft_mutex_destroy(t_php *php);
t_php	*ft_php_init(int argc, char **argv);
t_philo	*ft_philo_init(int size, int argc, char **argv, t_php *php);
int		ft_check_php(t_php *php);
int		*ft_init_th(int pp, int setidx);
int		ft_philo_atoi(char *str);

int		ft_get_eatth(t_philo *philo);
void	have_fork_l(t_philo *philo);
void	have_fork_r(t_philo *philo);
void	eatting(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

void	ft_put_str_fd(char *str, int fd);
void	ft_philo_fork_init(int i, t_php *php, t_philo *philo);
void	ft_die_print(t_philo *philo, int i);
void	ft_settime(t_philo *philo);
void	ft_timeinit(t_philo *philo);
int		ft_time(struct timeval ptv, t_php *php);
int		ft_mon_time(t_philo *philo);

int		ft_chkforktime(t_philo philo);
void	ft_sleep(int time, t_philo *philo);
void	ft_philo_eat_check(t_philo *philo);
int		ft_atoi_check(int a, int b);

void	*ft_thread_process(void *pil);
int		ft_dead_chk(t_philo *philo);
void	*ft_monitor(void *philo);
void	ft_philo_all_dead(t_php *php);

void	ft_mutex_init(t_php *php);
void	ft_thread_init(t_php *php);
void	ft_thread_end(t_php *php);
void	ft_mutex_end(t_php *php);

char	**php_split(char **av);
void	allfree(char **result);
void	ft_save_split(char **re, char **av);
char	*ft_save_line(char *str, int i, int j);
int		php_sizeof_malloc(char **av);

int		ft_strlen(char *str);
char	*ft_str_join(char *str1, char *str2);
int		changer_size(int i);
char	*ft_int_str_change(int i);

#endif
