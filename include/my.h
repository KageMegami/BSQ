/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** BSQ
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef STRUCT_H_
#define STRUCT_H_
typedef struct square_s
{
	int col;
	int row;
	int size;
} square_t;

typedef struct map_s
{
	char *map;
	int width;
	int height;
} map_t;

typedef struct return_s
{
	int i;
	int j;
} return_t;

#endif /*STRUCT_H_*/

void	find_square(char *map, int width, int height);
void	draw_square(char *map, square_t square, int width, int height);
char	*read_map(int size, int fd, int *width, int *height);
