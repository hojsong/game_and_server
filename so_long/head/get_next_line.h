/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.h									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/11/17 17:26:48 by hojsong		   #+#	#+#			 */
/*   Updated: 2022/12/19 14:58:10 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*make_line(int fd, char *buf, char *back);
char	*make_back(char *c);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *w1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, size_t start, size_t len);
char	*ft_strdup(char *src);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	**ft_split(char const *str, char c);

#endif
