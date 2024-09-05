/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/18 17:08:46 by hojsong		   #+#	#+#			 */
/*   Updated: 2022/12/19 18:56:38 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../head/get_next_line.h"

size_t	ft_strlen(char *src)
{
	size_t	len;

	len = 0;
	if (src == NULL)
		return (0);
	while (src[len])
		len++;
	return (len);
}

char	*make_line(int fd, char *buf, char *back)
{
	int		cnt;
	char	*curptr;

	while (1)
	{
		cnt = read(fd, buf, BUFFER_SIZE);
		if (cnt == -1)
			return (NULL);
		else if (cnt == 0)
			break ;
		buf[cnt] = '\0';
		if (!back)
			back = ft_strdup("");
		curptr = back;
		back = ft_strjoin(curptr, buf);
		if (!back)
			return (0);
		free(curptr);
		curptr = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (back);
}

char	*make_back(char *c)
{
	int		i;
	char	*rlt;

	i = 0;
	while (c[i] != '\0' && c[i] != '\n')
		i++;
	if (c[i] == '\0')
		return (0);
	rlt = ft_substr(c, i + 1, ft_strlen(c) - i);
	if (!rlt)
		return (0);
	if (rlt[0] == '\0')
	{
		free(rlt);
		rlt = NULL;
		return (0);
	}
	c[i + 1] = '\0';
	return (rlt);
}

char	*get_next_line(int fd)
{
	static char	*back;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	line = make_line(fd, buf, back);
	free(buf);
	buf = NULL;
	if (!line)
	{
		free(back);
		back = NULL;
		return (0);
	}
	back = make_back(line);
	return (line);
}
