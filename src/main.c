/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** main
*/

#include "../include/my.h"

int	main(int ac, char **av)
{
	int fd = 0;
	struct stat stat_f;
	char *map;
	int width = 0;
	int height = 0;

	if (ac != 2)
		return (84);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (84);
	if (stat(av[1], &stat_f) == -1)
		return (84);
	map = read_map(stat_f.st_size, fd, &width, &height);
	close(fd);
	find_square(map, width, height);
	for (; map[0] != 'M'; map -= 1);
	free(map);
	return (0);
}
