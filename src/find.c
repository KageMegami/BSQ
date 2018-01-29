/*
** EPITECH PROJECT, 2017
** find square
** File description:
** BSQ
*/

#include "../include/my.h"

int	test_node(int i, int j, map_t sqrmap)
{
	if (sqrmap.map[j * (sqrmap.width + 1) + i] == 'o')
		return (1);
	return (0);
}

int	test_next(int j, int i, map_t sqrmap, int size)
{
	int b = 0;

	for (b = size - 1 ; b >= 0; b--)
	{
		if (test_node(i + b, j, sqrmap) == 1)
			return (b + 1);
	}
	return(0);
}

return_t	test_square(int i , int j, map_t sqrmap, int size)
{
	int a = 0;
	return_t ret;

	if (size == 0) {
		ret.j = 1;
		ret.i = (sqrmap.map[j * (sqrmap.width + 1) + i] \
			 == '.') ? 0 : 1;
		return (ret);
	}
	for (a = size - 1; a >=  0; a--) {
		ret.i = test_next(j + a, i, sqrmap, size);
		ret.j = a + 1;
		if (ret.i != 0)
			return (ret);
	}
	ret.i = 0;
	ret.j = 1;
	return (ret);
}

square_t	find_the_biggest_one\
(square_t square, map_t sqrmap, int cols, int rows)
{
	int i = 0;
	int j = 0;
	return_t ret;
	int jump = 0;

	while (j + square.size <= rows) {
		jump =  (square.size == 0) ? 1 : square.size;
		while (i + square.size <= cols && j + square.size <= rows) {
			ret = test_square(i, j, sqrmap, square.size);
			square.size += (ret.i == 0) ? 1 : 0;
			square.row = (ret.i == 0) ? j : square.row;
			square.col = (ret.i == 0) ? i : square.col;
			jump = (jump > ret.j) ? ret.j : jump;
			i += ret.i;
		}
		j += jump;
		i = 0;
	}
	return (square);
}

void	find_square(char *map, int width, int height)
{
	square_t square = {0, 0, 0};
	map_t sqrmap = {map, width, height};

	square = find_the_biggest_one(square, sqrmap, width, height);
	if (square.size != 0)
		square.size -= 1;
	draw_square(map, square, width, height);
}
