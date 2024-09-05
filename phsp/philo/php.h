/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   php.h											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/03 14:33:19 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/02/21 17:22:42 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef PHP_H
# define PHP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				eatth;
	int				eatting;
	int				dead;
	int				left;
	int				right;
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
	pthread_mutex_t	*fork;
	pthread_mutex_t	pri;
	pthread_mutex_t	eat;
	pthread_mutex_t	dead;
	pthread_mutex_t	timeset;
	pthread_t		*thread;
	pthread_t		tid;
	struct s_philo	*philos;
}	t_php;

void	ft_mutex_destroy(t_php *php);
t_php	*ft_php_init(int argc, char **argv);
t_philo	*ft_philo_init(int size, int argc, char **argv, t_php *php);
int		ft_check_php(t_php *php);
int		*ft_init_th(int pp, int setidx);
int		ft_philo_atoi(char *str);

int		ft_get_eatth(t_php *php, int i, int eatth);
void	have_fork_l(t_philo *philo);
void	have_fork_r(t_philo *philo);
void	eatting(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);

void	ft_put_str_fd(char *str, int fd);
void	ft_philo_fork_init(int i, t_php *php, t_philo *philo);
void	ft_die_print(t_php *php, int i);
void	ft_settime(t_philo *philo);
void	ft_timeinit(t_philo *philo);
int		ft_time(struct timeval ptv, t_php *php);
int		ft_mon_time(t_php *php, int i);

int		ft_chkforktime(t_philo philo);
void	ft_sleep(int time, t_philo *philo);
void	ft_philo_eat_check(t_philo *philo);
int		ft_atoi_check(int a, int b);

void	*ft_thread_process(void *pil);
int		ft_dead_chk(t_philo *philo);
void	*ft_monitor(void *ppt);
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

#endif
