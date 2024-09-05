/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/03 14:44:02 by hojsong		   #+#	#+#			 */
/*   Updated: 2023/02/23 15:34:54 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "./php.h"

int	main(int argc, char **argv)
{
	char		**reset;
	t_php		*php;

	argc = php_sizeof_malloc(argv);
	reset = php_split(argv);
	if (reset == NULL)
		ft_put_str_fd("Error : Argument Error\n", 2);
	else
	{
		php = ft_php_init(argc, reset);
		allfree(reset);
		if (php == NULL)
			ft_put_str_fd("Error : Argument Error\n", 2);
		else
		{
			ft_mutex_init(php);
			ft_thread_init(php);
			ft_thread_end(php);
			free(php);
		}
	}
	return (0);
}
