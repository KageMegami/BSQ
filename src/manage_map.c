/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** main
*/

#include "../include/my.h"

void	draw_square(char *map, square_t square, int width, int height)
{
	for (int i = 0; i < square.size; i++)
	{
		for (int j = 0; j < square.size; j++)
			map[(square.row + i) * (width + 1) + square.col + j] = 'x';
	}
	write(1, map, (width + 1) * height);
}

char	*read_map(int size, int fd, int *width, int *height)
{
	char *map = malloc(sizeof (char) * (size + 1));
	int ret = 0;
	int i = 0;

	ret = read(fd, map, size + 1);
	if (ret == -1)
		return (NULL);
	map[ret] = '\0';
	map[0] = 'M';
	while (*map != '\n' && *map != '\0')
		map += 1;
	if (*map != '\0')
		map += 1;
	while (map[*width] != '\n' && map[*width] != '\0')
		*width += 1;
	while (map[i] != '\0' && map[i + 1] != '\0') {
		*height += 1;
		i += *width + 1;
	}
	return (map);
}
