#include "../header/ft_ping.h"

extern struct addrinfo *g_res;
extern struct timeval total_time, program_start;
extern unsigned long long total, suc;
extern int   closefd, ac;
extern char  **av;
extern double *save_times;

size_t	ft_strlen(const char *str){
	size_t i;

	i = 0;
	while(str && str[i])
		i++;
	return i;
}

void	*ft_memset(void *b, int c, size_t len){
	size_t			i;
	unsigned char	*st;

	i = 0;
	st = (unsigned char *)b;
	while (i < len)
		st[i++] = (unsigned char)c;
	return (st);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_isalnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	if (c >= 97 && c <= 122)
		return (1);
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}
