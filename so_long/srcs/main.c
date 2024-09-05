/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: hojsong <hojsong@student.42seoul.k>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/12/19 14:21:59 by hojsong		   #+#	#+#			 */
/*   Updated: 2022/12/22 15:33:07 by hojsong		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../head/sl.h"

int	main(int argc, char **argv)
{
	t_game	*game;
	int		fd;

	game = malloc(sizeof(t_game));
	if (argc != 2)
		ft_error(1);
	fd = open(argv[1], O_RDONLY);
	game->map = ft_map_create(fd);
	close(fd);
	check(game);
	game->move = 0;
	mlxstart(game);
}

char	**ft_map_create(int fd)
{
	char	*line;
	char	*save_line;
	char	*gnl;
	char	**map;

	save_line = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		gnl = save_line;
		save_line = ft_strjoin(gnl, line);
		free(gnl);
		free(line);
	}
	map = ft_split(save_line, '\n');
	free(line);
	free(save_line);
	return (map);
}

void	ft_error(int i)
{
	write(2, "ERROR\n", 6);
	if (i == 2)
		write(2, "File Read Fail\n", 15);
	else if (i == 3)
		write(2, "Map Error\n", 10);
	exit(1);
}
